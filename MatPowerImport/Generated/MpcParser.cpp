
// Generated from D:\source\repos\MatPowerImport\MatPowerImport\Mpc.g4 by ANTLR 4.13.0


#include "MpcVisitor.h"

#include "MpcParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct MpcParserStaticData final {
  MpcParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MpcParserStaticData(const MpcParserStaticData&) = delete;
  MpcParserStaticData(MpcParserStaticData&&) = delete;
  MpcParserStaticData& operator=(const MpcParserStaticData&) = delete;
  MpcParserStaticData& operator=(MpcParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag mpcParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
MpcParserStaticData *mpcParserStaticData = nullptr;

void mpcParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (mpcParserStaticData != nullptr) {
    return;
  }
#else
  assert(mpcParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<MpcParserStaticData>(
    std::vector<std::string>{
      "input", "mpcvars", "mpcvar", "constvalue", "mpcfunction", "vallist", 
      "valmatrixrow", "valmatrix", "valarray", "cellarray", "expression"
    },
    std::vector<std::string>{
      "", "'bus'", "'gen'", "'branch'", "'version'", "'gencost'", "'baseMVA'", 
      "'bus_name'", "", "'.'", "'['", "']'", "'{'", "'}'", "'='", "'function'", 
      "", "'''", "", "", "'mpc'", "", "", "", "','", "", "", "';'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "FLOAT", "DOT", "LBS", "RBS", "LCB", 
      "RCB", "LET", "FUNCTION", "INTEGER", "SQUOTE", "INF", "STRING", "MPC", 
      "VARIABLE", "LINE_COMMENT", "NEWLINE", "COMMA", "WSK", "WS", "SEMI"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,27,132,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,1,0,3,0,24,8,0,1,0,5,0,27,8,0,10,0,12,
  	0,30,9,0,1,0,1,0,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,3,2,85,8,2,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,5,1,5,3,5,96,8,5,
  	1,5,5,5,99,8,5,10,5,12,5,102,9,5,1,6,1,6,1,6,3,6,107,8,6,5,6,109,8,6,
  	10,6,12,6,112,9,6,1,7,1,7,3,7,116,8,7,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,
  	1,10,1,10,1,10,1,10,3,10,130,8,10,1,10,0,0,11,0,2,4,6,8,10,12,14,16,18,
  	20,0,1,3,0,8,8,16,16,18,19,136,0,23,1,0,0,0,2,33,1,0,0,0,4,84,1,0,0,0,
  	6,86,1,0,0,0,8,88,1,0,0,0,10,93,1,0,0,0,12,103,1,0,0,0,14,115,1,0,0,0,
  	16,117,1,0,0,0,18,121,1,0,0,0,20,129,1,0,0,0,22,24,3,8,4,0,23,22,1,0,
  	0,0,23,24,1,0,0,0,24,28,1,0,0,0,25,27,3,2,1,0,26,25,1,0,0,0,27,30,1,0,
  	0,0,28,26,1,0,0,0,28,29,1,0,0,0,29,31,1,0,0,0,30,28,1,0,0,0,31,32,5,0,
  	0,1,32,1,1,0,0,0,33,34,3,4,2,0,34,3,1,0,0,0,35,36,5,20,0,0,36,37,5,9,
  	0,0,37,38,5,1,0,0,38,39,5,14,0,0,39,40,3,20,10,0,40,41,5,27,0,0,41,85,
  	1,0,0,0,42,43,5,20,0,0,43,44,5,9,0,0,44,45,5,2,0,0,45,46,5,14,0,0,46,
  	47,3,20,10,0,47,48,5,27,0,0,48,85,1,0,0,0,49,50,5,20,0,0,50,51,5,9,0,
  	0,51,52,5,3,0,0,52,53,5,14,0,0,53,54,3,20,10,0,54,55,5,27,0,0,55,85,1,
  	0,0,0,56,57,5,20,0,0,57,58,5,9,0,0,58,59,5,4,0,0,59,60,5,14,0,0,60,61,
  	3,20,10,0,61,62,5,27,0,0,62,85,1,0,0,0,63,64,5,20,0,0,64,65,5,9,0,0,65,
  	66,5,5,0,0,66,67,5,14,0,0,67,68,3,20,10,0,68,69,5,27,0,0,69,85,1,0,0,
  	0,70,71,5,20,0,0,71,72,5,9,0,0,72,73,5,6,0,0,73,74,5,14,0,0,74,75,3,20,
  	10,0,75,76,5,27,0,0,76,85,1,0,0,0,77,78,5,20,0,0,78,79,5,9,0,0,79,80,
  	5,7,0,0,80,81,5,14,0,0,81,82,3,20,10,0,82,83,5,27,0,0,83,85,1,0,0,0,84,
  	35,1,0,0,0,84,42,1,0,0,0,84,49,1,0,0,0,84,56,1,0,0,0,84,63,1,0,0,0,84,
  	70,1,0,0,0,84,77,1,0,0,0,85,5,1,0,0,0,86,87,7,0,0,0,87,7,1,0,0,0,88,89,
  	5,15,0,0,89,90,5,20,0,0,90,91,5,14,0,0,91,92,5,21,0,0,92,9,1,0,0,0,93,
  	100,3,6,3,0,94,96,5,24,0,0,95,94,1,0,0,0,95,96,1,0,0,0,96,97,1,0,0,0,
  	97,99,3,6,3,0,98,95,1,0,0,0,99,102,1,0,0,0,100,98,1,0,0,0,100,101,1,0,
  	0,0,101,11,1,0,0,0,102,100,1,0,0,0,103,110,3,10,5,0,104,106,5,27,0,0,
  	105,107,3,10,5,0,106,105,1,0,0,0,106,107,1,0,0,0,107,109,1,0,0,0,108,
  	104,1,0,0,0,109,112,1,0,0,0,110,108,1,0,0,0,110,111,1,0,0,0,111,13,1,
  	0,0,0,112,110,1,0,0,0,113,116,3,10,5,0,114,116,3,12,6,0,115,113,1,0,0,
  	0,115,114,1,0,0,0,116,15,1,0,0,0,117,118,5,10,0,0,118,119,3,14,7,0,119,
  	120,5,11,0,0,120,17,1,0,0,0,121,122,5,12,0,0,122,123,3,14,7,0,123,124,
  	5,13,0,0,124,19,1,0,0,0,125,130,3,6,3,0,126,130,5,21,0,0,127,130,3,16,
  	8,0,128,130,3,18,9,0,129,125,1,0,0,0,129,126,1,0,0,0,129,127,1,0,0,0,
  	129,128,1,0,0,0,130,21,1,0,0,0,9,23,28,84,95,100,106,110,115,129
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  mpcParserStaticData = staticData.release();
}

}

MpcParser::MpcParser(TokenStream *input) : MpcParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

MpcParser::MpcParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  MpcParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *mpcParserStaticData->atn, mpcParserStaticData->decisionToDFA, mpcParserStaticData->sharedContextCache, options);
}

