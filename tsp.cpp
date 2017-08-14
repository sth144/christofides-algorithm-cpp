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

void TSP::perfectMatching() {
  /************************************************************************************
   find a perfect matching M in the subgraph O using greedy algorithm but not minimum
  *************************************************************************************/
  int closest, length; //int d;
  std::vector<int>::iterator tmp, first;

  // Find nodes with odd degrees in T to get subgraph O
  findOdds();

  // for each odd node
  while (!odds.empty()) {
    first = odds.begin();
    vector<int>::iterator it = odds.begin() + 1;
    vector<int>::iterator end = odds.end();
    length = std::numeric_limits<int>::max();
    for (; it != end; ++it) {
      // if this node is closer than the current closest, update closest and length
      if (graph[*first][*it] < length) {
        length = graph[*first][*it];
        closest = *it;
        tmp = it;
      }
    } // two nodes are matched, end of list reached
    adjlist[*first].push_back(closest);
    adjlist[closest].push_back(*first);
    odds.erase(tmp);
    odds.erase(first);
  }
}



void TSP::printResult(){
  ofstream outputStream;
  outputStream.open(outFname.c_str(), ios::out);
  outputStream << pathLength << endl;
  for (vector<int>::iterator it = circuit.begin(); it != circuit.end(); ++it) {
    outputStream << *it << endl;
  }
  outputStream.close();
};

void TSP::printPath(){
  cout << endl;
  for (vector<int>::iterator it = circuit.begin(); it != circuit.end()-1; ++it) {
    cout << *it << " to " << *(it+1) << " ";
    cout << graph[*it][*(it+1)] << endl;
  }
  cout << *(circuit.end()-1) << " to " << circuit.front();
  cout << "\nLength: " << pathLength << endl << endl;
};

void TSP::printEuler() {
  for (vector<int>::iterator it = circuit.begin(); it != circuit.end(); ++it)
    cout << *it << endl;
}

void TSP::printAdjList() {
  for (int i = 0; i < n; i++) {
    cout << i << ": "; //print which vertex's edge list follows
    for (int j = 0; j < (int)adjlist[i].size(); j++) {
      cout << adjlist[i][j] << " "; //print each item in edge list
    }
    cout << endl;
  }
};

void TSP::printCities(){
  cout << endl;
  int i = 0;
  for (vector<City>::iterator it = cities.begin(); it != cities.end(); ++it)
    cout << i++ << ":  " << it->x << " " << it->y << endl;
}
