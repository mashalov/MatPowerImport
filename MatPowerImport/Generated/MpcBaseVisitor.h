
// Generated from D:\source\repos\MatPowerImport\MatPowerImport\Mpc.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "MpcVisitor.h"


/**
 * This class provides an empty implementation of MpcVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MpcBaseVisitor : public MpcVisitor {
public:

  virtual antlrcpp::Any visitInput(MpcParser::InputContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMpcvars(MpcParser::MpcvarsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBus(MpcParser::BusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGen(MpcParser::GenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBranch(MpcParser::BranchContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVersion(MpcParser::VersionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGencost(MpcParser::GencostContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBaseMVA(MpcParser::BaseMVAContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBusname(MpcParser::BusnameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstvalue(MpcParser::ConstvalueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction(MpcParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstlist(MpcParser::ConstlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitValmatrixrow(MpcParser::ValmatrixrowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitValmatrix(MpcParser::ValmatrixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitValarray(MpcParser::ValarrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCellarray(MpcParser::CellarrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRealconst(MpcParser::RealconstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(MpcParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArray(MpcParser::ArrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCell(MpcParser::CellContext *ctx) override {
    return visitChildren(ctx);
  }


};

