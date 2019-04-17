#include <iostream>
#include <vector>
#include <stdlib.h>
// Implimentation of just the Vertex(s)
#ifndef Vertex_HPP
#define Vertex_HPP

using namespace std;

class Vertex
{
private:

public:
bool saved; // saved planet
bool visited;
bool dead; // eaten planet
int distance; // Temp distance for random purpose
string label; // for example label a,b,c,d
int SizeOfEdge = 10; // size number of possible connections for a single vertex
vector<Vertex*> edges; //Think of this as the number of connections one node can have.
int count = 0; // index

Vertex(); // Constructor
~Vertex(); // deconstructor
Vertex(int size); // PreConstructor
void setVisited(bool v);
bool getVisited();
void printEdges();
};
#endif
