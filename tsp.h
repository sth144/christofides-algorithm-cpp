/*************************************************************************
Title: TSP.hpp
Description: TSP class specification file for our Christofides implementation
Authors: Sean Hinds, Ryan Hong, Jeff Herlitz
Date: 08/16/17
*************************************************************************/

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
#include <limits>

using namespace std;

#ifndef TSP_H
#define TSP_H

class TSP
{
private:

	struct City{
		int x;
		int y;
	};

	string iFile;
	string oFile;

	// List of odd nodes
	vector<int>odds;

	//Smaller cost matrix to find minimum matching on odd nodes
	int **cost;

	//Adjacency list
	vector<int> *adjList;

	void findOdds();



protected:


public:
	// Number of cities
	int n;

	//path
	int **path_vals;

	//Shortest path length
	int pathLength;

	//euler circuit
	vector<int> circuit;

	vector<City> cities;

	// n x n, pairwise distances between cities
	int **graph;

  vector<int>* adjlist;

	// Constructor
	TSP(string in, string out);

	// Destructor
	~TSP();

	int get_distance(struct City c1, struct City c2);

	//Find perfect matching
	void perfectMatching();

	//Find Euler tour
	void euler_tour(int start, vector<int> &path);

	//Find Hamiltonian path
	void make_hamiltonian(vector<int> &path, int &pathCost);

	// Prim's algorithm
	void findMST();

	int getMinIndex(int key[], bool mst[]);

	void printResult();
	void printPath();
	void printEuler();
	void printAdjList();
	void printCities();

	int get_size(){return n;};

	void fillMatrix();

	int findBestPath(int start);

};

#endif
