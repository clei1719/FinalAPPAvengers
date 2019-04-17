#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <list>
#include <vector>
#include "Vertex.hpp"
#include "UnDirectedGraph.hpp"

using namespace std;

UnDirectedGraph::UnDirectedGraph()// Constructor
{

}
UnDirectedGraph::UnDirectedGraph(int size)// PreConstructor
{

}
UnDirectedGraph::~UnDirectedGraph() // Deconstructor
{
        listOfVertex.empty();
}
void UnDirectedGraph::addVertex(string label) // creating a new node/vertex and add it to the graph array
{
        // add vertex
        Vertex *newVertex = new Vertex;
        newVertex->label = label;
        //newVertex->distance = rand() % 10; // random generates the distance;
        listOfVertex.push_back(newVertex);
}
void UnDirectedGraph::addEdge(string v1, string v2) // makes UnDirected Connections
{
        addEdgeHelper(v1,v2);
        addEdgeHelper(v2,v1);
}

void UnDirectedGraph::addEdgeHelper(string v1, string v2) // Loop through array, find v1 and v2, then in list of v1, add v2
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
void UnDirectedGraph::printGraph()
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
void UnDirectedGraph::exportGraph() // this will dump the graph for js or css for visualization.
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
void UnDirectedGraph::displayEdges()
{
        for(unsigned int i = 0; i < listOfVertex.size(); i++)
        {
                cout << listOfVertex[i]->label << "-->";
                for(unsigned int j = 0; j < listOfVertex[i]->edges.size(); j++)
                {

                        if(j == listOfVertex[i]->edges.size() - 1)// without stars because its at the end
                        {
                                cout << listOfVertex[i]->edges[j]->label << " (" << listOfVertex[i]->edges[j]->distance << " miles)";
                        }
                        else
                        {
                                cout << listOfVertex[i]->edges[j]->label << " (" << listOfVertex[i]->edges[j]->distance << " miles)***";
                        }
                }
                cout << endl;
        }
}
void UnDirectedGraph::printBFT()
{
        setAllVerticesUnvisited(); // clears all to unvisisted in case we search again.
        for(unsigned int i = 0; i < listOfVertex.size(); i++) // loops through verticies.
        {
                if(listOfVertex[i]->saved == false) // if the vertex has not been visited then we print
                        BFT_traversal(listOfVertex[i]);
        }
}
void UnDirectedGraph::BFT_traversal(Vertex *v)
{
        vector<Vertex*> traversal; // creates a new temp queue for us to use to traverse the list of Vertexs we have in the graph.
        traversal.push_back(v); // adds the root or starting node
        cout << v->label << endl;
        v->saved = true;
        while(traversal.size()!=0) // is the size of the traversal que, if it is not 0 then we keep going through the que
        {
                Vertex* current=traversal[0];
                for(unsigned int j = 0; j < current->edges.size(); j++) // for loop for each edge of a single node
                {

                        if(!current->edges[j]->saved) // if pointer of edge vertex pointer does not match
                        {
                                cout << current->edges[j]->label << endl; // this accesses the edge pointer of vertex type member function of name
                                current->edges[j]->saved = true; // marks the edge as being visited for that current node/vertex
                                traversal.push_back(current->edges[j]); // adding all the edges of the current node/vertex
                        }
                }
                traversal.erase(traversal.begin()); // it is popping of the que from the traversal, vector list of vertexs.
                // this basically pops out the node we just looked at and lets us move to the next node that will become the new current.
        }
}
Vertex* UnDirectedGraph::checkDistance(Vertex* playerStart) // BFT modification for checking how far a node is from the player.
{
        vector<Vertex*> traversal; // creates a new temp queue for us to use to traverse the list of Vertexs we have in the graph.
        traversal.push_back(playerStart); // adds the root or starting node
        cout << playerStart->label << endl;
        playerStart->distance=0;
        playerStart->visited = true;

        while(traversal.size()!=0) // is the size of the traversal que, if it is not 0 then we keep going through the que
        {
                Vertex* current=traversal[0];
                for(unsigned int j = 0; j < current->edges.size(); j++) // for loop for each edge of a single node
                {

                        if(!current->edges[j]->visited) // if pointer of edge vertex pointer does not match
                        {
                                cout << current->edges[j]->label << endl; // this accesses the edge pointer of vertex type member function of name
                                current->edges[j]->visited = true; // marks the edge as being visited for that current node/vertex
                                traversal.push_back(current->edges[j]); // adding all the edges of the current node/vertex
                                // we need to return the list of vectors 3 nodes deep
                                current->edges[j]->distance = current->distance+1; // counts the levels or depth of nodes around player.
                                //return current->edges[j]->v; // return pointer to node;
                        }

                }
                traversal.erase(traversal.begin()); // it is popping of the que from the traversal, vector list of vertexs.
                // this basically pops out the node we just looked at and lets us move to the next node that will become the new current.
        }
        while(1) // selects a random node that fits the distance of 3 or greater and returns that node.
        {
                int random=rand()%listOfVertex.size();
                if(listOfVertex[random]->distance<3)
                {
                        // we do nothing here.....
                }
                else
                {
                        return listOfVertex[random];
                }
        }
}
Vertex* UnDirectedGraph::BFTempty(Vertex* emptyStart)
{
        vector<Vertex*> traversal; // creates a new temp queue for us to use to traverse the list of Vertexs we have in the graph.
        traversal.push_back(emptyStart); // adds the root or starting node
        cout << emptyStart->label << endl;
        emptyStart->distance=0;
        emptyStart->visited = true;

        while(traversal.size()!=0) // is the size of the traversal que, if it is not 0 then we keep going through the que
        {
                Vertex* current=traversal[0];
                for(unsigned int j = 0; j < current->edges.size(); j++) // for loop for each edge of a single node
                {

                        if(!current->edges[j]->visited) // if pointer of edge vertex pointer does not match
                        {
                                cout << current->edges[j]->label << endl; // this accesses the edge pointer of vertex type member function of name
                                current->edges[j]->visited = true; // marks the edge as being visited for that current node/vertex
                                traversal.push_back(current->edges[j]); // adding all the edges of the current node/vertex
                                // we need to return the list of vectors 3 nodes deep
                                current->edges[j]->distance = current->distance+1; // counts the levels or depth of nodes around player.
                                //return current->edges[j]->v; // return pointer to node;
                        }

                }
                traversal.erase(traversal.begin()); // it is popping of the que from the traversal, vector list of vertexs.
                // this basically pops out the node we just looked at and lets us move to the next node that will become the new current.
        }
        while(1) // selects a random node that fits the distance of 3 or greater and returns that node.
        {
                int random=rand()%listOfVertex.size();
                if(listOfVertex[random]->distance <= 1 && !listOfVertex[random]->saved)
                {
                        // we do nothing here.....
                }
                else
                {
                        return listOfVertex[random];
                }
        }
}
void UnDirectedGraph::printDFT()
{
        setAllVerticesUnvisited();// clears all to unvisisted in case we search again.
        for(unsigned int i = 0; i < listOfVertex.size(); i++)
        {
                if(listOfVertex[i]->visited == false) // if the vertex has not been visited then we print
                        DFT_traversal(listOfVertex[i]);
        }
}
void UnDirectedGraph::DFT_traversal(Vertex *v)
{
        // searches if visited or not
        v->visited = true;
        cout << v->label << endl;
        for(unsigned int i = 0; i < v->edges.size(); i++) // loop through edges
        {
                if(v->edges[i]->visited == false) // check if visited
                {
                        // recusive calls
                        DFT_traversal(v->edges[i]); //reccur through each edge
                }
        }
}
Vertex* UnDirectedGraph::findVertex(std::string name)
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
void UnDirectedGraph::setAllVerticesUnvisited()
{
        for(unsigned int i = 0; i < listOfVertex.size(); i++)
        {
                listOfVertex[i]->visited = false;
        }
}
Vertex* UnDirectedGraph::playerLocation()
{
        return currPlayer.playerLocation;
}
void UnDirectedGraph::SetplayerLocation(Vertex* v)
{
        currPlayer.playerLocation = v;
}
Vertex* UnDirectedGraph::thanatosLocation()
{
        return Thanatos.playerLocation;
}
Vertex* UnDirectedGraph::emptyLocation()
{
        return Empty.playerLocation;
}
void UnDirectedGraph::setemptyLocation(Vertex* v)
{
        Empty.playerLocation = v;
}
bool UnDirectedGraph::isPlayeronNode(Vertex* v)// first check if player is on the node that empty wants to eat.
{
        if(currPlayer.playerLocation == v)
        {
                return true;
        }
        else
        {
                return false;
        }
}
bool UnDirectedGraph::hasBeenSaved(Vertex* v) // if player has visited this node before
{
        for(unsigned int i = 0; i < listOfVertex.size(); i++)
        {
                if(listOfVertex[i]->saved == v->saved)
                {
                        return true;
                }
        }
        return false;
}
void UnDirectedGraph::insertPlayer()
{

        int numOfVertex = rand() % listOfVertex.size(); // this grab the random index# for the size of the graph.
        currPlayer.playerLocation = listOfVertex[numOfVertex]; // inserts Player at a random location in graph.
        currPlayer.playerLocation->saved = true; // saves the location player is currently on when starting.
}
void UnDirectedGraph::insertThanatos()
{
        //search first for 3 nodes away from player;
        Vertex* thanatosLocation = checkDistance(currPlayer.playerLocation);
        Thanatos.playerLocation = thanatosLocation; // inserts Player at a random location in graph.
}
void UnDirectedGraph::insertEmpty()
{
        Vertex* EmptyLocation = checkDistance(currPlayer.playerLocation);// check 3 modes away from player, if not then reroll;
        Empty.playerLocation = EmptyLocation; // inserts Player at a random location in graph.
        Empty.playerLocation->dead = true; // saves the location empty is currently on when starting.
}
