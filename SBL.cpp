// SBL.cpp : Defines the entry point for the application.
//

#include "SBL.h"
#include "Variable.h"
#include "Parser.h"
#include "Mide.h"
using namespace std;

void test() {
	/*for (auto& var : variableMap) {
		Variable* var2 = var.second.get();
		int* value = static_cast<int*>(var2->dataPointer);
		std::cout << var2->name << " " << *value<<std::endl;
	}*/
}

int main()
{
	//Debug::Error(69,"\n");
	parseFile("code.sbl");
	test();
	return 0;
}
