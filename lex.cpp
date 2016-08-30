#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "LexicalAnalyzer.h"

using namespace std;

int main(){
  LexicalAnalyzer lexicalAnalyzer;
  ifstream myFile;
  string token;

  lexicalAnalyzer.getFileName(myFile);
  //lexicalAnalyzer.initiateValidTokens();
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
  string readLine;
  getline(myFile, readLine);
}

void LexicalAnalyzer::initiateValidTokens(){
  tokenNames.push_back("ADDOP");
  tokenNames.push_back("ADDOP");
  tokenNames.push_back("AND");
  tokenNames.push_back("ASSIGNOP");
  tokenNames.push_back("COMMA");
  tokenNames.push_back("CURLL");
  tokenNames.push_back("CURLR");
  tokenNames.push_back("ELSE");
  tokenNames.push_back("FUNCTION");
  tokenNames.push_back("ID");
  tokenNames.push_back("IF");
  tokenNames.push_back("MULOP");
  tokenNames.push_back("MULOP");
  tokenNames.push_back("NOT");
  tokenNames.push_back("NUMBER");
  tokenNames.push_back("OR");
  tokenNames.push_back("PARENL");
  tokenNames.push_back("PARENR");
  tokenNames.push_back("RELOP");
  tokenNames.push_back("RELOP");
  tokenNames.push_back("RELOP");
  tokenNames.push_back("RELOP");
  tokenNames.push_back("RELOP");
  tokenNames.push_back("RELOP");
  tokenNames.push_back("RETURN");
  tokenNames.push_back("SEMICOLON");
  tokenNames.push_back("STRING");
  tokenNames.push_back("VAR");
  tokenNames.push_back("WHILE");

  for(int x = 0; x < tokenNames.size(); x++){
    cout << tokenNames[x] << endl;
  }
}
