#pragma once
#include<iostream>
#include "Mide.h"
namespace Debug {

	template<typename T>
	void printLine(T arg) {
		std::cout << arg;
	}

	template<typename T, typename... Args>
	void printLine(T arg, Args... rest) {
		std::cout << arg;
		printLine(rest...);
	}


	template<typename T>
	void Error(T arg) {
		std::cout << "\033[31m";
		std::cout<<"ERROR["<<currentLineNumber<<"]: " << arg<<std::endl;
		std::cout << "\033[0m";
	}

	template<typename T, typename... Args>
	void Error(T arg, Args... rest) {
		std::cout << "\033[31m";
		std::cout << "ERROR[" << currentLineNumber << "]: " << arg;
		printLine(rest...);
		std::cout << "\033[0m";
		std::cout << std::endl;
	}
}