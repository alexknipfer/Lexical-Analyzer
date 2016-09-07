#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "LexicalAnalyzer.h"

using namespace std;

int main(){
  LexicalAnalyzer lexicalAnalyzer;
  ifstream myFile;

  lexicalAnalyzer.getFileName(myFile);
  lexicalAnalyzer.scanFile(myFile);

  return 0;
}

void LexicalAnalyzer::getFileName(ifstream &myFile){
  string fileName;

  cout << "Enter file name: ";

  while(true){
    cin >> fileName;
    myFile.open(fileName);

    if(!myFile){
      cout << "Invalid file name, Please enter a valid file name: ";
    }
    else{
      break;
    }
  }
}

//********************** scanFile **********************************************

void LexicalAnalyzer::scanFile(ifstream &myFile){
  string currentToken;
  string readLine;
  char lookahead;
  string myNumber = "";
  int tempX;

    //continue to go through input file line by line
  while(getline(myFile, readLine)){
      //parse line to get tokens
    for(int x = 0; x < readLine.length(); x++){
      tempX = x;
      lookahead = readLine[x];

      token.push_back(readLine[x]);

        // analyze token since white space is read
      if(isWhiteSpace(lookahead)){
        token.pop_back();
        analyzeToken(token);
        token.clear();
      }

        //analyze token since symbol is read
      else if(isSymbol(lookahead)){
        token.pop_back();
        analyzeToken(token);
        token.clear();
        token.push_back(lookahead);
        analyzeToken(token);
        token.clear();
      }

        //analyze number to see if it is a integer or a part of a string
        //make sure it is a INTEGER
      else if(isdigit(lookahead) && !isalpha(readLine[x-1])){
          //keep getting integer values
        while(isdigit(readLine[x+1])){
          token.push_back(readLine[x+1]);
          x++;
        }
          //add integer to string for printing
        for(int y = 0; y < token.size(); y++){
          myNumber += token[y];
        }
          //print token
        cout << "TOKEN:NUMBER            " << myNumber << endl;
        myNumber = "";
      }

        //if a comment is reached (#), exit loop and don't print line
      else if(isComment(lookahead)){
        token.clear();
        break;
      }

        //check to see if value read in is a RELOP
      else if(isRelop(lookahead)){
        token.pop_back();
        if(isRelop(readLine[x+1])){
          token.push_back(lookahead);
          token.push_back(readLine[x+1]);
          x = x + 2;
          analyzeToken(token);
          token.clear();
        }
        else{
          cout << "TOKEN:ERROR             " << lookahead << endl;
        }
      }

        //check to see if value read is a assignment operator (<-)
      else if(isAssignOp(lookahead)){
        token.pop_back();
        if(isAssignOp(readLine[x+1])){
          token.push_back(lookahead);
          token.push_back(readLine[x+1]);
          x = x + 2;
          analyzeToken(token);
          token.clear();
        }

        else{
          cout << "TOKEN:ERROR               " << currentToken << endl;
        }
      }

    }
  }
}

//******************************************************************************

bool LexicalAnalyzer::isAssignOp(char ch){
  if(ch == '<' || ch == '-'){
    return true;
  }
  else{
    return false;
  }
}

  //returns true if argument is a whitespace
bool LexicalAnalyzer::isWhiteSpace(char ch){
  if(ch == ' ' || ch == '\n' || ch == '\0'){
    return true;
  }
  else{
    return false;
  }
}

  //returns true if argument is a symbol
bool LexicalAnalyzer::isSymbol(char ch){
  if(ch == '(' || ch == ')' || ch == ',' || ch == '{' || ch == '}' || ch == '+' ||
     ch == '-' || ch == '*' || ch == '/' || ch == '&' || ch == '!' || ch == '|' || ch == ';'){
    return true;
  }
  else{
    return false;
  }
}

  //returns true if argument is a character of a RELOP
