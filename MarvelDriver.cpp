//Load standard Libraries
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <time.h>
//Load class files
#include "Vertex.hpp"
#include "DirectedGraph.hpp"
#include "UnDirectedGraph.hpp"

//************************************************************************************************************
//FUNCTIONS GO HERE:


//FUNCTIONS END
//************************************************************************************************************

//************************************************************************************************************
//MAIN GOES HERE:
int main(int argc, char *argv[])
{
        srand(time(0)); //seeds random
        //DirectedGraph g(50); // creates an object of graph
        UnDirectedGraph graph(25);
        int numOfVertex = rand() % 25 + 10; // random num generator of size of graph.
        for(int i = 0; i < numOfVertex; i++) // creates the graph with vertexs
        {
                string s; // we may need to randomize vertex labels (perhaps a list of planets)
                graph.addVertex(to_string(i)); // adds vertexs up to the numnber that we want
        }
        for(int j = 0; j < numOfVertex*2; j++)
        {
                int v1, v2;
                do // while v1 and v2 equal each other re-roll , prevents vertexs from pointing to themselves.
                {
                        v1=rand()%numOfVertex+1;
                        v2=rand()%numOfVertex+1;
                }
                while(v1 == v2);

                graph.addEdge(to_string(v1),to_string(v2));
        }
        graph.printGraph();
        return 0;
}
//************************************************************************************************************
