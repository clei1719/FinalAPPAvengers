#ifndef UnDirectedGraph_HPP
#define UnDirectedGraph_HPP

#include <stdlib.h>
#include <fstream>
#include <list>
#include <vector>
#include "Vertex.hpp"
//#include "Edge.hpp"

using namespace std;

class UnDirectedGraph
{
private:

public:
// The maximum number of vertex for the graph or random graph.
bool visited;
int SizeOfGraph = 50; // size of graph
vector<Vertex*> listOfVertex;
int count; // index of all vertex's that are stored in graph

UnDirectedGraph()// Constructor
{

}
UnDirectedGraph(int size)// PreConstructor
{

}
~UnDirectedGraph() // Deconstructor
{
        listOfVertex.empty();
}
void addVertex(string label) // creating a new node/vertex and add it to the graph array
{
        // add vertex
        Vertex *newVertex = new Vertex;
        newVertex->label = label;
        listOfVertex.push_back(newVertex);
}
void addEdge(string v1, string v2) // makes UnDirected Connections
{
        addEdgeHelper(v1,v2);
        addEdgeHelper(v2,v1);
}

void addEdgeHelper(string v1, string v2) // Loop through array, find v1 and v2, then in list of v1, add v2
{
        Vertex *tempV2=NULL;
        Vertex *tempV1=NULL;

        for(Vertex* i: listOfVertex) // Loop through array
        {
                if(v2 == i->label) // find v2
                {
                        tempV2 = i; // passes the location of v1 vertex to temp pointer.
                }
                if(v1 == i->label) // find v1
                {
                        tempV1 = i; // passes the location of v1 to temp pointer.
                }
        }
        // then in list of v1, add v2
        if(tempV1!=NULL && tempV2!=NULL)
        {
                tempV1->edges.push_back(tempV2); // list of edges takes v1 vertex count
        }


}
void printGraph()
{
        //for each vertex in graph array print its label and then print each edge for that node
        for(Vertex* current: listOfVertex)//for each vertex in graph array
        {
                //Vertex* current = listOfVertex[i]; // current is just an easy way to see that it is the vertex at i
                cout << current->label <<": "; // print vertex at its label(this will do this for all vertexs)
                for(Vertex* j : current->edges) // then for each edge count for that particular vertex
                {
                        // print each edge for that node/vertex
                        // Easier understood that it is really printing the labels of the
                        // other neighboring node/vertexs, or rather the connections.
                        cout << j->label<< " ";
                }
                cout<<endl;
        }
}
void exportGraph() // this will dump the graph for js or css for visualization.
{
        ofstream outputFile;
        outputFile.open("output.txt");
        if(outputFile.is_open())
        {
                //for each vertex in graph array print its label and then print each edge for that node
                for(Vertex *current : listOfVertex)//for each vertex in graph array
                {
                        //Vertex* current = listOfVertex[i]; // current is just an easy way to see that it is the vertex at i
                        outputFile << current->label <<": "; // print vertex at its label(this will do this for all vertexs)
                        for(Vertex* j : current->edges) // then for each edge count for that particular vertex
                        {
                                // print each edge for that node/vertex
                                // Easier understood that it is really printing the labels of the
                                // other neighboring node/vertexs, or rather the connections.
                                outputFile << j->label<< " ";
                        }
                        outputFile<<endl;
                }
        }
}
void displayEdges()
{
        for(unsigned int i = 0; i < listOfVertex.size(); i++)
        {
                cout << listOfVertex[i]->label << "-->";
                for(unsigned int j = 0; j < listOfVertex[i]->edges.size(); j++)
                {

                        if(j == listOfVertex[i]->edges.size() - 1)// without stars because its at the end
                        {
                                cout << listOfVertex[i]->edges[j]->v->label << " (" << listOfVertex[i]->edges[j]->weight << " miles)";
                        }
                        else
                        {
                                cout << listOfVertex[i]->edges[j]->v->label << " (" << listOfVertex[i]->edges[j]->weight << " miles)***";
                        }
                }
                cout << endl;
        }
}
void printBFT()
{
        setAllVerticesUnvisited(); // clears all to unvisisted in case we search again.
        for(unsigned int i = 0; i < listOfVertex.size(); i++) // loops through verticies.
        {
                if(listOfVertex[i]->visited == false) // if the vertex has not been visited then we print
                        BFT_traversal(listOfVertex[i]);
        }
}
void BFT_traversal(Vertex *v)
{
        vector<Vertex*> traversal; // creates a new temp queue for us to use to traverse the list of Vertexs we have in the graph.
        traversal.push_back(v); // adds the root or starting node
        cout << v->label << endl;
        v->visited = true;
        while(traversal.size()!=0) // is the size of the traversal que, if it is not 0 then we keep going through the que
        {
                Vertex* current=traversal[0];
                for(unsigned int j = 0; j < current->edges.size(); j++) // for loop for each edge of a single node
                {

                        if(!current->edges[j]->v->visited) // if pointer of edge vertex pointer does not match
                        {
                                cout << current->edges[j]->v->label << endl; // this accesses the edge pointer of vertex type member function of name
                                current->edges[j]->v->visited = true; // marks the edge as being visited for that current node/vertex
                                traversal.push_back(current->edges[j]->v); // adding all the edges of the current node/vertex
                        }
                }
                traversal.erase(traversal.begin()); // it is popping of the que from the traversal, vector list of vertexs.
                // this basically pops out the node we just looked at and lets us move to the next node that will become the new current.
        }
}
void printDFT()
{
        setAllVerticesUnvisited();// clears all to unvisisted in case we search again.
        for(unsigned int i = 0; i < listOfVertex.size(); i++)
        {
                if(listOfVertex[i]->visited == false) // if the vertex has not been visited then we print
                        DFT_traversal(listOfVertex[i]);
        }
}
void DFT_traversal(Vertex *v)
{
        // searches if visited or not
        v->visited = true;
        cout << v->label << endl;
        for(unsigned int i = 0; i < v->edges.size(); i++) // loop through edges
        {
                if(v->edges[i]->v->visited == false) // check if visited
                {
                        // recusive calls
                        DFT_traversal(v->edges[i]->v); //reccur through each edge
                }
        }
}
Vertex* findVertex(std::string name)
{
        for(unsigned int i = 0; i < listOfVertex.size(); i++)
        {
                if(listOfVertex[i]->label == name)
                {
                        return listOfVertex[i];
                }
        }
        return NULL;
}
void setAllVerticesUnvisited()
{
        for(unsigned int i = 0; i < listOfVertex.size(); i++)
        {
                listOfVertex[i]->visited = false;
        }
}
};
#endif
