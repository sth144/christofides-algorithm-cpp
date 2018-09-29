/*************************************************************************
Title: TSP.hpp
Description: TSP class specification file for our Christofides implementation
Authors: Sean Hinds, Ryan Hong, Jeff Herlitz
Date: 08/16/17

Changes:
- cities coordinates changed from int to double
- removed unused members
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

using namespace std;

#ifndef TSP_H
#define TSP_H

class TSP
{
private:

	struct City{
		double x;
		double y;
	};

	string iFile;
	string oFile;

	// List of odd nodes
	vector<int>odds;

	//Adjacency list
	vector<int> *adjList;

	void findOdds();



protected:


public:
	// Number of cities
	int n;

	//Shortest path length
	int pathLength;

	//euler circuit
	vector<int> circuit;

	vector<City> cities;

	// n x n, pairwise distances between cities
        typedef double distance_t;
	distance_t **graph;
        static distance_t const DINF;

  vector<int>* adjlist;

	// Constructor
	TSP(string in, string out);

	// Destructor
	~TSP();

	distance_t get_distance(struct City c1, struct City c2);

	//Find perfect matching
	void perfectMatching();

	//Find Euler tour
	void euler_tour(int start, vector<int> &path);

	//Find Hamiltonian path
	void make_hamiltonian(vector<int> &path, int &pathCost);

	// Prim's algorithm
	void findMST();

	int getMinIndex(distance_t key[], bool mst[]);

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
