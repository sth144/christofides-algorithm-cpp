#include <iostream>
#include <climits>
#include "tsp.h"
#include "twoOpt.h"

int main(int argc, char** argv) {

	// Read file names from input
	string input, output;
	input = output = argv[1];
	output.append(".tour");

	// Create new tsp object
	TSP tsp(input, output);
	int tsp_size = tsp.get_size();

	int bestIndex;
	int best;

	// Fill N x N matrix with distances between nodes
	tsp.fillMatrix_threads();

	// Find a MST T in graph G
	tsp.findMST();

	// Find a minimum weighted matching M for odd vertices in T
	tsp.perfectMatching();

	

	// Loop through each index and find shortest path
	for (long t = 0; t < tsp_size; t++) {
		int result = tsp->find_best_path(t);

		tsp->path_vals[t][0] = t; // set start
		tsp->path_vals[t][1] = result; // set end

		if (tsp.path_vals[t][1] < best) {
			bestIndex = tsp.path_vals[t][0];
			best = tsp.path_vals[t][1];
		}
	}

	// Store best path
	tsp.create_tour(bestIndex);

	// Print to file
	tsp.printResult();

}