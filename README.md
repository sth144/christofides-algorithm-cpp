# cs325projectG24C

Title: CS325 Final Project Group 24  
  
Author: Jeff Herlitz, Ryan Hong, Sean Hinds  
  
Date: 08/16/17  
  
    
Description: C++ implementation of Christofides Algorithm, a Polynomial-time Solution to the Traveling Salesman Problem. The Traveling Salesman problem is a famous NP-complete problem in computer science. It poses the question of: given a set of points in 2 dimensional space, what is the shortest walk which visits each point. Christofides algorithm is the best known approximation for the general traveling salesman problem. Taking advantage of minimum spanning trees and perfect matchings on graphs, this algorithm is guaranteed to return a solution which is longer than the optimal path by a factor of no more than 3/2. It does so in polynomial time, with a published time complexity of T(n) = O(n4).   

The workflow of the algorithm is as follows, for an arbitrary graph G:  

Christofides(G(V, w)):  
Calculate T, a minimum spanning tree on G using Prims algorithm  
Calculate O, a subgraph of the odd-degree vertices in T 		// there are an even number of such  
// vertices, by the Handshake  
// property    
	Calculate M, a minimum-weight perfect matching on O  
	Form a new graph X by combining the edges in M and T		// every vertex now has even degree  
									// we can do an Euler tour  
	Calculate E, an Euler tour around X  
	Remove edges in E which visit previously visited vertices, while still maintaining a path  
	Return E  
  
Our implementation in C++ calculates, in polynomial time, approximations within about 35% of the optimal solution.
  
Code Files: main.cpp tsp.cpp tsp.hpp
  
Dependencies: C++11, command prompt
  
Use Case: Want to determine a reasonably short tour which visits every vertex in a set of vertices. Will not deliver the optimal solution, but will be within a factor of about 1.35
  
Compile command: 'make' on a Linux system (makefile has a default target which executes the command 'g++ main.cpp TSP.cpp -o TSP')  
  
Run command: './TSP \<data filename>'  
  
Output: '\<data filename>.tour', a file which contains the total tour length, followed by the order of nodes visited.  
