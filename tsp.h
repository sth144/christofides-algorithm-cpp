#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

#ifndef TSP_H
#define TSP_H

class TSP
{
private:

	// List of odd nodes
	vector<int>odds;

	// Find odd vertices in graph
	void findOdds();

	// Prim helper function
	int getMinIndex(int key[], bool mstSet[]);


protected:


public:
	// Number of cities
	int n;

	// n x n, pairwise distances between cities
	int **graph;

  vector<int>* adjlist;

	// Constructor
	TSP(string in, string out);

	// Destructor
	~TSP();



	// Prim's algorithm
	void findMST();

};

#endif
