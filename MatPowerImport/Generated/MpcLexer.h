
// Generated from D:\source\repos\MatPowerImport\MatPowerImport\Mpc.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  MpcLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    FLOAT = 8, DOT = 9, LBS = 10, RBS = 11, LCB = 12, RCB = 13, LET = 14, 
    FUNCTION = 15, INTEGER = 16, SQUOTE = 17, INF = 18, STRING = 19, MPC = 20, 
    VARIABLE = 21, LINE_COMMENT = 22, NEWLINE = 23, COMMA = 24, WSK = 25, 
    WS = 26, SEMI = 27
  };

  explicit MpcLexer(antlr4::CharStream *input);

  ~MpcLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.
  void STRINGAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.

};

