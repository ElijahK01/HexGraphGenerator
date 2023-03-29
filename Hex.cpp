#include "Hex.h"
#include <vector>

using namespace std;

Hex* ptrI;   // up
Hex* ptrII;  // up right
Hex* ptrIII; // down right
Hex* ptrIV;  // down
Hex* ptrV;   // down left
Hex* ptrVI;  // up left

vector<int> edgeLengths;

Hex* Hex::getSelfPtr()
{
	return this;
}

Hex* Hex::getPtr(int dir)
{
	switch (dir)
	{
	case 1:
		return ptrI;
	case 2:
		return ptrII;
	case 3:
		return ptrIII;
	case 4:
		return ptrIV;
	case 5:
		return ptrV;
	case 6:
		return ptrVI;
	default:
		return nullptr;
	}
}

void Hex::setPtr(int dir, Hex* ptr)
{
	switch (dir)
	{
	case 1:
		ptrI = ptr;
		break;
	case 2:
		ptrII = ptr;
		break;
	case 3:
		ptrIII = ptr;
		break;
	case 4:
		ptrIV = ptr;
		break;
	case 5:
		ptrV = ptr;
		break;
	case 6:
		ptrVI = ptr;
		break;
	}
}