MpcParser::~MpcParser() {
  delete _interpreter;
}

const atn::ATN& MpcParser::getATN() const {
  return *mpcParserStaticData->atn;
}

std::string MpcParser::getGrammarFileName() const {
  return "Mpc.g4";
}

const std::vector<std::string>& MpcParser::getRuleNames() const {
  return mpcParserStaticData->ruleNames;
}

const dfa::Vocabulary& MpcParser::getVocabulary() const {
  return mpcParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MpcParser::getSerializedATN() const {
  return mpcParserStaticData->serializedATN;
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


std::any MpcParser::InputContext::accept(tree::ParseTreeVisitor *visitor) {
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
    setState(23);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MpcParser::FUNCTION) {
      setState(22);
      mpcfunction();
    }
    setState(28);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MpcParser::MPC) {
      setState(25);
      mpcvars();
      setState(30);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(31);
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


std::any MpcParser::MpcvarsContext::accept(tree::ParseTreeVisitor *visitor) {
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
    setState(33);
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


std::any MpcParser::BusContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MpcParser::GenContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MpcParser::GencostContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MpcVisitor*>(visitor))
    return parserVisitor->visitGencost(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BusnameContext ------------------------------------------------------------------

tree::TerminalNode* MpcParser::BusnameContext::MPC() {
  return getToken(MpcParser::MPC, 0);
}

tree::TerminalNode* MpcParser::BusnameContext::DOT() {
  return getToken(MpcParser::DOT, 0);
}

tree::TerminalNode* MpcParser::BusnameContext::LET() {
  return getToken(MpcParser::LET, 0);
}

MpcParser::ExpressionContext* MpcParser::BusnameContext::expression() {
  return getRuleContext<MpcParser::ExpressionContext>(0);
}

tree::TerminalNode* MpcParser::BusnameContext::SEMI() {
  return getToken(MpcParser::SEMI, 0);
}

MpcParser::BusnameContext::BusnameContext(MpcvarContext *ctx) { copyFrom(ctx); }


std::any MpcParser::BusnameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MpcVisitor*>(visitor))
    return parserVisitor->visitBusname(this);
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


std::any MpcParser::BaseMVAContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MpcParser::BranchContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MpcParser::VersionContext::accept(tree::ParseTreeVisitor *visitor) {
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
    setState(84);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MpcParser::BusContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(35);
      match(MpcParser::MPC);
      setState(36);
      match(MpcParser::DOT);
      setState(37);
      match(MpcParser::T__0);
      setState(38);
      match(MpcParser::LET);
      setState(39);
      expression();
      setState(40);
      match(MpcParser::SEMI);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MpcParser::GenContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(42);
      match(MpcParser::MPC);
      setState(43);
      match(MpcParser::DOT);
      setState(44);
      match(MpcParser::T__1);
      setState(45);
      match(MpcParser::LET);
      setState(46);
      expression();
      setState(47);
      match(MpcParser::SEMI);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<MpcParser::BranchContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(49);
      match(MpcParser::MPC);
      setState(50);
      match(MpcParser::DOT);
      setState(51);
      match(MpcParser::T__2);
      setState(52);
      match(MpcParser::LET);
      setState(53);
      expression();
      setState(54);
      match(MpcParser::SEMI);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<MpcParser::VersionContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(56);
      match(MpcParser::MPC);
      setState(57);
      match(MpcParser::DOT);
      setState(58);
      match(MpcParser::T__3);
      setState(59);
      match(MpcParser::LET);
      setState(60);
      expression();
      setState(61);
      match(MpcParser::SEMI);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<MpcParser::GencostContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(63);
      match(MpcParser::MPC);
      setState(64);
      match(MpcParser::DOT);
      setState(65);
      match(MpcParser::T__4);
      setState(66);
      match(MpcParser::LET);
      setState(67);
      expression();
      setState(68);
      match(MpcParser::SEMI);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<MpcParser::BaseMVAContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(70);
      match(MpcParser::MPC);
      setState(71);
      match(MpcParser::DOT);
      setState(72);
      match(MpcParser::T__5);
      setState(73);
      match(MpcParser::LET);
      setState(74);
      expression();
      setState(75);
      match(MpcParser::SEMI);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<MpcParser::BusnameContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(77);
      match(MpcParser::MPC);
      setState(78);
      match(MpcParser::DOT);
      setState(79);
      match(MpcParser::T__6);
      setState(80);
      match(MpcParser::LET);
      setState(81);
      expression();
      setState(82);
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

tree::TerminalNode* MpcParser::ConstvalueContext::INF() {
  return getToken(MpcParser::INF, 0);
}


size_t MpcParser::ConstvalueContext::getRuleIndex() const {
  return MpcParser::RuleConstvalue;
}


std::any MpcParser::ConstvalueContext::accept(tree::ParseTreeVisitor *visitor) {
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
    setState(86);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 852224) != 0))) {
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


std::any MpcParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
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
    _localctx = _tracker.createInstance<MpcParser::FunctionContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(88);
    match(MpcParser::FUNCTION);
    setState(89);
    match(MpcParser::MPC);
    setState(90);
    match(MpcParser::LET);
    setState(91);
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


std::any MpcParser::ConstlistContext::accept(tree::ParseTreeVisitor *visitor) {
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
    _localctx = _tracker.createInstance<MpcParser::ConstlistContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(93);
    constvalue();
    setState(100);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 17629440) != 0)) {
      setState(95);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MpcParser::COMMA) {
        setState(94);
        match(MpcParser::COMMA);
      }
      setState(97);
      constvalue();
      setState(102);
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


