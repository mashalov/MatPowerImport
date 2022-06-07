
// Generated from C:\Users\Bug9\source\repos\MatPowerImport\MatPowerImport\Mpc.g4 by ANTLR 4.9.2


#include "MpcVisitor.h"

#include "MpcParser.h"


using namespace antlrcpp;
using namespace antlr4;

MpcParser::MpcParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

MpcParser::~MpcParser() {
  delete _interpreter;
}

std::string MpcParser::getGrammarFileName() const {
  return "Mpc.g4";
}

const std::vector<std::string>& MpcParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& MpcParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- InputContext ------------------------------------------------------------------

MpcParser::InputContext::InputContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MpcParser::InputContext::EOF() {
  return getToken(MpcParser::EOF, 0);
}

MpcParser::MpcfunctionContext* MpcParser::InputContext::mpcfunction() {
  return getRuleContext<MpcParser::MpcfunctionContext>(0);
}

std::vector<MpcParser::MpcvarsContext *> MpcParser::InputContext::mpcvars() {
  return getRuleContexts<MpcParser::MpcvarsContext>();
}

MpcParser::MpcvarsContext* MpcParser::InputContext::mpcvars(size_t i) {
  return getRuleContext<MpcParser::MpcvarsContext>(i);
}


size_t MpcParser::InputContext::getRuleIndex() const {
  return MpcParser::RuleInput;
}


antlrcpp::Any MpcParser::InputContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MpcVisitor*>(visitor))
    return parserVisitor->visitInput(this);
  else
    return visitor->visitChildren(this);
}

MpcParser::InputContext* MpcParser::input() {
  InputContext *_localctx = _tracker.createInstance<InputContext>(_ctx, getState());
  enterRule(_localctx, 0, MpcParser::RuleInput);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(21);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MpcParser::FUNCTION) {
      setState(20);
      mpcfunction();
    }
    setState(26);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MpcParser::MPC) {
      setState(23);
      mpcvars();
      setState(28);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(29);
    match(MpcParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MpcvarsContext ------------------------------------------------------------------

MpcParser::MpcvarsContext::MpcvarsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MpcParser::MpcvarContext* MpcParser::MpcvarsContext::mpcvar() {
  return getRuleContext<MpcParser::MpcvarContext>(0);
}


size_t MpcParser::MpcvarsContext::getRuleIndex() const {
  return MpcParser::RuleMpcvars;
}


antlrcpp::Any MpcParser::MpcvarsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MpcVisitor*>(visitor))
    return parserVisitor->visitMpcvars(this);
  else
    return visitor->visitChildren(this);
}

