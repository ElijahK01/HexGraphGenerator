#pragma once
#include "Hex.h"

class HexGraph
{
public:
	HexGraph();
	HexGraph(int width, int height);
	void GenerateGraph();
	void SetDimensions(int width, int height);

private:
	unsigned int width;
	unsigned int height;
	Hex* parentHex;
	vector<Hex*> hexList;

	Hex* returnHexRelative(Hex* base, vector<int> path);	// returns hex from base following path
	Hex* returnHexAbsolute(vector<int> path);				// returns hax from parent hex following path
	void createHex(int dir, Hex* parentPtr);
};

