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
        logger_.Log(LogMessageTypes::Info, "MATPOWER caseformat is imported from {}", path.string());

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


    ShowDimensions();

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
        mcase << "];" << std::endl << std::endl;
    };

    mcase << fmt::format("function mpc = {}", path.filename().replace_extension().string()) << std::endl;
    if (!comment_.empty())
    {
        STRINGLIST comments;
        stringutils::split(comment_, comments, "\n");
        for(const auto& comment : comments)
            mcase << "% " << comment << std::endl;
    }
    mcase << "mpc.version = '2';" << std::endl;
    mcase << fmt::format("mpc.baseMVA = {};", BaseMVA_) << std::endl;
    mcase << "mpc.bus = [" << std::endl;
    mcase << fmt::format("%{:>9} {:>3} {:>12} {:>12} {:>12} {:>12} {:>7} {:>12} {:>12} {:>12} {:>7} {:>12} {:>12}",
        "Id",
        "Tpe",
        "Pd", "Qd",
        "Gs", "Bs",
        "area",
        "Vm", "Va",
        "baseKv",
        "zone",
        "Vmax", "Vmin" )<< std::endl;
    for (const auto& bus : buses)
    {
        mcase << fmt::format("{:10} {:3} {:12g} {:12g} {:12g} {:12g} {:7} {:12g} {:12g} {:12g} {:7} {:12g} {:12g};",
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

    mcase << "mpc.branch = [" << std::endl;
    mcase << fmt::format("%{:>9} {:>10} {:>12} {:>12} {:>12} {:>12} {:>12} {:>12} {:>12} {:>12} {:>3} {:>12} {:>12}",
        "fbus",
        "tbus",
        "r", "x", "b",
        "rateA", "rateB", "rateC",
        "ratio", "angle", 
        "sta",
        "angmin", "angmax") << std::endl;
    for (const auto& branch : branches)
    {
        mcase << fmt::format("{:10} {:10} {:12g} {:12g} {:12g} {:12g} {:12g} {:12g} {:12g} {:12g} {:3} {:12g} {:12g};",
            branch.IdHead,
            branch.IdTail,
            branch.r,
            branch.x,
            branch.b,
            branch.rateA,
            branch.rateB,
            branch.rateC,
            branch.ktr,
            branch.kti,
            branch.State,
            branch.Dmin,
            branch.Dmax) << std::endl;
    }
    (closearray)();

    mcase << "mpc.gen = [" << std::endl;
    mcase << fmt::format("%{:>9} {:>12} {:>12} {:>12} {:>12} {:>12} {:>12} {:>5} {:>12} {:>12} {:>12} {:>12} {:>12} {:>12} {:>12} {:>12} {:>12} {:>12} {:>12} {:>12} {:>12}",
        "bus",
        "Pg", "Qg",
        "Qmax", "Qmin",
        "Vg",
        "mBase",
        "state",
        "Pmax", "Pmin",
        "Pc1", "Pc2",
        "Qc1min", "Qc1max",
        "Qc2min", "Qc2max",
        "ramp", "ramp_10", "ramp_30",
        "ramp_Q", "APF") << std::endl;
    for (const auto& gen : generators)
    {
        mcase << fmt::format("{:10} {:12g} {:12g} {:12g} {:12g} {:12g} {:12g} {:5} {:12g} {:12g} {:12g} {:12g} {:12g} {:12g} {:12g} {:12g} {:12g} {:12g} {:12g} {:12g} {:12g};",
            gen.Id,
            gen.Pg,
            gen.Qg,
            gen.Qmax,
            gen.Qmin,
            gen.Vg,
            gen.Sbase,
            gen.State,
            gen.Pmax,
            gen.Pmin,
            gen.Pc1,
            gen.Pc2,
            gen.Qc1min,
            gen.Qc1max,
            gen.Qc2min,
            gen.Qc2max,
            gen.ramp,
            gen.ramp10,
            gen.ramp30,
            gen.rampQ,
            gen.APF) << std::endl;
    }
    (closearray)();

    ShowDimensions();
    if(!Silent_)
        logger_.Log(LogMessageTypes::Info, "MATPOWER model is exported to {}", path.string());
}

void MatPowerCase::ShowDimensions()
{
    constexpr const char* ReportMask = "{:<15} {:>15}";
    if (!Silent_)
    {
        logger_.Log(LogMessageTypes::Info, ReportMask, "Base MVA", BaseMVA_);
        logger_.Log(LogMessageTypes::Info, ReportMask, "Buses", buses.size());
        logger_.Log(LogMessageTypes::Info, ReportMask, "Branches", branches.size());
        logger_.Log(LogMessageTypes::Info, ReportMask, "Generators", generators.size());
        logger_.Log(LogMessageTypes::Info, ReportMask, "Areas", areas.size());
    }
}