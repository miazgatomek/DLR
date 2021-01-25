#include "Testing.h"

void Testing::displayTest() {
	std::cout << "\n\n\tDISPLAYING RING TEST\n";

	std::cout << "\n Displaying ring:";
	DLR<int, int> test(5);
	test.displayRing();

	std::cout << "\n Displaying given nodes (positions: 2, 0, -7):";
	test.displayNode(2);
	test.displayNode(0);
	test.displayNode(-7);

	std::cout << "\n Displaying empty ring:";
	test.clearRing();
	test.displayRing();
}


void Testing::addingNodesTest() {
	std::cout << "\n\n\tADDING NODES TEST\n";

	std::cout << "\n Empty ring after using pushNext, pushPrev:";
	DLR<int, int> test;
	test.pushNext(1, 1);
	test.pushPrev(2, 2);
	test.pushNext(3, 3);
	test.pushPrev(4, 4);
	test.displayRing();

	std::cout << "\n After using createRandomNodes(4)";
	test.createRandomNodes(4);
	test.displayRing();
}


void Testing::constructorsTest() {
	std::cout << "\n\n\tCONSTRUCTORS TESTS\n";

	DLR<int, int> test1(4);
	DLR<int, int> test2(test1);

	std::cout << "\n Using DLR(int) constructor:";
	test1.displayRing();

	std::cout << "\n Using copy constructor:";
	test2.displayRing();
}


void Testing::operatorsTest(){
	std::cout << "\n\n\tOPERATORS TEST\n";

	std::cout << "\n First ring:";
	DLR<int, int> test1(4);
	test1.displayRing();

	std::cout << "\n Second ring:";
	DLR<int, int> test2(3);
	test2.displayRing();

	std::cout << "\n Incremented first ring by second ring:";
	test1 += test2;
	test1.displayRing();

	std::cout << "\n Copied second ring by first ring:";
	test2 = test1;
	test2.displayRing();

	std::cout << "\n Copied first ring by empty ring:";
	test2.clearRing();
	test1 = test2;
	test1.displayRing();
}


void Testing::deletingNodesTest() {
	std::cout << "\n\n\tDELETING TEST\n";

	std::cout << "\n Original ring:";
	DLR<int, int> test(4);
	test.pushNext(1, 1);
	test.pushNext(1, 1);
	test.createRandomNodes(2);
	test.pushNext(1, 1);
	test.displayRing();

	std::cout << "\n Ring after deleteByKey(1):";
	test.deleteByKey(1);
	test.displayRing();

	std::cout << "\n Ring after clearRing()";
	test.clearRing();
	test.displayRing();
}


void Testing::produceTest() {
	std::cout << "\n\n\tPRODUCE FUNCTION TEST\n";

	std::cout << "\n First ring:";
	DLR<int, int> test1;
	test1.pushNext(2, 1);
	test1.pushNext(1, 1);
	test1.pushNext(3, 1);
	test1.displayRing();

	std::cout << "\n Second ring:";
	DLR<int, int> test2;
	test2.pushNext(40,1);
	test2.pushNext(30,1);
	test2.pushNext(20,1);
	test2.pushNext(10,1);
	test2.displayRing();

	std::cout << "\n Produced ring (test1, 1, 2, true, test2, 0, 3, false, 2, true):";
	DLR<int, int> test3;
	test3 = produce(test1, 1, 2, true, test2, 0, 3, false, 2, true);
	test3.displayRing();
}