std::any MpcParser::ValmatrixrowContext::accept(tree::ParseTreeVisitor *visitor) {
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
    setState(103);
    vallist();
    setState(110);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MpcParser::SEMI) {
      setState(104);
      match(MpcParser::SEMI);
      setState(106);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 852224) != 0)) {
        setState(105);
        vallist();
      }
      setState(112);
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


std::any MpcParser::ValmatrixContext::accept(tree::ParseTreeVisitor *visitor) {
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
    setState(115);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(113);
      vallist();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(114);
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


std::any MpcParser::ValarrayContext::accept(tree::ParseTreeVisitor *visitor) {
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
    setState(117);
    match(MpcParser::LBS);
    setState(118);
    valmatrix();
    setState(119);
    match(MpcParser::RBS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CellarrayContext ------------------------------------------------------------------

MpcParser::CellarrayContext::CellarrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MpcParser::CellarrayContext::LCB() {
  return getToken(MpcParser::LCB, 0);
}

MpcParser::ValmatrixContext* MpcParser::CellarrayContext::valmatrix() {
  return getRuleContext<MpcParser::ValmatrixContext>(0);
}

tree::TerminalNode* MpcParser::CellarrayContext::RCB() {
  return getToken(MpcParser::RCB, 0);
}


size_t MpcParser::CellarrayContext::getRuleIndex() const {
  return MpcParser::RuleCellarray;
}


std::any MpcParser::CellarrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MpcVisitor*>(visitor))
    return parserVisitor->visitCellarray(this);
  else
    return visitor->visitChildren(this);
}

MpcParser::CellarrayContext* MpcParser::cellarray() {
  CellarrayContext *_localctx = _tracker.createInstance<CellarrayContext>(_ctx, getState());
  enterRule(_localctx, 18, MpcParser::RuleCellarray);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    match(MpcParser::LCB);
    setState(122);
    valmatrix();
    setState(123);
    match(MpcParser::RCB);
   
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


std::any MpcParser::ArrayContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MpcParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MpcParser::RealconstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MpcVisitor*>(visitor))
    return parserVisitor->visitRealconst(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CellContext ------------------------------------------------------------------

MpcParser::CellarrayContext* MpcParser::CellContext::cellarray() {
  return getRuleContext<MpcParser::CellarrayContext>(0);
}

MpcParser::CellContext::CellContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any MpcParser::CellContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MpcVisitor*>(visitor))
    return parserVisitor->visitCell(this);
  else
    return visitor->visitChildren(this);
}
MpcParser::ExpressionContext* MpcParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 20, MpcParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(129);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MpcParser::FLOAT:
      case MpcParser::INTEGER:
      case MpcParser::INF:
      case MpcParser::STRING: {
        _localctx = _tracker.createInstance<MpcParser::RealconstContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(125);
        constvalue();
        break;
      }

      case MpcParser::VARIABLE: {
        _localctx = _tracker.createInstance<MpcParser::VariableContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(126);
        match(MpcParser::VARIABLE);
        break;
      }

      case MpcParser::LBS: {
        _localctx = _tracker.createInstance<MpcParser::ArrayContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(127);
        valarray();
        break;
      }

      case MpcParser::LCB: {
        _localctx = _tracker.createInstance<MpcParser::CellContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(128);
        cellarray();
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

void MpcParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  mpcParserInitialize();
#else
  ::antlr4::internal::call_once(mpcParserOnceFlag, mpcParserInitialize);
#endif
}
