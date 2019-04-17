#ifndef UnDirectedGraph_HPP
#define UnDirectedGraph_HPP

#include <stdlib.h>
#include <fstream>
#include <list>
#include <vector>
#include "Vertex.hpp"
#include "Player.hpp"
//#include "Edge.hpp"

using namespace std;

class UnDirectedGraph
{
private:

public:
// The maximum number of vertex for the graph or random graph.

//int SizeOfGraph = 50; // size of graph
vector<Vertex*> listOfVertex;
Player currPlayer;
Player Thanatos;
Player Empty;
int count; // index of all vertex's that are stored in graph

UnDirectedGraph(); // Constructor
UnDirectedGraph(int size); // PreConstructor
~UnDirectedGraph(); // Deconstructor
void addVertex(string label); // creating a new node/vertex and add it to the graph array
void addEdge(string v1, string v2); // makes UnDirected Connections
void addEdgeHelper(string v1, string v2); // Loop through array, find v1 and v2, then in list of v1, add v2
void printGraph();
void exportGraph(); // this will dump the graph for js or css for visualization.
void displayEdges();
void printBFT();
void BFT_traversal(Vertex *v);
void printDFT();
void DFT_traversal(Vertex *v);
Vertex* findVertex(std::string name);
void setAllVerticesUnvisited();
void insertPlayer();
void insertThanatos();
void insertEmpty();
Vertex* playerLocation();
void SetplayerLocation(Vertex* v);
Vertex* checkDistance(Vertex* playerStart);
bool isPlayeronNode(Vertex* v);// first check if player is on the node that empty wants to eat.
bool hasBeenSaved(Vertex* v); // if player has visited this node before
Vertex* BFTempty(Vertex* emptyStart);
Vertex* thanatosLocation();
Vertex* emptyLocation();
void setemptyLocation(Vertex* v);

};
#endif
