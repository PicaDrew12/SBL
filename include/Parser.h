#pragma once
#include<string>
#include <iostream>
#include "Debug.h"
#include "Variable.h"
#include "Mide.h"


//extern int lineIndex;
extern bool continueReading;
enum class ReadingMode {
	Default,
	VariableAssigment
};

//enum class VariableReadState {
//	Null,
//	Type,
//	Name,
//	Value
//};

void parseFile(std::string path);

void parseVariable(std::ifstream* cursorPointer);