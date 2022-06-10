
// Generated from C:/Users/Bug9/source/repos/MatPowerImport/MatPowerImport/Mpc.g4 by ANTLR 4.10.1


#include "MpcLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct MpcLexerStaticData final {
  MpcLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MpcLexerStaticData(const MpcLexerStaticData&) = delete;
  MpcLexerStaticData(MpcLexerStaticData&&) = delete;
  MpcLexerStaticData& operator=(const MpcLexerStaticData&) = delete;
  MpcLexerStaticData& operator=(MpcLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag mpclexerLexerOnceFlag;
MpcLexerStaticData *mpclexerLexerStaticData = nullptr;

void mpclexerLexerInitialize() {
  assert(mpclexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<MpcLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "FLOAT", "DOT", 
      "LBS", "RBS", "LCB", "RCB", "LET", "FUNCTION", "INTEGER", "SQUOTE", 
      "INSTRING", "INF", "STRING", "SIGN", "DIGITS", "Exponent", "MPC", 
      "VARIABLE", "LINE_COMMENT", "NEWLINE", "COMMA", "WSK", "WS", "SEMI"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,27,232,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,7,1,7,1,7,1,7,3,7,116,8,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,
  	7,1,7,3,7,128,8,7,3,7,130,8,7,1,7,3,7,133,8,7,3,7,135,8,7,1,8,1,8,1,9,
  	1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,1,14,1,14,1,15,1,15,1,15,1,16,1,16,1,17,5,17,164,8,17,10,17,
  	12,17,167,9,17,1,18,1,18,1,18,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,20,
  	3,20,180,8,20,1,21,4,21,183,8,21,11,21,12,21,184,1,22,1,22,3,22,189,8,
  	22,1,22,1,22,1,23,1,23,1,23,1,23,1,24,1,24,5,24,199,8,24,10,24,12,24,
  	202,9,24,1,25,1,25,5,25,206,8,25,10,25,12,25,209,9,25,1,25,1,25,1,26,
  	3,26,214,8,26,1,26,1,26,1,26,1,26,1,27,1,27,1,28,1,28,1,28,1,28,1,29,
  	4,29,227,8,29,11,29,12,29,228,1,30,1,30,0,0,31,1,1,3,2,5,3,7,4,9,5,11,
  	6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,0,
  	37,18,39,19,41,0,43,0,45,0,47,20,49,21,51,22,53,23,55,24,57,25,59,26,
  	61,27,1,0,8,1,0,39,39,1,0,48,57,2,0,69,69,101,101,2,0,43,43,45,45,3,0,
  	65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,2,0,10,10,13,13,2,0,9,
  	9,32,32,241,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,
  	0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,
  	21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,
  	0,0,0,0,33,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,
  	0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,
  	61,1,0,0,0,1,63,1,0,0,0,3,67,1,0,0,0,5,71,1,0,0,0,7,78,1,0,0,0,9,86,1,
  	0,0,0,11,94,1,0,0,0,13,102,1,0,0,0,15,134,1,0,0,0,17,136,1,0,0,0,19,138,
  	1,0,0,0,21,140,1,0,0,0,23,142,1,0,0,0,25,144,1,0,0,0,27,146,1,0,0,0,29,
  	148,1,0,0,0,31,157,1,0,0,0,33,160,1,0,0,0,35,165,1,0,0,0,37,168,1,0,0,
  	0,39,173,1,0,0,0,41,179,1,0,0,0,43,182,1,0,0,0,45,186,1,0,0,0,47,192,
  	1,0,0,0,49,196,1,0,0,0,51,203,1,0,0,0,53,213,1,0,0,0,55,219,1,0,0,0,57,
  	221,1,0,0,0,59,226,1,0,0,0,61,230,1,0,0,0,63,64,5,98,0,0,64,65,5,117,
  	0,0,65,66,5,115,0,0,66,2,1,0,0,0,67,68,5,103,0,0,68,69,5,101,0,0,69,70,
  	5,110,0,0,70,4,1,0,0,0,71,72,5,98,0,0,72,73,5,114,0,0,73,74,5,97,0,0,
  	74,75,5,110,0,0,75,76,5,99,0,0,76,77,5,104,0,0,77,6,1,0,0,0,78,79,5,118,
  	0,0,79,80,5,101,0,0,80,81,5,114,0,0,81,82,5,115,0,0,82,83,5,105,0,0,83,
  	84,5,111,0,0,84,85,5,110,0,0,85,8,1,0,0,0,86,87,5,103,0,0,87,88,5,101,
  	0,0,88,89,5,110,0,0,89,90,5,99,0,0,90,91,5,111,0,0,91,92,5,115,0,0,92,
  	93,5,116,0,0,93,10,1,0,0,0,94,95,5,98,0,0,95,96,5,97,0,0,96,97,5,115,
  	0,0,97,98,5,101,0,0,98,99,5,77,0,0,99,100,5,86,0,0,100,101,5,65,0,0,101,
  	12,1,0,0,0,102,103,5,98,0,0,103,104,5,117,0,0,104,105,5,115,0,0,105,106,
  	5,95,0,0,106,107,5,110,0,0,107,108,5,97,0,0,108,109,5,109,0,0,109,110,
  	5,101,0,0,110,14,1,0,0,0,111,112,3,41,20,0,112,113,3,17,8,0,113,115,3,
  	43,21,0,114,116,3,45,22,0,115,114,1,0,0,0,115,116,1,0,0,0,116,135,1,0,
  	0,0,117,118,3,41,20,0,118,119,3,43,21,0,119,120,3,17,8,0,120,121,3,45,
  	22,0,121,135,1,0,0,0,122,123,3,41,20,0,123,132,3,43,21,0,124,129,3,17,
  	8,0,125,127,3,43,21,0,126,128,3,45,22,0,127,126,1,0,0,0,127,128,1,0,0,
  	0,128,130,1,0,0,0,129,125,1,0,0,0,129,130,1,0,0,0,130,133,1,0,0,0,131,
  	133,3,45,22,0,132,124,1,0,0,0,132,131,1,0,0,0,133,135,1,0,0,0,134,111,
  	1,0,0,0,134,117,1,0,0,0,134,122,1,0,0,0,135,16,1,0,0,0,136,137,5,46,0,
  	0,137,18,1,0,0,0,138,139,5,91,0,0,139,20,1,0,0,0,140,141,5,93,0,0,141,
  	22,1,0,0,0,142,143,5,123,0,0,143,24,1,0,0,0,144,145,5,125,0,0,145,26,
  	1,0,0,0,146,147,5,61,0,0,147,28,1,0,0,0,148,149,5,102,0,0,149,150,5,117,
  	0,0,150,151,5,110,0,0,151,152,5,99,0,0,152,153,5,116,0,0,153,154,5,105,
  	0,0,154,155,5,111,0,0,155,156,5,110,0,0,156,30,1,0,0,0,157,158,3,41,20,
  	0,158,159,3,43,21,0,159,32,1,0,0,0,160,161,5,39,0,0,161,34,1,0,0,0,162,
  	164,8,0,0,0,163,162,1,0,0,0,164,167,1,0,0,0,165,163,1,0,0,0,165,166,1,
  	0,0,0,166,36,1,0,0,0,167,165,1,0,0,0,168,169,3,41,20,0,169,170,5,73,0,
  	0,170,171,5,110,0,0,171,172,5,102,0,0,172,38,1,0,0,0,173,174,3,33,16,
  	0,174,175,3,35,17,0,175,176,3,33,16,0,176,177,6,19,0,0,177,40,1,0,0,0,
  	178,180,5,45,0,0,179,178,1,0,0,0,179,180,1,0,0,0,180,42,1,0,0,0,181,183,
  	7,1,0,0,182,181,1,0,0,0,183,184,1,0,0,0,184,182,1,0,0,0,184,185,1,0,0,
  	0,185,44,1,0,0,0,186,188,7,2,0,0,187,189,7,3,0,0,188,187,1,0,0,0,188,
  	189,1,0,0,0,189,190,1,0,0,0,190,191,3,43,21,0,191,46,1,0,0,0,192,193,
  	5,109,0,0,193,194,5,112,0,0,194,195,5,99,0,0,195,48,1,0,0,0,196,200,7,
  	4,0,0,197,199,7,5,0,0,198,197,1,0,0,0,199,202,1,0,0,0,200,198,1,0,0,0,
  	200,201,1,0,0,0,201,50,1,0,0,0,202,200,1,0,0,0,203,207,5,37,0,0,204,206,
  	8,6,0,0,205,204,1,0,0,0,206,209,1,0,0,0,207,205,1,0,0,0,207,208,1,0,0,
  	0,208,210,1,0,0,0,209,207,1,0,0,0,210,211,6,25,1,0,211,52,1,0,0,0,212,
  	214,5,13,0,0,213,212,1,0,0,0,213,214,1,0,0,0,214,215,1,0,0,0,215,216,
  	5,10,0,0,216,217,1,0,0,0,217,218,6,26,1,0,218,54,1,0,0,0,219,220,5,44,
  	0,0,220,56,1,0,0,0,221,222,3,59,29,0,222,223,1,0,0,0,223,224,6,28,1,0,
  	224,58,1,0,0,0,225,227,7,7,0,0,226,225,1,0,0,0,227,228,1,0,0,0,228,226,
  	1,0,0,0,228,229,1,0,0,0,229,60,1,0,0,0,230,231,5,59,0,0,231,62,1,0,0,
  	0,14,0,115,127,129,132,134,165,179,184,188,200,207,213,228,2,1,19,0,6,
  	0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  mpclexerLexerStaticData = staticData.release();
}

}

MpcLexer::MpcLexer(CharStream *input) : Lexer(input) {
  MpcLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *mpclexerLexerStaticData->atn, mpclexerLexerStaticData->decisionToDFA, mpclexerLexerStaticData->sharedContextCache);
}

MpcLexer::~MpcLexer() {
  delete _interpreter;
}

std::string MpcLexer::getGrammarFileName() const {
  return "Mpc.g4";
}

const std::vector<std::string>& MpcLexer::getRuleNames() const {
  return mpclexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& MpcLexer::getChannelNames() const {
  return mpclexerLexerStaticData->channelNames;
}

const std::vector<std::string>& MpcLexer::getModeNames() const {
  return mpclexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& MpcLexer::getVocabulary() const {
  return mpclexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MpcLexer::getSerializedATN() const {
  return mpclexerLexerStaticData->serializedATN;
}

const atn::ATN& MpcLexer::getATN() const {
  return *mpclexerLexerStaticData->atn;
}


void MpcLexer::action(RuleContext *context, size_t ruleIndex, size_t actionIndex) {
  switch (ruleIndex) {
    case 19: STRINGAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

void MpcLexer::STRINGAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 0:  setText(getText().substr(1, getText().length()-2));  break;

  default:
    break;
  }
}



void MpcLexer::initialize() {
  std::call_once(mpclexerLexerOnceFlag, mpclexerLexerInitialize);
}
