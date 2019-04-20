#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <vector>
#include <list>
#include "Vertex.hpp"
#include "UndirectedGraph.hpp"

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
void UnDirectedGraph::deleteGraph()
{
        for(Vertex* i : listOfVertex)
        {
                for(Vertex* j : i->edges)
                {
                        i->edges.pop_back();
                }
                delete listOfVertex.back();
                listOfVertex.pop_back();
        }
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
// may have issue of repeating an edge here....
void UnDirectedGraph::addEdgeHelper(string v1, string v2) // Loop through array, find v1 and v2, then in list of v1, add v2
{
        Vertex *tempV2=NULL;
        Vertex *tempV1=NULL;
        for(Vertex* i: listOfVertex)   // Loop through array
        {
                if(v2 == i->label)         // find v2
                {
                        tempV2 = i;         // passes the location of v1 vertex to temp pointer.
                }
                if(v1 == i->label)         // find v1
                {
                        tempV1 = i;         // passes the location of v1 to temp pointer.
                }
        }
        // then in list of v1, add v2
        if(tempV1!=NULL && tempV2!=NULL)
        {
                tempV1->edges.push_back(tempV2);         // list of edges takes v1 vertex count
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
                cout << endl;
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
        Vertex* player = playerLocation();
        Vertex* thanatos = thanatosLocation();
        Vertex* empty = emptyLocation();
        outputFile << "playerLocation: " << player->label << endl;
        outputFile << "thanatosLocation: " << thanatos->label << endl;
        outputFile << "emptyLocation: " << empty->label << endl;

        for (unsigned int i = 0; i < listOfVertex.size(); i++)
        {
                outputFile << listOfVertex[i]->saved << "," << listOfVertex[i]->dead << "," << listOfVertex[i]->visited << endl;
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
        //cout << playerStart->label << endl;
        playerStart->distance = 0;
        playerStart->visited = true;
        vector<Vertex*> stored;

        while(traversal.size() != 0) // is the size of the traversal que, if it is not 0 then we keep going through the que
        {
                Vertex* current = traversal[0];
                for(unsigned int j = 0; j < current->edges.size(); j++) // for loop for each edge of a single node
                {

                        if(!current->edges[j]->visited) // if pointer of edge vertex pointer does not match
                        {
                                //cout << current->edges[j]->label << endl; // this accesses the edge pointer of vertex type member function of name
                                current->edges[j]->visited = true; // marks the edge as being visited for that current node/vertex
                                traversal.push_back(current->edges[j]); // adding all the edges of the current node/vertex
                                // we need to return the list of vectors 3 nodes deep
                                current->edges[j]->distance = current->distance+1; // counts the levels or depth of nodes around player.
                                if(current->edges[j]->distance >= 2)
                                {
                                        //cout << "stored " << current->edges[j] << endl;
                                        stored.push_back(current->edges[j]);
                                }
                                //return current->edges[j]->v; // return pointer to node;
                        }


                }
                traversal.erase(traversal.begin()); // it is popping of the que from the traversal, vector list of vertexs.
                // this basically pops out the node we just looked at and lets us move to the next node that will become the new current.
        }
        // if(stored.empty())
        // {
        //         cout << "I am crabby "<< endl;
        //         return NULL;
        // }
        // selects a random node that fits the distance of 3 or greater and returns that node.
        // int random = rand()%stored.size();
        // return stored[random];
        while(1) // selects a random node that fits the distance of 3 or greater and returns that node.
        {
                int random=rand()%listOfVertex.size();
                if(listOfVertex[random]->distance <= 2 && !listOfVertex[random]->saved)
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
        //cout << emptyStart->label << endl;
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
int UnDirectedGraph::randomNum()
{
        srand(time(0));
        int i = 1;
        int n = rand() % listOfVertex.size();
        while(n) // this grab the random index# for the size of the graph.
        {
                return n;
        }
        return i;
}
void UnDirectedGraph::insertPlayer()
{
        int numOfVertex = rand() % listOfVertex.size(); // this grab the random index# for the size of the graph.
        currPlayer.playerLocation = listOfVertex[numOfVertex]; // inserts Player at a random location in graph.
        currPlayer.playerLocation->saved = true; // saves the location player is currently on when starting.
}
bool UnDirectedGraph::insertThanatos()
{
        //search first for 3 nodes away from player;
        Vertex* thanatosLocation = checkDistance(playerLocation());
        if(thanatosLocation != playerLocation())
        {
                Thanatos.playerLocation = thanatosLocation;   // inserts Player at a random location in graph.
                //cout << "Thanotos is inserted at: " << Thanatos.playerLocation->label << endl;   // temp cout
                return true;
        }
        else
        {
                unsigned int i = 0;
                while(playerLocation() == thanatosLocation && thanatosLocation->distance < 2)
                {
                        int numOfVertex = 0;
                        if(i < listOfVertex.size())
                        {
                                //cout << "in here !!" << endl;
                                string Vlist = listOfVertex[i]->label;
                                numOfVertex = stoi(Vlist); // this grab the random index# for the size of the graph.
                        }
                        thanatosLocation = listOfVertex[numOfVertex];
                        //cout << "Thanotos is inserted at: " << thanatosLocation->label << endl; // temp cout
                        i++;
                }
                return true;
                // deleteGraph();
                // SetplayerLocation(NULL);
                // thanatosLocation = NULL;
                // return false;
        }
        return false;
}
bool UnDirectedGraph::insertEmpty()
{
        Vertex* EmptyLocation = checkDistance(playerLocation());// check 3 modes away from player, if not then reroll;
        if(thanatosLocation() != EmptyLocation && EmptyLocation != playerLocation()) // so we don't insert on top of thanatos
        {
                Empty.playerLocation = EmptyLocation; // inserts Player at a random location in graph.
                Empty.playerLocation->dead = true; // saves the location empty is currently on when starting.
                //cout << "Empty is inserted at: " << Empty.playerLocation->label << endl; // temp cout
                return true;
        }
        else
        {
                deleteGraph();
                SetplayerLocation(NULL);
                setemptyLocation(NULL);
                EmptyLocation = NULL;
                return false;
        }
}
bool isEdgeThere(UnDirectedGraph g, int v1, int v2)
{
        Vertex* ver1=g.findVertex(to_string(v1));
        Vertex* ver2=g.findVertex(to_string(v2));
        for(unsigned int i=0; i<ver1->edges.size(); i++)
        {
                if(ver1->edges[i]->label==ver2->label)
                {
                        return true;
                }
        }
        return false;
}
void UnDirectedGraph::generateRandomGraph(UnDirectedGraph &graph)
{
        srand(time(0)); //seeds random
        //DirectedGraph g(50); // creates an object of graph
        //UnDirectedGraph graph(25);
        int numOfVertex = rand() % 25 + 10; // random num generator of size of graph.
        for(int i = 0; i < numOfVertex; i++) // creates the graph with vertexs
        {
                string s; // we may need to randomize vertex labels (perhaps a list of planets)
                graph.addVertex(to_string(i + 1)); // adds vertexs up to the numnber that we want
        }
        int v1 = 0; int v2 = 1;
        for(int j = 0; j < numOfVertex*2; j++)
        {
                v1=rand()%numOfVertex+1;
                v2=rand()%numOfVertex+1;
                if(v1 != v2 && !isEdgeThere(graph,v1,v2))
                {
                        graph.addEdge(to_string(v1),to_string(v2));
                }
                else
                {
                        j--;
                }
        }
}
