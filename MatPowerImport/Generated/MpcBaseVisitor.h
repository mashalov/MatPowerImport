
// Generated from C:/Users/Bug9/source/repos/MatPowerImport/MatPowerImport/Mpc.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "MpcVisitor.h"


/**
 * This class provides an empty implementation of MpcVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MpcBaseVisitor : public MpcVisitor {
public:

  virtual std::any visitInput(MpcParser::InputContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMpcvars(MpcParser::MpcvarsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBus(MpcParser::BusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGen(MpcParser::GenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBranch(MpcParser::BranchContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVersion(MpcParser::VersionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGencost(MpcParser::GencostContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBaseMVA(MpcParser::BaseMVAContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBusname(MpcParser::BusnameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstvalue(MpcParser::ConstvalueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction(MpcParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstlist(MpcParser::ConstlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValmatrixrow(MpcParser::ValmatrixrowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValmatrix(MpcParser::ValmatrixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValarray(MpcParser::ValarrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCellarray(MpcParser::CellarrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRealconst(MpcParser::RealconstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariable(MpcParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray(MpcParser::ArrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCell(MpcParser::CellContext *ctx) override {
    return visitChildren(ctx);
  }


};

