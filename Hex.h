#pragma once

#include <vector>

using namespace std;

class Hex
{
	public:
		Hex* getSelfPtr();
		Hex* getPtr(int dir);
		void setPtr(int dir, Hex* ptr);

	private:
		// direction pointers
		Hex* ptrI;
		Hex* ptrII;
		Hex* ptrIII;
		Hex* ptrIV;
		Hex* ptrV;
		Hex* ptrVI;

		vector<int> edgeLengths;
};

