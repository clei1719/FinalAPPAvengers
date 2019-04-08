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
bool visited;
Vertex *v;
int weight;
string label; // for example label a,b,c,d
int SizeOfEdge = 10; // size number of possible connections for a single vertex
vector<Vertex*> edges; //Think of this as the number of connections one node can have.
int count = 0;
Vertex() // Constructor
{

}
~Vertex()
{

}

Vertex(int size) // PreConstructor
{

}
void setVisited(bool v)
{
        visited = v;
}
bool getVisited()
{
        return visited;
}
void printEdges()
{
        // prints all edges
        for(Vertex* i : edges)
        {
                cout << i->label << " ";
        }
        cout << endl;
}
};
#endif
