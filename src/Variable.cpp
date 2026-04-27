#include "Variable.h"
#include "Mide.h"
Variable::Variable(Type type, void* dataPointer, std::string name,int address) {
	this->type = type;
	this->dataPointer = dataPointer;
	this->name = name;
	this->address = address;
}

int registerVariable(Type type, void* dataPointer, std::string name) {
	variableMap[name] = std::make_unique<Variable>(type, dataPointer, name, addressCounter);
	return 0;
}

std::variant<int*, float*, char*, std::string*> getVariableData(Variable& variable) {
	std::variant<int*, float*, char*, std::string*> var;
	if (variable.type == Type::INT) {
		var = static_cast<int*>(variable.dataPointer);
	}
	if (variable.type == Type::FLOAT) {
		var = static_cast<float*>(variable.dataPointer);
	}
	if (variable.type == Type::CHAR) {
		var = static_cast<char*>(variable.dataPointer);
	}
	if (variable.type == Type::STRING) {
		var = static_cast<std::string*>(variable.dataPointer);

	}

	return var;
	
}