#include "Testing.h"

int main()
{
    std::cout << "---TESTING---";

	Testing test;

	test.displayTest();
	test.addingNodesTest();
	test.constructorsTest();
	test.operatorsTest();
	test.deletingNodesTest();
	test.produceTest();

	std::cout << "\n\n---ALL TESTS COMPLETED---\n";
}
