#include "Mide.h"
#include<iostream>

std::unordered_map<std::string, std::unique_ptr<Variable>> variableMap;

std::unordered_map<std::string, std::unique_ptr<int>> intStorage;
std::unordered_map<std::string, std::unique_ptr<float>> floatStorage;
std::unordered_map<std::string, std::unique_ptr<char>> charStorage;
std::unordered_map<std::string, std::unique_ptr<std::string>> stringStorage;
int addressCounter =0;
int currentLineNumber = 0;
void debugPrintVariableMap(){

  std::cout<<"Var map:"<<std::endl;
  for(auto& var : variableMap){
    std::cout<<var.first<<std::endl;
  }
  std::cout<<"END var"<<std::endl;
}
//Variable* getVariable(std::string name) {
//	for (auto var : variables) {
//		if()
//	}
//}
