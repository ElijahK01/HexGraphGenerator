#include "HexGraph.h"
#include "Hex.h"
#include <vector>

using namespace std;

int width;
int height;

Hex* parentHex;
vector<Hex*> hexList;

HexGraph::HexGraph() : width(0), height(0){}

HexGraph::HexGraph(int width, int height) : width(width), height(height)
{
	this->GenerateGraph();
}

void HexGraph::GenerateGraph() 
{
	Hex firstHex = Hex();
	this->parentHex = &firstHex;
	hexList.push_back(&firstHex);

	// create vertical col of hexes
	for (int i = 1; i < height; i++)
	{
		this->createHex(4, (Hex*)hexList.at(hexList.size() - 1));
	}
}
void HexGraph::SetDimensions(int width, int height)
{
	this->width = width;
	this->height = height;
}

Hex* HexGraph::returnHexRelative(Hex* base, vector<int> path)
{
	Hex* currentPtr = base;

	for (int i = (int)path.size(); i < 0; i--)
	{
		currentPtr = currentPtr->getPtr(path.at(i));
	}

	return currentPtr;
}

Hex* HexGraph::returnHexAbsolute(vector<int> path)
{
	return returnHexRelative(parentHex, path);
}

void HexGraph::createHex(int dir, Hex* parentPtr)
{
	Hex parent = *parentPtr;
	Hex child = Hex();

	hexList.push_back(&child);

	parent.setPtr(dir, &child);
	
	// set direction to opposite (hexagon = 6  sides, 1/2 of 6 is 3)
	if (dir - 3 > 0)
	{
		dir -= 3;
	}
	else
	{
		dir += 3;
	}

	child.setPtr(dir, &parent);
}
