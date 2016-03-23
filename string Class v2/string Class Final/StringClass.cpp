#include "strings.h"
#include <iostream>
int main()
{
	String jeff = "jeff";
	String anotherString = "ITS JHONNY BOY";
	std::cout << jeff.Length() << std::endl;
	std::cout << jeff[2] << std::endl;
	if (jeff == "jef") {
		std::cout << "true" << std::endl;
	}
	else {
		std::cout << "false" << std::endl;
	}
	std::cout << jeff << std::endl;
	jeff = anotherString;
	std::cout << jeff << std::endl;
	jeff = jeff.toLower();
	std::cout << jeff << std::endl;
	jeff = jeff.toUpper();
	std::cout << jeff << std::endl;
	jeff = jeff.toLower();
	jeff.subStringReplace("jhonny", "PERFECT");
	std::cout << jeff << std::endl;
	jeff += "hi";
	jeff = jeff + anotherString + jeff + anotherString + "is long" + jeff;
	jeff = jeff.toLower();
	std::cout << jeff << std::endl;
	jeff.subStringReplace("jhonny", "NOPE");
	jeff.subStringReplace("jhonny", "NOPE");
	jeff.subStringReplace("NOPE", "jhonny");
	std::cout << jeff << std::endl;
	return 0;
}

