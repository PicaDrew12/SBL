#pragma once
#include "Variable.h"
#include <vector>
#include <unordered_map>
#include<memory>


extern std::unordered_map<std::string, std::unique_ptr<Variable>> variableMap;
extern std::unordered_map<std::string, std::unique_ptr<int>> intStorage;
extern std::unordered_map<std::string, std::unique_ptr<float>> floatStorage;
extern std::unordered_map<std::string, std::unique_ptr<char>> charStorage;
extern std::unordered_map<std::string, std::unique_ptr<std::string>> stringStorage;
extern int addressCounter;
extern int currentLineNumber;

//Variable* getVariable(std::string name);
