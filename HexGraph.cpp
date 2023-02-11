#include "HexGraph.h"
#include "Hex.h"
#include <vector>
#include <iostream>
#include <string>

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
	Hex* firstHex = new Hex();
	this->parentHex = firstHex;
	hexList.push_back(firstHex);

	Hex* currentHex = firstHex;
	Hex* prevHex = firstHex;
	Hex* colHeaderHex = firstHex;

	// create vertical col of hexes
	for (int i = 1; i < height; i++)
	{
		currentHex->setPtr(4, new Hex());
		currentHex->getPtr(4)->setPtr(1, currentHex);

		currentHex = currentHex->getPtr(4);
	}

	currentHex = firstHex;
	

	// go through columns adding adjacent hex
	while (currentHex)
	{
		cout << "At Hex " << currentHex << endl;

		currentHex->setPtr(firstLinkDir(1), new Hex());									// set first link direction
		currentHex->getPtr(firstLinkDir(1))->setPtr(firstLinkDir(1) + 3, currentHex);	// set link back

		prevHex = currentHex;
		currentHex = currentHex->getPtr(4);
	}

	// add second adj link to node (reverse direction)
	currentHex = colHeaderHex;
	while (currentHex->getPtr(4))
	{
		cout << "At Hex " << currentHex << endl;

		pair<int, int> p = secondLinkDirs(1);
		currentHex->getPtr(p.first)->setPtr(5, currentHex->getPtr(p.second)); // link second step
		currentHex->getPtr(p.second)->setPtr(2, currentHex->getPtr(p.first));

		prevHex = currentHex;
		currentHex = currentHex->getPtr(4);
	}
	
	currentHex = colHeaderHex->getPtr(4); // col dependant

	while (currentHex)
	{
		currentHex->getPtr(2)->setPtr(4, currentHex->getPtr(3));
		currentHex->getPtr(3)->setPtr(1, currentHex->getPtr(2));

		currentHex = currentHex->getPtr(4);
	}

	// works for 1 column
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

int HexGraph::firstLinkDir(int colNum)
{
	if (colNum % 2 == 1)
		return 3;
	else
		return 2;
}

pair<int, int> HexGraph::secondLinkDirs(int colNum)
{
	if (colNum % 2 == 1)
		return make_pair(3, 4);
	else
		return make_pair(2, 1);
}

int HexGraph::nextNodeDir(int colNum)
{
	if (colNum % 2 == 1)
		return 4;
	else
		return 1;
}