bool LexicalAnalyzer::isRelop(char ch){
  if(ch == '=' || ch == '!' || ch == '<' || ch == '>'){
    return true;
  }
  else{
    return false;
  }
}

  //returns true if argument is a RELOP
bool LexicalAnalyzer::isRelopString(string currentToken){
  if(currentToken == "==" || currentToken == "!=" || currentToken == "<" ||
          currentToken == ">" || currentToken == "<=" || currentToken == ">="){
      return true;
  }
  else{
      return false;
  }
}

  //returns true if argument is a FUNCTION keyword
bool LexicalAnalyzer::isFunction(string currentToken){
  if(currentToken == "function"){
    return true;
  }
  else{
    return false;
  }
}

  //returns true if argument is a IF keyword
bool LexicalAnalyzer::isIf(string currentToken){
  if(currentToken == "if"){
    return true;
  }
  else{
    return false;
  }
}

  //returns true if argument is a OR symbol
bool LexicalAnalyzer::isOr(string currentToken){
  if(currentToken == "|"){
    return true;
  }
  else{
    return false;
  }
}

  //returns true if argument is a TRUE keyword
bool LexicalAnalyzer::isElse(string currentToken){
  if(currentToken == "else"){
    return true;
  }
  else{
    return false;
  }
}

  //returns true if argument is a NOT symbol
bool LexicalAnalyzer::isNot(string currentToken){
  if(currentToken == "!"){
    return true;
  }
  else{
    return false;
  }
}

  //returns true if argument is a RETURN keyword
bool LexicalAnalyzer::isReturn(string currentToken){
  if(currentToken == "return"){
    return true;
  }
  else{
    return false;
  }
}

  //returns true if argument is a VAR keyword
bool LexicalAnalyzer::isVar(string currentToken){
  if(currentToken == "var"){
    return true;
  }
  else{
    return false;
  }
}

  //returns true if argument is a WHILE keyword
bool LexicalAnalyzer::isWhile(string currentToken){
  if(currentToken == "while"){
    return true;
  }
  else{
    return false;
  }
}

  //returns true if argument is a ID
bool LexicalAnalyzer::isID(string currentToken){
  if(isalpha(currentToken[0]) && currentToken != "if" && currentToken != "function" &&
     currentToken != "else" && currentToken != "return" && currentToken != "var" &&
     currentToken != "while"){
    return true;
  }
  else{
    return false;
  }
}

  //returns true if argument is a left parentesis
bool LexicalAnalyzer::isParenL(string currentToken){
  if(currentToken == "("){
    return true;
  }
  else{
    return false;
  }
}

//returns true if argument is a right parentesis
bool LexicalAnalyzer::isParenR(string currentToken){
  if(currentToken == ")"){
    return true;
  }
  else{
    return false;
  }
}

  //returns true if argument is a left curly brace
bool LexicalAnalyzer::isCurlL(string currentToken){
  if(currentToken == "{"){
    return true;
  }
  else{
    return false;
  }
}

  //returns true if argument is a right curly brace
bool LexicalAnalyzer::isCurlR(string currentToken){
  if(currentToken == "}"){
    return true;
  }
  else{
    return false;
  }
}

  //returns true if argument is a SEMICOLON
bool LexicalAnalyzer::isSemicolon(string currentToken){
  if(currentToken == ";"){
    return true;
  }
  else{
    return false;
  }
}

  //returns true if argument is a ADDOP (+ or -)
bool LexicalAnalyzer::isAddOp(string currentToken){
  if(currentToken == "+" || currentToken == "-"){
    return true;
  }
  else{
    return false;
  }
}

  //returns true if argument is a MULOP (/ or *)
bool LexicalAnalyzer::isMulOp(string currentToken){
  if(currentToken == "/" || currentToken == "*"){
    return true;
  }
  else{
    return false;
  }
}

  //returns true if argument is a comma
