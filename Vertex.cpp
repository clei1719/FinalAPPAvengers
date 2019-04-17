#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Vertex.hpp"
// Implimentation of just the Vertex(s)


using namespace std;

Vertex::Vertex() // Constructor
{

}
Vertex::~Vertex()// deconstructor
{

}

Vertex::Vertex(int size) // PreConstructor
{

}
void Vertex::setVisited(bool v)
{
        saved = v;
}
bool Vertex::getVisited()
{
        return saved;
}
void Vertex::printEdges()
{
        // prints all edges
        for(Vertex* i : edges)
        {
                cout << i->label << " ";
        }
        cout << endl;
}
