#include <fstream>
#include <set>
#include "MatPowerData.h"
#undef max
#include "AntlrASTVisitor.h"

MatPowerCase::MatPowerCase(CPlainLogger& logger) : 
    logger_(logger),
    busnames(buses)
{

}

void MatPowerCase::Import(const std::filesystem::path& path)
{
	std::fstream mcase(path);
	if (!mcase.is_open())
		throw CExceptionGLE(cszFileCannotBeOpened, path.string());
    mcase.seekg(0, std::ios::end);
    size_t size = mcase.tellg();
    std::string Source(size, ' ');
    mcase.seekg(0);
    mcase.read(&Source[0], size);

    antlr4::ANTLRInputStream input(Source);
    MpcLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    MpcParser parser(&tokens);
    //auto errorListener = std::make_unique<AntlrASTErrorListener>(pTree.get(), input.toString());
    // ставим обработчики ошибок в лексер и парсер
    //parser.removeErrorListeners();
    //parser.addErrorListener(errorListener.get());
    //lexer.removeErrorListeners();
    //lexer.addErrorListener(errorListener.get());
    antlr4::tree::ParseTree* tree = parser.input();
    MpcParserVisitor visitor(*this);
    visitor.visit(tree);

    if(!Silent_)
        logger_.Log(LogMessageTypes::Info, "MatPower caseformat is imported from {}", path.string());

    std::set<long> Areas;
    for (const auto& bus : buses)
    {
        if (bus.AreaId > 0)
            Areas.insert(bus.AreaId);

        if (bus.Unom <= 0)
            logger_.Log(LogMessageTypes::Error, "Bus {} has wrong baseKv {}", bus.Id, bus.Unom);
    }

    areas.reserve(Areas.size());
    for (const auto& area : Areas)
        areas.push_back({ area });

    constexpr const char* ReportMask = "{:<15} {:>15}";

    if (!Silent_)
    {
        logger_.Log(LogMessageTypes::Info, ReportMask, "Base MVA", BaseMVA_);
        logger_.Log(LogMessageTypes::Info, ReportMask, "Buses", buses.size());
        logger_.Log(LogMessageTypes::Info, ReportMask, "Branches", branches.size());
        logger_.Log(LogMessageTypes::Info, ReportMask, "Generators", generators.size());
        logger_.Log(LogMessageTypes::Info, ReportMask, "Areas", areas.size());
    }

    if (BaseMVA_ <= 0)
        throw CException("BaseMVA {} seems wrong", BaseMVA_);
}

void MatPowerCase::Export(const std::filesystem::path& path)
{
    std::fstream mcase;
    mcase.open(path, std::fstream::out);
    if (!mcase.is_open())
        throw CExceptionGLE(cszFileCannotBeOpened, path.string());

    const auto closearray = [&mcase]()
    {
        mcase << "];" << std::endl;
    };

    mcase << fmt::format("function mpc = {};", path.filename().replace_extension().string()) << std::endl;
    mcase << "mpc.version='2';" << std::endl;
    mcase << fmt::format("mpc.baseMVA={};", BaseMVA_) << std::endl;
    //" % bus_i	type	Pd	Qd	Gs	Bs	area	Vm	Va	baseKV	zone	Vmax	Vmin"

    mcase << "mpc.bus = [" << std::endl;
    mcase << fmt::format("%{:>9} {:>3} {:>15} {:>15} {:>15} {:>15} {:>7} {:>15} {:>15} {:>15} {:>7} {:>15} {:>15}",
        "Id",
        "Tpe",
        "Pd",
        "Qd",
        "Gs",
        "Bs",
        "area",
        "Vm",
        "Va",
        "baseKv",
        "zone",
        "Vmax",
        "Vmin" )<< std::endl;
    for (const auto& bus : buses)
    {
        mcase << fmt::format("{:10} {:3} {:15g} {:15g} {:15g} {:15g} {:7} {:15g} {:15g} {:15g} {:7} {:15g} {:15g};",
            bus.Id,
            bus.Type,
            bus.Pn,
            bus.Qn,
            bus.Gsh,
            bus.Bsh,
            bus.AreaId,
            bus.V,
            bus.Delta,
            bus.Unom,
            bus.LossAreaId,
            bus.Vmax,
            bus.Vmin) << std::endl;
    }
    (closearray)();
    
}