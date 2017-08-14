#include "tsp.h"


/******************************************************************************
  This function uses Prim's algorithm to determine a minimum spanning tree on
    the graph
******************************************************************************/

void TSP::findMST() {

  int key[n];
  bool included[n];
  int parent[n];

  for (int i = 0; i < n; i++) {

    // set each key to infinity
    key[i] = std::numeric_limits<int>::max();

    // node node yet included in MST
    included[i] = false;

  }

  // root of MST has distance of 0 and no parent
  key[0] = 0;
  parent[0] = -1;

  for (int i = 0; i < n - 1; i++) {

    // find closes vertex not already in tree
    int k = getMinIndex(key, included);

    // set included to true for this vertex
    included[k] = true;

    // examine each unexamined vertex adjacent to most recently added
    for (int j = 0; j < n; j++) {

      // node exists, is unexamined, and graph[k][j] less than previous
      // key for u
      if (graph[k][j] && included[j] == false && graph[k][j] < key[j]) {

          // update parent
          parent[j] = k;

          // update key
          key[j] = graph[k][j];

      }
    }

  }

  // construct a tree by forming adjacency matrices
  for (int i = 0; i < n; i++) {

    int j = parent[i];

    if (j != -1) {

      adjlist[i].push_back(j);
      adjlist[j].push_back(i);

    }

  }

}


/******************************************************************************
  find the index of the closest unexamined node
******************************************************************************/

int TSP::getMinIndex(int key[], bool mst[]) {

  // initialize min and min_index
  int min = std::numeric_limits<int>::max();
  int min_index;

  // iterate through each vertex
  for (int i = 0; i < n; i++) {

    // if vertex hasn't been visited and has a smaller key than min
    if (mst[i] == false && key[i] < min) {

      // reassign min and min_index to the values from this node
      min = key[i];
      min_index = i;

    }

  }

  return min_index;

}


/******************************************************************************
  find all vertices of odd degree in the MST. Store them in an subgraph O
******************************************************************************/

void TSP::findOdds() {

  for (int i = 0; i < n; i++) {

    // if degree of vertex i is odd
    if ((adjlist[i].size() % 2) != 0) {

      // push vertex to odds, which is a representation of subgraph O
      odds.push_back(i);

    }

  }

}
