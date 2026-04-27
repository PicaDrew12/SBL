#pragma once
#include<variant>
#include<string>
enum class Type {
	INT,
	FLOAT,
	CHAR,
	STRING
};

class Variable {
public:
	Type type;
	void* dataPointer;
	std::string name;
	int address;
	Variable(Type type, void* dataPointer, std::string name, int address);
};

int registerVariable(Type type, void* dataPointer, std::string name);
//std::variant<int, float, char, std::string> getVariableData(Variable& variable);
std::variant<int*, float*, char*, std::string*> getVariableData(Variable& variable);