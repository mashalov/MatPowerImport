
// Generated from C:\Users\Bug9\source\repos\MatPowerImport\MatPowerImport\Mpc.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "MpcParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by MpcParser.
 */
class  MpcVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MpcParser.
   */
    virtual antlrcpp::Any visitInput(MpcParser::InputContext *context) = 0;

    virtual antlrcpp::Any visitMpcvars(MpcParser::MpcvarsContext *context) = 0;

    virtual antlrcpp::Any visitBus(MpcParser::BusContext *context) = 0;

    virtual antlrcpp::Any visitGen(MpcParser::GenContext *context) = 0;

    virtual antlrcpp::Any visitBranch(MpcParser::BranchContext *context) = 0;

    virtual antlrcpp::Any visitVersion(MpcParser::VersionContext *context) = 0;

    virtual antlrcpp::Any visitGencost(MpcParser::GencostContext *context) = 0;

    virtual antlrcpp::Any visitBaseMVA(MpcParser::BaseMVAContext *context) = 0;

    virtual antlrcpp::Any visitConstvalue(MpcParser::ConstvalueContext *context) = 0;

    virtual antlrcpp::Any visitFunction(MpcParser::FunctionContext *context) = 0;

    virtual antlrcpp::Any visitConstlist(MpcParser::ConstlistContext *context) = 0;

    virtual antlrcpp::Any visitValmatrixrow(MpcParser::ValmatrixrowContext *context) = 0;

    virtual antlrcpp::Any visitValmatrix(MpcParser::ValmatrixContext *context) = 0;

    virtual antlrcpp::Any visitValarray(MpcParser::ValarrayContext *context) = 0;

    virtual antlrcpp::Any visitRealconst(MpcParser::RealconstContext *context) = 0;

    virtual antlrcpp::Any visitVariable(MpcParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitArray(MpcParser::ArrayContext *context) = 0;


};

