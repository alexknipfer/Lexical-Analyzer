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
