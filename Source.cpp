#include <string>
#include <vector>
#include "HexGraph.h"
#include "Hex.h"

using namespace std;

int main()
{
	// create hex graph
	HexGraph* h = new HexGraph(10, 10);

	// test routing
	Hex* h1 = h->getHexAt(1, 1);
	Hex* h2 = h->getParentHex()->getPtr(4)->getPtr(3);
	Hex* h3 = h->getParentHex()->getPtr(4)->getPtr(4)->getPtr(4)->getPtr(4)->getPtr(4)->getPtr(4)->getPtr(2)->getPtr(2)->getPtr(2)->getPtr(1)->getPtr(1)->getPtr(5)->getPtr(6)->getPtr(1);

	delete h;
}