#include "Parser.h"
#include "fstream"
#include <sstream>
#include <regex>


ReadingMode currentMode;
//int lineIndex = 0;
bool continueReading = true;

void Abort() {
	continueReading = false;
	std::cout << "Interpreter exited" << std::endl;
}

bool isValidVariableName(std::string& name) {
	std::regex pattern(R"(^[A-Za-z][A-Za-z0-9]*$)");
	return std::regex_match(name, pattern);
}

bool doesVariableExist(std::string variableName) {
	auto it = variableMap.find(variableName);
	if (it == variableMap.end()) {
    Debug::Error("Variable ", variableName, "dosen't exist" );
		return false;
	}
	else {
  return		true;
	}
}

void parseVariable(std::istringstream* cursorPointer) {
	std::string typeName;
	std::string variableName;
	Type type;
	void* dataPointer;
	*cursorPointer >> typeName;
	*cursorPointer >> variableName;
	if (!isValidVariableName(variableName))
		Debug::Error("Variable name '", variableName, "' is not valid");
	char isEqual;
	*cursorPointer >>isEqual;
	if (isEqual != '=') {
		std::cout << "NO equal";
	}
	if (typeName == "int") {
		int interger;
		*cursorPointer >> interger;
		type = Type::INT;
		intStorage[variableName] = std::make_unique<int>(interger);
		dataPointer = intStorage[variableName].get();
		int code = registerVariable(type, dataPointer, variableName);
  //  std::cout<<code<<" Asta e "<<std::endl;

	}
	else if (typeName == "float") {
		type = Type::FLOAT;
		float value;
		*cursorPointer >> value;
		floatStorage[variableName] = std::make_unique<float>(value);
		dataPointer = floatStorage[variableName].get();
		registerVariable(type, dataPointer, variableName);
	}
	else if (typeName == "char") {
		type = Type::CHAR;
		char value;
		*cursorPointer >> value;
		charStorage[variableName] = std::make_unique<char>(value);
		dataPointer = charStorage[variableName].get();
		registerVariable(type, dataPointer, variableName);
		
	}
	else if (typeName == "string") {
		type = Type::STRING;
	}
	
	
}


void parseVariableAssignment(std::istringstream* cursorPointer) {
	std::string variableName;
	*cursorPointer >> variableName;
	auto it = variableMap.find(variableName);
	if (doesVariableExist(variableName)) {
		char isEqual;
		*cursorPointer >> isEqual;
		if (isEqual != '=') {
			std::cout << "NO equal";
		}
		else {
			Variable& var= *it->second.get();
			std::string data;
			std::stringstream ss(data);
			if (doesVariableExist(data)) {
				Variable* var = variableMap[data].get();
				Variable* other = variableMap[data].get();
				if (var->type != other->type)
					Debug::Error("Type mismatch at asigment ", var->name, " : ", other->name);

			}
			else {
				if (var.type == Type::INT) {
					int value;
					ss >> value;

					intStorage[variableName] = std::make_unique<int>(value);
					var.dataPointer = intStorage[variableName].get();

				}
				if (var.type == Type::FLOAT) {
					float value;
					ss >> value;
					floatStorage[variableName] = std::make_unique<float>(value);
					var.dataPointer = floatStorage[variableName].get();

				}
				if (var.type == Type::CHAR) {
					std::string value;
					ss >> value;
					if(value[0] == '\'' && value[value.size() -1] == '\'')
					//*cursorPointer >> value;
					charStorage[variableName] = std::make_unique<char>(value[1]);
					var.dataPointer = charStorage[variableName].get();

				}
			}
			

			
		}
	}
	else {
		//std::cout << "ERROR" << "VARIABLE NOT FOUND";
		Debug::Error("Variable ", variableName, " dosen't exist");
		Abort();
	}
}


void handlePrint(std::istringstream* cursorPointer) {
	std::string token;
	while (*cursorPointer >> token) {
		if (doesVariableExist(token)) {
			auto value = getVariableData(*variableMap[token]);
			std::visit([](auto&& val) {
				std::cout << *val;
				}, value);
		}
    else if(token[0]=='\"'){
      std::cout<<"Opa";
    }
    else{
      
    }
	}
}

void parseFile(std::string path) {
	currentMode = ReadingMode::Default;
	std::ifstream file(path);
	std::string line;
	while (std::getline(file, line)) {
		if (continueReading) {
			std::istringstream cursor(line);
			std::string token;
			cursor >> token;
			if (currentMode == ReadingMode::Default) {
				if (token == "var") {
					parseVariable(&cursor);

				}
				else if (token == "set") {
					parseVariableAssignment(&cursor);

				}
				else if (token == "print") {
					handlePrint(&cursor);
				}
        else if(token == "" || token == " "){
          continue;
        }
				else {
					Debug::Error("Token ", token, " is not recognized");
					Abort();
				}
			}

			currentLineNumber++;
		}
		

	}
}
