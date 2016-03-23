#include "strings.h"
#include <fstream>

void testCase(bool Expression, char* testName, float& successNum, float& failNum, std::ofstream& output) {

	if (Expression)
	{
		successNum++;
		output << "Test " << successNum + failNum << "\t" << testName << "\t" << "Success\n";
	}
	else {
		failNum++;
		output << "Test " << successNum + failNum << "\t" << testName << "\t" << "Fail\n";
	}

}
int main()
{
	std::ofstream output;
	output.open("testResults.txt", std::ofstream::out | std::ofstream::app);
	String jeff = "jeff";
	String anotherString = "johhny";
	float successNum = 0.0f;
	float failNum = 0.0f;
	testCase(strcmp(jeff, "jeff") == 0, "Base Constructor\t", successNum, failNum, output);
	testCase(jeff == "jeff", "operator == (TRUE)\t", successNum, failNum, output);
	testCase(!(jeff == "JEFFRY"), "operator == (FALSE)\t", successNum, failNum, output);
	testCase(jeff.Length() == 4, "Length\t\t\t", successNum, failNum, output);
	testCase(*jeff[0] == 'j', "char at positon\t\t", successNum, failNum, output);
	jeff = anotherString;
	testCase(jeff == "johhny", "operator =(string)\t", successNum, failNum, output);
	jeff = "jeff";
	testCase(jeff == "jeff", "operator =(cstring)\t", successNum, failNum, output);
	jeff = jeff.toUpper();
	testCase(jeff == "JEFF", "to uppercase\t\t", successNum, failNum, output);
	jeff = jeff.toLower();
	testCase(jeff == "jeff", "to lowercase\t\t", successNum, failNum, output);
	testCase(jeff.subStringFind("eff") != nullptr, "substring find(success)\t", successNum, failNum, output);
	testCase(jeff.subStringFind("ricky") == nullptr, "substring find(fail)\t", successNum, failNum, output);
	testCase(jeff.subStringFind("eff", 1) != nullptr, "substring find(index success)", successNum, failNum, output);
	testCase(jeff.subStringFind("jeff", 1) == nullptr, "substring find(index fail)", successNum, failNum, output);
	jeff.subStringReplace("eff", "offrey");
	testCase(jeff == "joffrey", "substring replace(success)", successNum, failNum, output);
	jeff.subStringReplace("ricky", "jeffry");
	testCase(jeff == "joffrey", "substring replace(fail)\t", successNum, failNum, output);
	jeff = "je";
	jeff = jeff + "ff7 the remake";
	testCase(jeff == "jeff7 the remake", "append(+, +=) \t\t", successNum, failNum, output);
	jeff = "this is " + jeff;
	testCase(jeff == "this is jeff", "prepend cstring\t\t", successNum, failNum, output);
	jeff = "jeff";
	output << "Successful " << (successNum / (successNum + failNum)) * (float)100 << "%\n\n";
	output.close();
	for (int i = 0; i < 100000000; ++i) {
		String test;
	}
	*jeff[0] = *anotherString[0];
	return 0;
}