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
    bool isWhiteSpace(char);
    bool isSymbol(char);
    bool isParenL(string);
    bool isComma(string);

  private:
    vector<char> token;
};
