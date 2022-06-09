#pragma once
#include "AntlrASTErrorListener.h"
#include "MatPowerData.h"

class MpcParserVisitor : public MpcBaseVisitor
{
    MatPowerCase& mpcase_;
    std::map<antlr4::tree::ParseTree*, SequentialVectorBase*> Parents;
public:
    MpcParserVisitor(MatPowerCase& mpcase) : mpcase_(mpcase)
    {
    }

    SequentialVectorBase* GetParent(antlr4::tree::ParseTree* Tree)
    {
        auto Parent{ Tree->parent };
        while (Parent)
        {
            if (auto Pit{ Parents.find(Parent) }; Pit != Parents.end())
                return Pit->second;
            else
                Parent = Parent->parent;
        }
        return nullptr;
    }


    std::string ParserError(antlr4::ParserRuleContext* ctx, std::string_view error, std::string_view offending)
    {
        return AntlrASTErrorListener::ParserError(error,
            ctx->start->getInputStream()->toString(),
            offending,
            ctx->start->getLine(),
            ctx->start->getCharPositionInLine());
    }

    antlrcpp::Any visitInput(MpcParser::InputContext* ctx) override
    {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitBus(MpcParser::BusContext* ctx) override
    {
        Parents.insert({ ctx, &mpcase_.buses });
        return visitChildren(ctx);
    }

    antlrcpp::Any visitGen(MpcParser::GenContext* ctx) override
    {
        Parents.insert({ ctx, &mpcase_.generators});
        return visitChildren(ctx);
    }

    antlrcpp::Any visitBranch(MpcParser::BranchContext* ctx) override
    {
        Parents.insert({ ctx, &mpcase_.branches });
        return visitChildren(ctx);
    }

    antlrcpp::Any visitBaseMVA(MpcParser::BaseMVAContext* ctx) override
    {
        mpcase_.BaseMVA_ = std::stod(ctx->children[4]->getText());
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitValmatrixrow(MpcParser::ValmatrixrowContext* ctx) override {
        if (auto parent{ GetParent(ctx) }; parent)
            parent->SetSize(ctx->children.size() / 2);
        return visitChildren(ctx);
    }

    antlrcpp::Any visitConstlist(MpcParser::ConstlistContext* ctx) override {
        if (auto parent{ GetParent(ctx) }; parent)
            parent->New();
        return visitChildren(ctx);
    }

    antlrcpp::Any visitConstvalue(MpcParser::ConstvalueContext* ctx) override {
        if (auto parent{ GetParent(ctx) }; parent)
        {
            if (ctx->getRuleIndex() == MpcParser::STRING)
                parent->SetValue(ctx->children[1]->getText());
            else
                parent->SetValue(ctx->getText());
        }
        
        return visitChildren(ctx);
    }

    antlrcpp::Any visitBusname(MpcParser::BusnameContext* ctx) override 
    {
        Parents.insert({ ctx, &mpcase_.busnames });
        return visitChildren(ctx);
    }

    ~MpcParserVisitor() = default;
};

