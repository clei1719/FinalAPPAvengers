//Load standard Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <time.h>
//Load class files
#include "Vertex.hpp"
#include "Trivia.hpp"
#include "DirectedGraph.hpp"
#include "UnDirectedGraph.hpp"

//************************************************************************************************************
//FUNCTIONS GO HERE:
void Intro()
{
        cout << "WELCOME TO THE AVENGERS TRIVIA GAME!!" << endl;
}
void Menu()
{
        cout << "1. How to Play" << endl;
        cout << "2. Start Game" << endl;
        cout << "3. Quit" << endl;
}
void generateRandomGraph(UnDirectedGraph &graph)
{
        srand(time(0)); //seeds random
        //DirectedGraph g(50); // creates an object of graph
        //UnDirectedGraph graph(25);
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
}
//FUNCTIONS END
//************************************************************************************************************

//************************************************************************************************************
//MAIN GOES HERE:
int main(int argc, char *argv[])
{
        Intro();
        string choice;

        UnDirectedGraph graph(25);
        bool isPlayer;
        Trivia triviaBank;
        triviaBank.addTrivia();
        questions q;
        while(choice != "3")
        {
                Menu();
                getline(cin,choice);
                switch(stoi(choice))
                {
                case 1:
                        cout << "Learn to play you dum dum" << endl;
                        break;
                case 2:
                        cout << "Beginning Game!" << endl;
                        cout << "Let the Battle Begin!" << endl;
                        generateRandomGraph(graph); // generates undirected graph for game play.
                        //TODO insert player into graph
                        graph.insertPlayer();
                        //TODO insert thantos into graph 3 nodes away from player location // kill switch
                        graph.insertThanatos();
                        //TODO insert Empty into graph at least two away from player
                        graph.insertEmpty();
                        graph.printGraph(); // prints graph in text...would be nice to have this do it in js or CSS or something.
                        // Player goes first, computer goes second.
                        isPlayer = true;
                        while(isPlayer == true)
                        {
                                //TODO After player chooses that is when we want to ask a random Trivia question.

                                q = triviaBank.tBank[rand() % 48]; // grabs the index of the question we want

                                string playerAnswer;
                                string question = q.question;
                                string A = q.arr[0];
                                string B = q.arr[1];
                                string C = q.arr[2];
                                string D = q.arr[3];
                                string answer = q.answer; // outputs the question
                                cout << question << endl; // outputs the question
                                cout << A << endl; // option A
                                cout << B << endl; // option B
                                cout << C << endl; // option C
                                cout << D << endl; // option D
                                cout << "Please Select a Letter Corresponding with the answer" << endl;
                                getline(cin, playerAnswer);
                                /* Then we call a menu to ask player to choose which edge to follow
                                   this means that we will need the player location to find the vertex, and then
                                   display the number of edges in form of choices for the player to choose from*/
                                // loop through all verteices
                                for(unsigned int i = 0; i < graph.listOfVertex.size(); i++)
                                {
                                        // loop through all edges
                                        for(unsigned int j =0; j < graph.listOfVertex[i]->edges.size(); j++)
                                        {
                                                // check if it is dead or saved
                                                if(graph.listOfVertex[i]->edges[j])
                                                {

                                                }
                                        }
                                }
                                // then give a choice to player for which options are available - switch statement or choice method?
                                // then move player to that choice


                                // If it is correct, then move to node and mark as saved , if incorrect then stay at node and end turn.

                                if(triviaBank.isCorrect(playerAnswer, question))// compare function to check if player got the question Correct
                                {
                                        //TODO move to node
                                        //TODO choose the next planet to save
                                }
                                else // player got a question wrong and players turn ends
                                {
                                        // COMPUTER TURN
                                        isPlayer = false;
                                        Vertex* playerLoc = graph.playerLocation();
                                        Vertex* emptyLoc = graph.emptyLocation();

                                        // function for Empty to select a node to possibly eat;
                                        Vertex* nodeEmptyisGoingToEat = graph.BFTempty(emptyLoc); // traverses the graph only 1 node away and returns a random node.
                                        while(isPlayer == false)
                                        {
                                                //computer turn for empty to eat a node with the lowest weight moves there and mark it as dead.
                                                if(graph.isPlayeronNode(playerLoc)) // first check if player is on the node that empty wants to eat.
                                                {
                                                        //TODO game over if empty eats player.
                                                        cout << "Your HERO's are defeated by the EMPTY! R.I.P." << endl;
                                                        break;
                                                }
                                                else
                                                {
                                                        //TODO eats the node - traverses to node to eat.
                                                        graph.setemptyLocation(nodeEmptyisGoingToEat);
                                                        //TODO marks it as dead
                                                        nodeEmptyisGoingToEat->dead = true;
                                                }
                                                // end computer turn
                                                isPlayer = true;
                                        }
                                }

                        }
                        break;
                case 3:
                        cout << "I guess your just going to let Thanatos kill everyone!  Great Thanks!" << endl;
                        break;
                default:
                        cout << "Invalid Input, please select a number between 1 and 3." << endl;
                }

        }
        return 0;
}
//************************************************************************************************************
