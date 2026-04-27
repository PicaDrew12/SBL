#include "Mide.h"


std::unordered_map<std::string, std::unique_ptr<Variable>> variableMap;

std::unordered_map<std::string, std::unique_ptr<int>> intStorage;
std::unordered_map<std::string, std::unique_ptr<float>> floatStorage;
std::unordered_map<std::string, std::unique_ptr<char>> charStorage;
std::unordered_map<std::string, std::unique_ptr<std::string>> stringStorage;
int addressCounter =0;
int currentLineNumber = 0;

//Variable* getVariable(std::string name) {
//	for (auto var : variables) {
//		if()
//	}
//}