#include <iostream>
#include <stdexcept>


int globalVar1{ 0 };

static int accessGlobalVar() {
	return globalVar1;
}

int main() {
	/*
	Integer Literals:
	*/
	std::cout << "Value: " << 123 << "; Size: " << sizeof(123) << std::endl;
	std::cout << "Value: " << 123LL << "; Size: "  << sizeof(123LL) << std::endl;

	/*
	Floating points:
	*/

	// float literal
	float f1{ 1.3f };

	// Assigning a double literal to a float var will lose precision.
	f1 = (2 - std::pow(2, -52)) * std::pow(2, 1023) - 1; // max possible double
	std::cout << "float:" << f1 << std::endl;

	// double literal
	double d1{ 1.4 }; // by default use double
	d1 = (2 - std::pow(2, -52)) * std::pow(2, 1023) - 1;
	std::cout << "double:" << d1 << std::endl;

	// Divisions
	int x1{ 32 };
	int x2{ 127 };
	float percentage_fail = x1 / x2;
	float percentage_success = ((float)x1) / x2; // Make sure at least one is float.
	std::cout 
		<< "Division of two ints: " << std::endl
		<< "Failed: " << percentage_fail << std::endl
		<< "Succeded: " << percentage_success << std::endl;

	/*
	Global & Local Vars
	*/

	// Access global var
	std::cout << "Global Var: " << globalVar1 << std::endl;
	std::cout << "Global Var (Func): " << accessGlobalVar() << std::endl;
	
	// Access local var
	int localVar1{ 0 };
	std::cout << "Local Var (Before): " << localVar1 << std::endl;
	{
		int localVar1{ 123 };
		std::cout << "Local Var (Sub-Field): " << localVar1 << std::endl;
	}
	std::cout << "Local Var (After): " << localVar1 << std::endl;


	/*
	Constants
	*/

	// Run-time constant
	int runtimeConstValue = 10;	// Only knows during runtime.
	const int runtimeConst{ runtimeConstValue };
	std::cout << "Run-time const: " << runtimeConst << std::endl;

	// Compile-time constant
	constexpr int compileTimeConst{ 1 }; // Already knew during compilation.
	std::cout << "Compile-time const: " << compileTimeConst << std::endl;
}