MpcParser::MpcvarsContext* MpcParser::mpcvars() {
  MpcvarsContext *_localctx = _tracker.createInstance<MpcvarsContext>(_ctx, getState());
  enterRule(_localctx, 2, MpcParser::RuleMpcvars);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(31);
    mpcvar();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MpcvarContext ------------------------------------------------------------------

MpcParser::MpcvarContext::MpcvarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MpcParser::MpcvarContext::getRuleIndex() const {
  return MpcParser::RuleMpcvar;
}

void MpcParser::MpcvarContext::copyFrom(MpcvarContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BusContext ------------------------------------------------------------------

tree::TerminalNode* MpcParser::BusContext::MPC() {
  return getToken(MpcParser::MPC, 0);
}

tree::TerminalNode* MpcParser::BusContext::DOT() {
  return getToken(MpcParser::DOT, 0);
}

tree::TerminalNode* MpcParser::BusContext::LET() {
  return getToken(MpcParser::LET, 0);
}

MpcParser::ExpressionContext* MpcParser::BusContext::expression() {
  return getRuleContext<MpcParser::ExpressionContext>(0);
}

tree::TerminalNode* MpcParser::BusContext::SEMI() {
  return getToken(MpcParser::SEMI, 0);
}

MpcParser::BusContext::BusContext(MpcvarContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MpcParser::BusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MpcVisitor*>(visitor))
    return parserVisitor->visitBus(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GenContext ------------------------------------------------------------------

tree::TerminalNode* MpcParser::GenContext::MPC() {
  return getToken(MpcParser::MPC, 0);
}

tree::TerminalNode* MpcParser::GenContext::DOT() {
  return getToken(MpcParser::DOT, 0);
}

tree::TerminalNode* MpcParser::GenContext::LET() {
  return getToken(MpcParser::LET, 0);
}

MpcParser::ExpressionContext* MpcParser::GenContext::expression() {
  return getRuleContext<MpcParser::ExpressionContext>(0);
}

tree::TerminalNode* MpcParser::GenContext::SEMI() {
  return getToken(MpcParser::SEMI, 0);
}

MpcParser::GenContext::GenContext(MpcvarContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MpcParser::GenContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MpcVisitor*>(visitor))
    return parserVisitor->visitGen(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GencostContext ------------------------------------------------------------------

tree::TerminalNode* MpcParser::GencostContext::MPC() {
  return getToken(MpcParser::MPC, 0);
}

tree::TerminalNode* MpcParser::GencostContext::DOT() {
  return getToken(MpcParser::DOT, 0);
}

tree::TerminalNode* MpcParser::GencostContext::LET() {
  return getToken(MpcParser::LET, 0);
}

MpcParser::ExpressionContext* MpcParser::GencostContext::expression() {
  return getRuleContext<MpcParser::ExpressionContext>(0);
}

tree::TerminalNode* MpcParser::GencostContext::SEMI() {
  return getToken(MpcParser::SEMI, 0);
}

MpcParser::GencostContext::GencostContext(MpcvarContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MpcParser::GencostContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MpcVisitor*>(visitor))
    return parserVisitor->visitGencost(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BaseMVAContext ------------------------------------------------------------------

tree::TerminalNode* MpcParser::BaseMVAContext::MPC() {
  return getToken(MpcParser::MPC, 0);
}

tree::TerminalNode* MpcParser::BaseMVAContext::DOT() {
  return getToken(MpcParser::DOT, 0);
}

tree::TerminalNode* MpcParser::BaseMVAContext::LET() {
  return getToken(MpcParser::LET, 0);
}

MpcParser::ExpressionContext* MpcParser::BaseMVAContext::expression() {
  return getRuleContext<MpcParser::ExpressionContext>(0);
}

tree::TerminalNode* MpcParser::BaseMVAContext::SEMI() {
  return getToken(MpcParser::SEMI, 0);
}

MpcParser::BaseMVAContext::BaseMVAContext(MpcvarContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MpcParser::BaseMVAContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MpcVisitor*>(visitor))
    return parserVisitor->visitBaseMVA(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BranchContext ------------------------------------------------------------------

tree::TerminalNode* MpcParser::BranchContext::MPC() {
  return getToken(MpcParser::MPC, 0);
}

tree::TerminalNode* MpcParser::BranchContext::DOT() {
  return getToken(MpcParser::DOT, 0);
}

tree::TerminalNode* MpcParser::BranchContext::LET() {
  return getToken(MpcParser::LET, 0);
}

MpcParser::ExpressionContext* MpcParser::BranchContext::expression() {
  return getRuleContext<MpcParser::ExpressionContext>(0);
}

tree::TerminalNode* MpcParser::BranchContext::SEMI() {
  return getToken(MpcParser::SEMI, 0);
}

MpcParser::BranchContext::BranchContext(MpcvarContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MpcParser::BranchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MpcVisitor*>(visitor))
    return parserVisitor->visitBranch(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VersionContext ------------------------------------------------------------------

tree::TerminalNode* MpcParser::VersionContext::MPC() {
  return getToken(MpcParser::MPC, 0);
}

tree::TerminalNode* MpcParser::VersionContext::DOT() {
  return getToken(MpcParser::DOT, 0);
}

tree::TerminalNode* MpcParser::VersionContext::LET() {
  return getToken(MpcParser::LET, 0);
}

MpcParser::ExpressionContext* MpcParser::VersionContext::expression() {
  return getRuleContext<MpcParser::ExpressionContext>(0);
}

tree::TerminalNode* MpcParser::VersionContext::SEMI() {
  return getToken(MpcParser::SEMI, 0);
}

MpcParser::VersionContext::VersionContext(MpcvarContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MpcParser::VersionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MpcVisitor*>(visitor))
    return parserVisitor->visitVersion(this);
  else
    return visitor->visitChildren(this);
}
MpcParser::MpcvarContext* MpcParser::mpcvar() {
  MpcvarContext *_localctx = _tracker.createInstance<MpcvarContext>(_ctx, getState());
  enterRule(_localctx, 4, MpcParser::RuleMpcvar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(75);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<MpcvarContext *>(_tracker.createInstance<MpcParser::BusContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(33);
      match(MpcParser::MPC);
      setState(34);
      match(MpcParser::DOT);
      setState(35);
      match(MpcParser::T__0);
      setState(36);
      match(MpcParser::LET);
      setState(37);
      expression();
      setState(38);
      match(MpcParser::SEMI);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<MpcvarContext *>(_tracker.createInstance<MpcParser::GenContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(40);
      match(MpcParser::MPC);
      setState(41);
      match(MpcParser::DOT);
      setState(42);
      match(MpcParser::T__1);
      setState(43);
      match(MpcParser::LET);
      setState(44);
      expression();
      setState(45);
      match(MpcParser::SEMI);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<MpcvarContext *>(_tracker.createInstance<MpcParser::BranchContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(47);
      match(MpcParser::MPC);
      setState(48);
      match(MpcParser::DOT);
      setState(49);
      match(MpcParser::T__2);
      setState(50);
      match(MpcParser::LET);
      setState(51);
      expression();
      setState(52);
      match(MpcParser::SEMI);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<MpcvarContext *>(_tracker.createInstance<MpcParser::VersionContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(54);
      match(MpcParser::MPC);
      setState(55);
      match(MpcParser::DOT);
      setState(56);
      match(MpcParser::T__3);
      setState(57);
      match(MpcParser::LET);
      setState(58);
      expression();
      setState(59);
      match(MpcParser::SEMI);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<MpcvarContext *>(_tracker.createInstance<MpcParser::GencostContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(61);
      match(MpcParser::MPC);
      setState(62);
      match(MpcParser::DOT);
      setState(63);
      match(MpcParser::T__4);
      setState(64);
      match(MpcParser::LET);
      setState(65);
      expression();
      setState(66);
      match(MpcParser::SEMI);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<MpcvarContext *>(_tracker.createInstance<MpcParser::BaseMVAContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(68);
      match(MpcParser::MPC);
      setState(69);
      match(MpcParser::DOT);
      setState(70);
      match(MpcParser::T__5);
      setState(71);
      match(MpcParser::LET);
      setState(72);
      expression();
      setState(73);
      match(MpcParser::SEMI);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstvalueContext ------------------------------------------------------------------

MpcParser::ConstvalueContext::ConstvalueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MpcParser::ConstvalueContext::FLOAT() {
  return getToken(MpcParser::FLOAT, 0);
}

tree::TerminalNode* MpcParser::ConstvalueContext::INTEGER() {
  return getToken(MpcParser::INTEGER, 0);
}

tree::TerminalNode* MpcParser::ConstvalueContext::STRING() {
  return getToken(MpcParser::STRING, 0);
}


size_t MpcParser::ConstvalueContext::getRuleIndex() const {
  return MpcParser::RuleConstvalue;
}


antlrcpp::Any MpcParser::ConstvalueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MpcVisitor*>(visitor))
    return parserVisitor->visitConstvalue(this);
  else
    return visitor->visitChildren(this);
}

MpcParser::ConstvalueContext* MpcParser::constvalue() {
  ConstvalueContext *_localctx = _tracker.createInstance<ConstvalueContext>(_ctx, getState());
  enterRule(_localctx, 6, MpcParser::RuleConstvalue);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MpcParser::FLOAT)
      | (1ULL << MpcParser::INTEGER)
      | (1ULL << MpcParser::STRING))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MpcfunctionContext ------------------------------------------------------------------

MpcParser::MpcfunctionContext::MpcfunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MpcParser::MpcfunctionContext::getRuleIndex() const {
  return MpcParser::RuleMpcfunction;
}

void MpcParser::MpcfunctionContext::copyFrom(MpcfunctionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FunctionContext ------------------------------------------------------------------

tree::TerminalNode* MpcParser::FunctionContext::FUNCTION() {
  return getToken(MpcParser::FUNCTION, 0);
}

tree::TerminalNode* MpcParser::FunctionContext::MPC() {
  return getToken(MpcParser::MPC, 0);
}

tree::TerminalNode* MpcParser::FunctionContext::LET() {
  return getToken(MpcParser::LET, 0);
}

tree::TerminalNode* MpcParser::FunctionContext::VARIABLE() {
  return getToken(MpcParser::VARIABLE, 0);
}

MpcParser::FunctionContext::FunctionContext(MpcfunctionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MpcParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MpcVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}
MpcParser::MpcfunctionContext* MpcParser::mpcfunction() {
  MpcfunctionContext *_localctx = _tracker.createInstance<MpcfunctionContext>(_ctx, getState());
  enterRule(_localctx, 8, MpcParser::RuleMpcfunction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = dynamic_cast<MpcfunctionContext *>(_tracker.createInstance<MpcParser::FunctionContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(79);
    match(MpcParser::FUNCTION);
    setState(80);
    match(MpcParser::MPC);
    setState(81);
    match(MpcParser::LET);
    setState(82);
    match(MpcParser::VARIABLE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VallistContext ------------------------------------------------------------------

MpcParser::VallistContext::VallistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MpcParser::VallistContext::getRuleIndex() const {
  return MpcParser::RuleVallist;
}

void MpcParser::VallistContext::copyFrom(VallistContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ConstlistContext ------------------------------------------------------------------

std::vector<MpcParser::ConstvalueContext *> MpcParser::ConstlistContext::constvalue() {
  return getRuleContexts<MpcParser::ConstvalueContext>();
}

MpcParser::ConstvalueContext* MpcParser::ConstlistContext::constvalue(size_t i) {
  return getRuleContext<MpcParser::ConstvalueContext>(i);
}

std::vector<tree::TerminalNode *> MpcParser::ConstlistContext::COMMA() {
  return getTokens(MpcParser::COMMA);
}

tree::TerminalNode* MpcParser::ConstlistContext::COMMA(size_t i) {
  return getToken(MpcParser::COMMA, i);
}

MpcParser::ConstlistContext::ConstlistContext(VallistContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MpcParser::ConstlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MpcVisitor*>(visitor))
    return parserVisitor->visitConstlist(this);
  else
    return visitor->visitChildren(this);
}
MpcParser::VallistContext* MpcParser::vallist() {
  VallistContext *_localctx = _tracker.createInstance<VallistContext>(_ctx, getState());
  enterRule(_localctx, 10, MpcParser::RuleVallist);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = dynamic_cast<VallistContext *>(_tracker.createInstance<MpcParser::ConstlistContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(84);
    constvalue();
    setState(91);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MpcParser::FLOAT)
      | (1ULL << MpcParser::INTEGER)
      | (1ULL << MpcParser::STRING)
      | (1ULL << MpcParser::COMMA))) != 0)) {
      setState(86);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MpcParser::COMMA) {
        setState(85);
        match(MpcParser::COMMA);
      }
      setState(88);
      constvalue();
      setState(93);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValmatrixrowContext ------------------------------------------------------------------

MpcParser::ValmatrixrowContext::ValmatrixrowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MpcParser::VallistContext *> MpcParser::ValmatrixrowContext::vallist() {
  return getRuleContexts<MpcParser::VallistContext>();
}

MpcParser::VallistContext* MpcParser::ValmatrixrowContext::vallist(size_t i) {
  return getRuleContext<MpcParser::VallistContext>(i);
}

std::vector<tree::TerminalNode *> MpcParser::ValmatrixrowContext::SEMI() {
  return getTokens(MpcParser::SEMI);
}

tree::TerminalNode* MpcParser::ValmatrixrowContext::SEMI(size_t i) {
  return getToken(MpcParser::SEMI, i);
}


size_t MpcParser::ValmatrixrowContext::getRuleIndex() const {
  return MpcParser::RuleValmatrixrow;
}


antlrcpp::Any MpcParser::ValmatrixrowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MpcVisitor*>(visitor))
    return parserVisitor->visitValmatrixrow(this);
  else
    return visitor->visitChildren(this);
}

MpcParser::ValmatrixrowContext* MpcParser::valmatrixrow() {
  ValmatrixrowContext *_localctx = _tracker.createInstance<ValmatrixrowContext>(_ctx, getState());
  enterRule(_localctx, 12, MpcParser::RuleValmatrixrow);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    vallist();
    setState(101);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MpcParser::SEMI) {
      setState(95);
      match(MpcParser::SEMI);
      setState(97);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MpcParser::FLOAT)
        | (1ULL << MpcParser::INTEGER)
        | (1ULL << MpcParser::STRING))) != 0)) {
        setState(96);
        vallist();
      }
      setState(103);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValmatrixContext ------------------------------------------------------------------

MpcParser::ValmatrixContext::ValmatrixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MpcParser::VallistContext* MpcParser::ValmatrixContext::vallist() {
  return getRuleContext<MpcParser::VallistContext>(0);
}

MpcParser::ValmatrixrowContext* MpcParser::ValmatrixContext::valmatrixrow() {
  return getRuleContext<MpcParser::ValmatrixrowContext>(0);
}


size_t MpcParser::ValmatrixContext::getRuleIndex() const {
  return MpcParser::RuleValmatrix;
}


antlrcpp::Any MpcParser::ValmatrixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MpcVisitor*>(visitor))
    return parserVisitor->visitValmatrix(this);
  else
    return visitor->visitChildren(this);
}

MpcParser::ValmatrixContext* MpcParser::valmatrix() {
  ValmatrixContext *_localctx = _tracker.createInstance<ValmatrixContext>(_ctx, getState());
  enterRule(_localctx, 14, MpcParser::RuleValmatrix);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(106);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(104);
      vallist();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(105);
      valmatrixrow();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValarrayContext ------------------------------------------------------------------

MpcParser::ValarrayContext::ValarrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MpcParser::ValarrayContext::LBS() {
  return getToken(MpcParser::LBS, 0);
}

MpcParser::ValmatrixContext* MpcParser::ValarrayContext::valmatrix() {
  return getRuleContext<MpcParser::ValmatrixContext>(0);
}

tree::TerminalNode* MpcParser::ValarrayContext::RBS() {
  return getToken(MpcParser::RBS, 0);
}


size_t MpcParser::ValarrayContext::getRuleIndex() const {
  return MpcParser::RuleValarray;
}


antlrcpp::Any MpcParser::ValarrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MpcVisitor*>(visitor))
    return parserVisitor->visitValarray(this);
  else
    return visitor->visitChildren(this);
}

MpcParser::ValarrayContext* MpcParser::valarray() {
  ValarrayContext *_localctx = _tracker.createInstance<ValarrayContext>(_ctx, getState());
  enterRule(_localctx, 16, MpcParser::RuleValarray);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    match(MpcParser::LBS);
    setState(109);
    valmatrix();
    setState(110);
    match(MpcParser::RBS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

MpcParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MpcParser::ExpressionContext::getRuleIndex() const {
  return MpcParser::RuleExpression;
}

void MpcParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ArrayContext ------------------------------------------------------------------

MpcParser::ValarrayContext* MpcParser::ArrayContext::valarray() {
  return getRuleContext<MpcParser::ValarrayContext>(0);
}

MpcParser::ArrayContext::ArrayContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MpcParser::ArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MpcVisitor*>(visitor))
    return parserVisitor->visitArray(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableContext ------------------------------------------------------------------

tree::TerminalNode* MpcParser::VariableContext::VARIABLE() {
  return getToken(MpcParser::VARIABLE, 0);
}

MpcParser::VariableContext::VariableContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MpcParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MpcVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RealconstContext ------------------------------------------------------------------

MpcParser::ConstvalueContext* MpcParser::RealconstContext::constvalue() {
  return getRuleContext<MpcParser::ConstvalueContext>(0);
}

MpcParser::RealconstContext::RealconstContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MpcParser::RealconstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MpcVisitor*>(visitor))
    return parserVisitor->visitRealconst(this);
  else
    return visitor->visitChildren(this);
}
MpcParser::ExpressionContext* MpcParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 18, MpcParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(115);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MpcParser::FLOAT:
      case MpcParser::INTEGER:
      case MpcParser::STRING: {
        _localctx = dynamic_cast<ExpressionContext *>(_tracker.createInstance<MpcParser::RealconstContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(112);
        constvalue();
        break;
      }

      case MpcParser::VARIABLE: {
        _localctx = dynamic_cast<ExpressionContext *>(_tracker.createInstance<MpcParser::VariableContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(113);
        match(MpcParser::VARIABLE);
        break;
      }

      case MpcParser::LBS: {
        _localctx = dynamic_cast<ExpressionContext *>(_tracker.createInstance<MpcParser::ArrayContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(114);
        valarray();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> MpcParser::_decisionToDFA;
atn::PredictionContextCache MpcParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN MpcParser::_atn;
std::vector<uint16_t> MpcParser::_serializedATN;

std::vector<std::string> MpcParser::_ruleNames = {
  "input", "mpcvars", "mpcvar", "constvalue", "mpcfunction", "vallist", 
  "valmatrixrow", "valmatrix", "valarray", "expression"
};

std::vector<std::string> MpcParser::_literalNames = {
  "", "'bus'", "'gen'", "'branch'", "'version'", "'gencost'", "'baseMVA'", 
  "", "'.'", "'['", "']'", "'='", "'function'", "", "", "'mpc'", "", "", 
  "", "','", "", "", "';'"
};

std::vector<std::string> MpcParser::_symbolicNames = {
  "", "", "", "", "", "", "", "FLOAT", "DOT", "LBS", "RBS", "LET", "FUNCTION", 
  "INTEGER", "STRING", "MPC", "VARIABLE", "LINE_COMMENT", "NEWLINE", "COMMA", 
  "WSK", "WS", "SEMI"
};

dfa::Vocabulary MpcParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> MpcParser::_tokenNames;

MpcParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x18, 0x78, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x3, 0x2, 0x5, 0x2, 0x18, 0xa, 0x2, 0x3, 0x2, 
       0x7, 0x2, 0x1b, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x1e, 0xb, 0x2, 0x3, 
       0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x5, 0x4, 0x4e, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 
       0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x59, 
       0xa, 0x7, 0x3, 0x7, 0x7, 0x7, 0x5c, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 
       0x5f, 0xb, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x64, 0xa, 
       0x8, 0x7, 0x8, 0x66, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x69, 0xb, 0x8, 
       0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x6d, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 
       0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x76, 
       0xa, 0xb, 0x3, 0xb, 0x2, 0x2, 0xc, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
       0xe, 0x10, 0x12, 0x14, 0x2, 0x3, 0x4, 0x2, 0x9, 0x9, 0xf, 0x10, 0x2, 
       0x7b, 0x2, 0x17, 0x3, 0x2, 0x2, 0x2, 0x4, 0x21, 0x3, 0x2, 0x2, 0x2, 
       0x6, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x8, 0x4f, 0x3, 0x2, 0x2, 0x2, 0xa, 
       0x51, 0x3, 0x2, 0x2, 0x2, 0xc, 0x56, 0x3, 0x2, 0x2, 0x2, 0xe, 0x60, 
       0x3, 0x2, 0x2, 0x2, 0x10, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x12, 0x6e, 0x3, 
       0x2, 0x2, 0x2, 0x14, 0x75, 0x3, 0x2, 0x2, 0x2, 0x16, 0x18, 0x5, 0xa, 
       0x6, 0x2, 0x17, 0x16, 0x3, 0x2, 0x2, 0x2, 0x17, 0x18, 0x3, 0x2, 0x2, 
       0x2, 0x18, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1b, 0x5, 0x4, 0x3, 0x2, 
       0x1a, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x1c, 
       0x1a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1f, 
       0x3, 0x2, 0x2, 0x2, 0x1e, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 0x7, 
       0x2, 0x2, 0x3, 0x20, 0x3, 0x3, 0x2, 0x2, 0x2, 0x21, 0x22, 0x5, 0x6, 
       0x4, 0x2, 0x22, 0x5, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 0x7, 0x11, 0x2, 
       0x2, 0x24, 0x25, 0x7, 0xa, 0x2, 0x2, 0x25, 0x26, 0x7, 0x3, 0x2, 0x2, 
       0x26, 0x27, 0x7, 0xd, 0x2, 0x2, 0x27, 0x28, 0x5, 0x14, 0xb, 0x2, 
       0x28, 0x29, 0x7, 0x18, 0x2, 0x2, 0x29, 0x4e, 0x3, 0x2, 0x2, 0x2, 
       0x2a, 0x2b, 0x7, 0x11, 0x2, 0x2, 0x2b, 0x2c, 0x7, 0xa, 0x2, 0x2, 
       0x2c, 0x2d, 0x7, 0x4, 0x2, 0x2, 0x2d, 0x2e, 0x7, 0xd, 0x2, 0x2, 0x2e, 
       0x2f, 0x5, 0x14, 0xb, 0x2, 0x2f, 0x30, 0x7, 0x18, 0x2, 0x2, 0x30, 
       0x4e, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x7, 0x11, 0x2, 0x2, 0x32, 
       0x33, 0x7, 0xa, 0x2, 0x2, 0x33, 0x34, 0x7, 0x5, 0x2, 0x2, 0x34, 0x35, 
       0x7, 0xd, 0x2, 0x2, 0x35, 0x36, 0x5, 0x14, 0xb, 0x2, 0x36, 0x37, 
       0x7, 0x18, 0x2, 0x2, 0x37, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 
       0x7, 0x11, 0x2, 0x2, 0x39, 0x3a, 0x7, 0xa, 0x2, 0x2, 0x3a, 0x3b, 
       0x7, 0x6, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0xd, 0x2, 0x2, 0x3c, 0x3d, 0x5, 
       0x14, 0xb, 0x2, 0x3d, 0x3e, 0x7, 0x18, 0x2, 0x2, 0x3e, 0x4e, 0x3, 
       0x2, 0x2, 0x2, 0x3f, 0x40, 0x7, 0x11, 0x2, 0x2, 0x40, 0x41, 0x7, 
       0xa, 0x2, 0x2, 0x41, 0x42, 0x7, 0x7, 0x2, 0x2, 0x42, 0x43, 0x7, 0xd, 
       0x2, 0x2, 0x43, 0x44, 0x5, 0x14, 0xb, 0x2, 0x44, 0x45, 0x7, 0x18, 
       0x2, 0x2, 0x45, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x7, 0x11, 
       0x2, 0x2, 0x47, 0x48, 0x7, 0xa, 0x2, 0x2, 0x48, 0x49, 0x7, 0x8, 0x2, 
       0x2, 0x49, 0x4a, 0x7, 0xd, 0x2, 0x2, 0x4a, 0x4b, 0x5, 0x14, 0xb, 
       0x2, 0x4b, 0x4c, 0x7, 0x18, 0x2, 0x2, 0x4c, 0x4e, 0x3, 0x2, 0x2, 
       0x2, 0x4d, 0x23, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x2a, 0x3, 0x2, 0x2, 0x2, 
       0x4d, 0x31, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x38, 0x3, 0x2, 0x2, 0x2, 0x4d, 
       0x3f, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x46, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x7, 
       0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x9, 0x2, 0x2, 0x2, 0x50, 0x9, 0x3, 
       0x2, 0x2, 0x2, 0x51, 0x52, 0x7, 0xe, 0x2, 0x2, 0x52, 0x53, 0x7, 0x11, 
       0x2, 0x2, 0x53, 0x54, 0x7, 0xd, 0x2, 0x2, 0x54, 0x55, 0x7, 0x12, 
       0x2, 0x2, 0x55, 0xb, 0x3, 0x2, 0x2, 0x2, 0x56, 0x5d, 0x5, 0x8, 0x5, 
       0x2, 0x57, 0x59, 0x7, 0x15, 0x2, 0x2, 0x58, 0x57, 0x3, 0x2, 0x2, 
       0x2, 0x58, 0x59, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x3, 0x2, 0x2, 0x2, 
       0x5a, 0x5c, 0x5, 0x8, 0x5, 0x2, 0x5b, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5c, 
       0x5f, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 
       0x3, 0x2, 0x2, 0x2, 0x5e, 0xd, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x5d, 0x3, 
       0x2, 0x2, 0x2, 0x60, 0x67, 0x5, 0xc, 0x7, 0x2, 0x61, 0x63, 0x7, 0x18, 
       0x2, 0x2, 0x62, 0x64, 0x5, 0xc, 0x7, 0x2, 0x63, 0x62, 0x3, 0x2, 0x2, 
       0x2, 0x63, 0x64, 0x3, 0x2, 0x2, 0x2, 0x64, 0x66, 0x3, 0x2, 0x2, 0x2, 
       0x65, 0x61, 0x3, 0x2, 0x2, 0x2, 0x66, 0x69, 0x3, 0x2, 0x2, 0x2, 0x67, 
       0x65, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x3, 0x2, 0x2, 0x2, 0x68, 0xf, 
       0x3, 0x2, 0x2, 0x2, 0x69, 0x67, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6d, 0x5, 
       0xc, 0x7, 0x2, 0x6b, 0x6d, 0x5, 0xe, 0x8, 0x2, 0x6c, 0x6a, 0x3, 0x2, 
       0x2, 0x2, 0x6c, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x11, 0x3, 0x2, 0x2, 
       0x2, 0x6e, 0x6f, 0x7, 0xb, 0x2, 0x2, 0x6f, 0x70, 0x5, 0x10, 0x9, 
       0x2, 0x70, 0x71, 0x7, 0xc, 0x2, 0x2, 0x71, 0x13, 0x3, 0x2, 0x2, 0x2, 
       0x72, 0x76, 0x5, 0x8, 0x5, 0x2, 0x73, 0x76, 0x7, 0x12, 0x2, 0x2, 
       0x74, 0x76, 0x5, 0x12, 0xa, 0x2, 0x75, 0x72, 0x3, 0x2, 0x2, 0x2, 
       0x75, 0x73, 0x3, 0x2, 0x2, 0x2, 0x75, 0x74, 0x3, 0x2, 0x2, 0x2, 0x76, 
       0x15, 0x3, 0x2, 0x2, 0x2, 0xb, 0x17, 0x1c, 0x4d, 0x58, 0x5d, 0x63, 
       0x67, 0x6c, 0x75, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

MpcParser::Initializer MpcParser::_init;
