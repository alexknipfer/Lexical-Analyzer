#include <string>
#include <iostream>
#include <vector>

using namespace std;

class LexicalAnalyzer{
  public:
    void getFileName(ifstream &);
    void scanFile(ifstream &);
    void analyzeToken(vector<char>);
    bool isFunction(string);
    bool isIf(string);
    bool isElse(string);
    bool isReturn(string);
    bool isNot(string);
    bool isOr(string);
    bool isSemicolon(string);
    bool isVar(string);
    bool isWhile(string);
    bool isWhiteSpace(char);
    bool isSymbol(char);
    bool isAssignOp(char);
    bool isAssignmentOperator(string);
    bool isParenL(string);
    bool isParenR(string);
    bool isCurlL(string);
    bool isCurlR(string);
    bool isAddOp(string);
    bool isMulOp(string);
    bool isComma(string);
    bool isID(string);
    bool isAnd(string);

  private:
    vector<char> token;
};
