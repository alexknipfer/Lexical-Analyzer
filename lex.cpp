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

void LexicalAnalyzer::scanFile(ifstream &myFile){
  string currentToken;
  string readLine;
  char lookahead;

    //continue to go through input file line by line
  while(getline(myFile, readLine)){

      //parse line to get tokens
    for(int x = 0; x < readLine.length(); x++){
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
    }
  }
}

  //returns true if argument is a whitespace
bool LexicalAnalyzer::isWhiteSpace(char ch){
  if(ch == ' ' || ch == '\n'){
    return true;
  }
  else{
    return false;
  }
}

  //returns true if argument is a symbol
bool LexicalAnalyzer::isSymbol(char ch){
  if(ch == '(' || ch == ')' || ch == ',' || ch == '{' || ch == '}' || ch == '+' || ch == '-'){
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

  //returns true if argument is a ID
bool LexicalAnalyzer::isID(string currentToken){
  if(isalpha(currentToken[0])){
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

  //returns true if argument is a ADDOP (+ or -)
bool LexicalAnalyzer::isAddOp(string currentToken){
  if(currentToken == "+" || currentToken == "-"){
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
    //checks if token is a ID
  else if(isID(currentToken)){
    cout << "TOKEN:ID                " << currentToken << endl;
  }
}
