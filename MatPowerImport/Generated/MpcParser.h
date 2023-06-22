
// Generated from D:\source\repos\MatPowerImport\MatPowerImport\Mpc.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  MpcParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    FLOAT = 8, DOT = 9, LBS = 10, RBS = 11, LCB = 12, RCB = 13, LET = 14, 
    FUNCTION = 15, INTEGER = 16, SQUOTE = 17, INF = 18, STRING = 19, MPC = 20, 
    VARIABLE = 21, LINE_COMMENT = 22, NEWLINE = 23, COMMA = 24, WSK = 25, 
    WS = 26, SEMI = 27
  };

  enum {
    RuleInput = 0, RuleMpcvars = 1, RuleMpcvar = 2, RuleConstvalue = 3, 
    RuleMpcfunction = 4, RuleVallist = 5, RuleValmatrixrow = 6, RuleValmatrix = 7, 
    RuleValarray = 8, RuleCellarray = 9, RuleExpression = 10
  };

  explicit MpcParser(antlr4::TokenStream *input);

  MpcParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~MpcParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class InputContext;
  class MpcvarsContext;
  class MpcvarContext;
  class ConstvalueContext;
  class MpcfunctionContext;
  class VallistContext;
  class ValmatrixrowContext;
  class ValmatrixContext;
  class ValarrayContext;
  class CellarrayContext;
  class ExpressionContext; 

  class  InputContext : public antlr4::ParserRuleContext {
  public:
    InputContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    MpcfunctionContext *mpcfunction();
    std::vector<MpcvarsContext *> mpcvars();
    MpcvarsContext* mpcvars(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InputContext* input();

  class  MpcvarsContext : public antlr4::ParserRuleContext {
  public:
    MpcvarsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MpcvarContext *mpcvar();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MpcvarsContext* mpcvars();

  class  MpcvarContext : public antlr4::ParserRuleContext {
  public:
    MpcvarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    MpcvarContext() = default;
    void copyFrom(MpcvarContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BusContext : public MpcvarContext {
  public:
    BusContext(MpcvarContext *ctx);

    antlr4::tree::TerminalNode *MPC();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *LET();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMI();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GenContext : public MpcvarContext {
  public:
    GenContext(MpcvarContext *ctx);

    antlr4::tree::TerminalNode *MPC();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *LET();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMI();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GencostContext : public MpcvarContext {
  public:
    GencostContext(MpcvarContext *ctx);

    antlr4::tree::TerminalNode *MPC();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *LET();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMI();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BusnameContext : public MpcvarContext {
  public:
    BusnameContext(MpcvarContext *ctx);

    antlr4::tree::TerminalNode *MPC();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *LET();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMI();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BaseMVAContext : public MpcvarContext {
  public:
    BaseMVAContext(MpcvarContext *ctx);

    antlr4::tree::TerminalNode *MPC();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *LET();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMI();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BranchContext : public MpcvarContext {
  public:
    BranchContext(MpcvarContext *ctx);

    antlr4::tree::TerminalNode *MPC();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *LET();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMI();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VersionContext : public MpcvarContext {
  public:
    VersionContext(MpcvarContext *ctx);

    antlr4::tree::TerminalNode *MPC();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *LET();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMI();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  MpcvarContext* mpcvar();

  class  ConstvalueContext : public antlr4::ParserRuleContext {
  public:
    ConstvalueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *INF();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstvalueContext* constvalue();

  class  MpcfunctionContext : public antlr4::ParserRuleContext {
  public:
    MpcfunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    MpcfunctionContext() = default;
    void copyFrom(MpcfunctionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FunctionContext : public MpcfunctionContext {
  public:
    FunctionContext(MpcfunctionContext *ctx);

    antlr4::tree::TerminalNode *FUNCTION();
    antlr4::tree::TerminalNode *MPC();
    antlr4::tree::TerminalNode *LET();
    antlr4::tree::TerminalNode *VARIABLE();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  MpcfunctionContext* mpcfunction();

  class  VallistContext : public antlr4::ParserRuleContext {
  public:
    VallistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    VallistContext() = default;
    void copyFrom(VallistContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ConstlistContext : public VallistContext {
  public:
    ConstlistContext(VallistContext *ctx);

    std::vector<ConstvalueContext *> constvalue();
    ConstvalueContext* constvalue(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  VallistContext* vallist();

  class  ValmatrixrowContext : public antlr4::ParserRuleContext {
  public:
    ValmatrixrowContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VallistContext *> vallist();
    VallistContext* vallist(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ValmatrixrowContext* valmatrixrow();

  class  ValmatrixContext : public antlr4::ParserRuleContext {
  public:
    ValmatrixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VallistContext *vallist();
    ValmatrixrowContext *valmatrixrow();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ValmatrixContext* valmatrix();

  class  ValarrayContext : public antlr4::ParserRuleContext {
  public:
    ValarrayContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBS();
    ValmatrixContext *valmatrix();
    antlr4::tree::TerminalNode *RBS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ValarrayContext* valarray();

  class  CellarrayContext : public antlr4::ParserRuleContext {
  public:
    CellarrayContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LCB();
    ValmatrixContext *valmatrix();
    antlr4::tree::TerminalNode *RCB();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CellarrayContext* cellarray();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ArrayContext : public ExpressionContext {
  public:
    ArrayContext(ExpressionContext *ctx);

    ValarrayContext *valarray();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VariableContext : public ExpressionContext {
  public:
    VariableContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *VARIABLE();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RealconstContext : public ExpressionContext {
  public:
    RealconstContext(ExpressionContext *ctx);

    ConstvalueContext *constvalue();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CellContext : public ExpressionContext {
  public:
    CellContext(ExpressionContext *ctx);

    CellarrayContext *cellarray();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

