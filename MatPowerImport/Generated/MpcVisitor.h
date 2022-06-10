
// Generated from C:/Users/Bug9/source/repos/MatPowerImport/MatPowerImport/Mpc.g4 by ANTLR 4.10.1

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
    virtual std::any visitInput(MpcParser::InputContext *context) = 0;

    virtual std::any visitMpcvars(MpcParser::MpcvarsContext *context) = 0;

    virtual std::any visitBus(MpcParser::BusContext *context) = 0;

    virtual std::any visitGen(MpcParser::GenContext *context) = 0;

    virtual std::any visitBranch(MpcParser::BranchContext *context) = 0;

    virtual std::any visitVersion(MpcParser::VersionContext *context) = 0;

    virtual std::any visitGencost(MpcParser::GencostContext *context) = 0;

    virtual std::any visitBaseMVA(MpcParser::BaseMVAContext *context) = 0;

    virtual std::any visitBusname(MpcParser::BusnameContext *context) = 0;

    virtual std::any visitConstvalue(MpcParser::ConstvalueContext *context) = 0;

    virtual std::any visitFunction(MpcParser::FunctionContext *context) = 0;

    virtual std::any visitConstlist(MpcParser::ConstlistContext *context) = 0;

    virtual std::any visitValmatrixrow(MpcParser::ValmatrixrowContext *context) = 0;

    virtual std::any visitValmatrix(MpcParser::ValmatrixContext *context) = 0;

    virtual std::any visitValarray(MpcParser::ValarrayContext *context) = 0;

    virtual std::any visitCellarray(MpcParser::CellarrayContext *context) = 0;

    virtual std::any visitRealconst(MpcParser::RealconstContext *context) = 0;

    virtual std::any visitVariable(MpcParser::VariableContext *context) = 0;

    virtual std::any visitArray(MpcParser::ArrayContext *context) = 0;

    virtual std::any visitCell(MpcParser::CellContext *context) = 0;


};