bool LexicalAnalyzer::isComma(string currentToken){
  if(currentToken == ","){
    return true;
  }
  else{
    return false;
  }
}

  //returns true if argument is a AND symbol
bool LexicalAnalyzer::isAnd(string currentToken){
  if(currentToken == "&"){
    return true;
  }
  else{
    return false;
  }
}

  //returns true if argument is a ASSIGNMENT operator
bool LexicalAnalyzer::isAssignmentOperator(string currentToken){
  if(currentToken == "<-"){
    return true;
  }
  else{
    return false;
  }
}

  //returns true if a argument is a COMMENT symbol (#)
bool LexicalAnalyzer::isComment(char ch){
  if(ch == '#'){
    return true;
  }
  else{
    return false;
  }
}

  //figures out token type of argument
void LexicalAnalyzer::analyzeToken(vector<char> token){
  string currentToken;
  for(int x = 0; x < token.size(); x++){
    currentToken += token[x];
  }

    //checks if token is a function keyword
  if(isFunction(currentToken)){
    cout << "TOKEN:FUNCTION          " << currentToken << endl;
  }

  else if(isAssignmentOperator(currentToken)){
    cout << "TOKEN:ASSIGNOP          " << currentToken << endl;
  }

    //checks if token is a if keyword
  else if(isIf(currentToken)){
    cout << "TOKEN:IF                " << currentToken << endl;
  }

    //checks if token is a else keyword
  else if(isElse(currentToken)){
    cout << "TOKEN:ELSE              " << currentToken << endl;
  }

    //checks if token is a return keyword
  else if(isReturn(currentToken)){
    cout << "TOKEN:RETURN            " << currentToken << endl;
  }

    //checks if token is a not symbol
  else if(isNot(currentToken)){
    cout << "TOKEN:NOT               " << currentToken << endl;
  }

    //checks if token is a or keyword
  else if(isOr(currentToken)){
    cout << "TOKEN:OR                " << currentToken << endl;
  }

    //checks if token is a VAR keyword
  else if(isVar(currentToken)){
    cout << "TOKEN:VAR               " << currentToken << endl;
  }

    //checks if token is a WHILE keyword
  else if(isWhile(currentToken)){
    cout << "TOKEN:WHILE             " << currentToken << endl;
  }

  //checks if token is a semicolon
  else if(isSemicolon(currentToken)){
    cout << "TOKEN:SEMICOLON         " << currentToken << endl;
  }

    //checks if token is a left parentesis
  else if(isParenL(currentToken)){
    cout << "TOKEN:PARENL            " << currentToken << endl;
  }

  else if(isParenR(currentToken)){
    cout << "TOKEN:PARENR            " << currentToken << endl;
  }

    //checks if token is a comma
  else if(isComma(currentToken)){
    cout << "TOKEN:COMMA             " << currentToken << endl;
  }

    //checks if token is left curly
  else if(isCurlL(currentToken)){
    cout << "TOKEN:CURLL             " << currentToken << endl;
  }

    //checks if token is right curly
  else if(isCurlR(currentToken)){
    cout << "TOKEN:CURLR             " << currentToken << endl;
  }

    //checks if token is a ADDOP (+ or -)
  else if(isAddOp(currentToken)){
    cout << "TOKEN:ADDOP             " << currentToken << endl;
  }

    //checks if token is a MULLOP (/ or *)
  else if(isMulOp(currentToken)){
    cout << "TOKEN:MULOP             " << currentToken << endl;
  }

    //checks if token is an AND
  else if(isAnd(currentToken)){
    cout << "TOKEN:AND               " << currentToken << endl;
  }

    //checks if token is a RELOP
  else if(isRelopString(currentToken)){
    cout << "TOKEN:RELOP             " << currentToken << endl;
  }

    //checks if token is a ID
  else if(isID(currentToken)){
    cout << "TOKEN:ID                " << currentToken << endl;
  }

}
