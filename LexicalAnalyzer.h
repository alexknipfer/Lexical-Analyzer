#include <string>
#include <iostream>
#include <vector>

using namespace std;

class LexicalAnalyzer{
  public:
    void getFileName(ifstream &);
    void initiateValidTokens();
    void scanFile(ifstream &);

  private:
    vector<string> tokenNames;
    vector<string> tokenDescriptions;
};
