#include <string>
#include <vector>
#include "HexGraph.h"
#include "Hex.h"

using namespace std;

int main()
{
	// create hex graph
	HexGraph* h = new HexGraph(10, 10);
	Hex* h1 = h->getHexAt(1, 1);
	Hex* h2 = h->getParentHex()->getPtr(4)->getPtr(3);

	delete h;
}