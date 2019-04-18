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

void AvengersTitleScreen()
{
        cout << R"(


                         AAA
                        A:::A
                       A:::::A
                      A:::::::A
                     A:::::::::A           vvvvvvv           vvvvvvv    eeeeeeeeeeee    nnnn  nnnnnnnn       ggggggggg   ggggg    eeeeeeeeeeee    rrrrr   rrrrrrrrr       ssssssssss
                    A:::::A:::::A           v:::::v         v:::::v   ee::::::::::::ee  n:::nn::::::::nn    g:::::::::ggg::::g  ee::::::::::::ee  r::::rrr:::::::::r    ss::::::::::s
                   A:::::A A:::::A           v:::::v       v:::::v   e::::::eeeee:::::een::::::::::::::nn  g:::::::::::::::::g e::::::eeeee:::::eer:::::::::::::::::r ss:::::::::::::s
                  A:::::A   A:::::A           v:::::v     v:::::v   e::::::e     e:::::enn:::::::::::::::ng::::::ggggg::::::gge::::::e     e:::::err::::::rrrrr::::::rs::::::ssss:::::s
                 A:::::A     A:::::A           v:::::v   v:::::v    e:::::::eeeee::::::e  n:::::nnnn:::::ng:::::g     g:::::g e:::::::eeeee::::::e r:::::r     r:::::r s:::::s  ssssss
                A:::::AAAAAAAAA:::::A           v:::::v v:::::v     e:::::::::::::::::e   n::::n    n::::ng:::::g     g:::::g e:::::::::::::::::e  r:::::r     rrrrrrr   s::::::s
               A:::::::::::::::::::::A           v:::::v:::::v      e::::::eeeeeeeeeee    n::::n    n::::ng:::::g     g:::::g e::::::eeeeeeeeeee   r:::::r                  s::::::s
              A:::::AAAAAAAAAAAAA:::::A           v:::::::::v       e:::::::e             n::::n    n::::ng::::::g    g:::::g e:::::::e            r:::::r            ssssss   s:::::s
             A:::::A             A:::::A           v:::::::v        e::::::::e            n::::n    n::::ng:::::::ggggg:::::g e::::::::e           r:::::r            s:::::ssss::::::s
            A:::::A               A:::::A           v:::::v          e::::::::eeeeeeee    n::::n    n::::n g::::::::::::::::g  e::::::::eeeeeeee   r:::::r            s::::::::::::::s
           A:::::A                 A:::::A           v:::v            ee:::::::::::::e    n::::n    n::::n  gg::::::::::::::g   ee:::::::::::::e   r:::::r             s:::::::::::ss
          AAAAAAA                   AAAAAAA           vvv               eeeeeeeeeeeeee    nnnnnn    nnnnnn    gggggggg::::::g     eeeeeeeeeeeeee   rrrrrrr              sssssssssss
                                                                                                                      g:::::g
                                                                                                          gggggg      g:::::g
                                                                                                          g:::::gg   gg:::::g
                                                                                                           g::::::ggg:::::::g
                                                                                                            gg:::::::::::::g
                                                                                                              ggg::::::ggg
                                                                                                                 gggggg
  )" << '\n';
        cout << R"(


                                                                    MMMMMMMM               MMMMMMMM
                                                                    M:::::::M             M:::::::M
                                                                    M::::::::M           M::::::::M
                                                                    M:::::::::M         M:::::::::M
                                                                    M::::::::::M       M::::::::::M  aaaaaaaaaaaaa   zzzzzzzzzzzzzzzzz    eeeeeeeeeeee
                                                                    M:::::::::::M     M:::::::::::M  a::::::::::::a  z:::::::::::::::z  ee::::::::::::ee
                                                                    M:::::::M::::M   M::::M:::::::M  aaaaaaaaa:::::a z::::::::::::::z  e::::::eeeee:::::ee
                                                                    M::::::M M::::M M::::M M::::::M           a::::a zzzzzzzz::::::z  e::::::e     e:::::e
                                                                    M::::::M  M::::M::::M  M::::::M    aaaaaaa:::::a       z::::::z   e:::::::eeeee::::::e
                                                                    M::::::M   M:::::::M   M::::::M  aa::::::::::::a      z::::::z    e:::::::::::::::::e
                                                                    M::::::M    M:::::M    M::::::M a::::aaaa::::::a     z::::::z     e::::::eeeeeeeeeee
                                                                    M::::::M     MMMMM     M::::::Ma::::a    a:::::a    z::::::z      e:::::::e
                                                                    M::::::M               M::::::Ma::::a    a:::::a   z::::::zzzzzzzze::::::::e
                                                                    M::::::M               M::::::Ma:::::aaaa::::::a  z::::::::::::::z e::::::::eeeeeeee
                                                                    M::::::M               M::::::M a::::::::::aa:::az:::::::::::::::z  ee:::::::::::::e
                                                                    MMMMMMMM               MMMMMMMM  aaaaaaaaaa  aaaazzzzzzzzzzzzzzzzz    eeeeeeeeeeeeee


  )" << '\n';





        cout << R"(

                                                          TTTTTTTTTTTTTTTTTTTTTTT                      iiii                             iiii
                                                          T:::::::::::::::::::::T                     i::::i                           i::::i
                                                          T:::::::::::::::::::::T                      iiii                             iiii
                                                          T:::::TT:::::::TT:::::T
                                                          TTTTTT  T:::::T  TTTTTTrrrrr   rrrrrrrrr   iiiiiii vvvvvvv           vvvvvvviiiiiii   aaaaaaaaaaaaa
                                                                  T:::::T        r::::rrr:::::::::r  i:::::i  v:::::v         v:::::v i:::::i   a::::::::::::a
                                                                  T:::::T        r:::::::::::::::::r  i::::i   v:::::v       v:::::v   i::::i   aaaaaaaaa:::::a
                                                                  T:::::T        rr::::::rrrrr::::::r i::::i    v:::::v     v:::::v    i::::i            a::::a
                                                                  T:::::T         r:::::r     r:::::r i::::i     v:::::v   v:::::v     i::::i     aaaaaaa:::::a
                                                                  T:::::T         r:::::r     rrrrrrr i::::i      v:::::v v:::::v      i::::i   aa::::::::::::a
                                                                  T:::::T         r:::::r             i::::i       v:::::v:::::v       i::::i  a::::aaaa::::::a
                                                                  T:::::T         r:::::r             i::::i        v:::::::::v        i::::i a::::a    a:::::a
                                                                TT:::::::TT       r:::::r            i::::::i        v:::::::v        i::::::ia::::a    a:::::a
                                                                T:::::::::T       r:::::r            i::::::i         v:::::v         i::::::ia:::::aaaa::::::a
                                                                T:::::::::T       r:::::r            i::::::i          v:::v          i::::::i a::::::::::aa:::a
                                                                TTTTTTTTTTT       rrrrrrr            iiiiiiii           vvv           iiiiiiii  aaaaaaaaaa  aaaa








  )" << '\n';

}




void Menu()
{
        cout << "1. How to Play" << endl;
        cout << "2. Start Game" << endl;
        cout << "3. Quit" << endl;
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

void generateRandomGraph(UnDirectedGraph &graph)
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
//FUNCTIONS END
//************************************************************************************************************

//************************************************************************************************************
//MAIN GOES HERE:
int main(int argc, char *argv[])
{
        AvengersTitleScreen();
        Intro();
        string choice;

        UnDirectedGraph graph(35);
        bool isPlayer;
        Trivia triviaBank;
        triviaBank.addTrivia();
        questions q;
        //int num = graph.randomNum();
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
                        graph.printGraph();// TODO prints graph in text for now..json export later.
                        //TODO insert player into graph
                        graph.insertPlayer();
                        cout << "Player should be inserted at: " << graph.listOfVertex[1]->label << endl;
                        //TODO insert thantos into graph 3 nodes away from player location // kill switch
                        graph.insertThanatos();
                        //TODO insert Empty into graph at least two away from player
                        graph.insertEmpty();
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
                                // If it is correct, then move to node and mark as saved , if incorrect then stay at node and end turn.
                                if(triviaBank.isCorrect(playerAnswer, answer))// compare function to check if player got the question Correct
                                {
                                        //TODO move to node
                                        /* Then we call a menu to ask player to choose which edge to follow
                                           this means that we will need the player location to find the vertex, and then
                                           display the number of edges in form of choices for the player to choose from*/
                                        //TODO choose the next planet to save
                                        // loop through all verteices
                                        cout << "This is a list of Planets you can choose to save next." << endl;
                                        Vertex* playerLoc = graph.playerLocation();
                                        Vertex* thanatosLocation = graph.thanatosLocation();
                                        string selection;
                                        int count = 1;
                                        // loop through all edges
                                        for(unsigned int j = 0; j < playerLoc->edges.size(); j++) // list of edges based on player location
                                        {
                                                // check if it is dead or saved
                                                if(!playerLoc->edges[j]->saved && !playerLoc->edges[j]->dead)
                                                {
                                                        // then give a choice list to player for which options are available
                                                        cout << j + 1 << ". "  << (playerLoc->edges[j]->label) << endl;
                                                        count++;
                                                }
                                        }
                                        cout << "Please choose the next Planet to liberate." << endl;
                                        // ask for input from user to select where they want to go.
                                        getline(cin, selection);
                                        int index = stoi(selection);
                                        bool flag = true;
                                        while(flag == true)
                                        {
                                                if(index <= count && (index > 48 || index < 48 + count))
                                                {
                                                        // then move player to that choice
                                                        graph.SetplayerLocation(playerLoc->edges[index - 1]); // updates the player location to that new vertex.
                                                        //Vertex* playerLoc1 = graph.playerLocation();
                                                        if(playerLoc == thanatosLocation)
                                                        {
                                                                cout << "You have found Thanatos!" << endl;
                                                                cout << "YOU WIN!!" << endl;
                                                                //TODO minigame function can go here!
                                                                return 0;
                                                        }
                                                        playerLoc->edges[index - 1]->saved = true; // marks planet as saved.
                                                        flag = false; // kicks out of loop.
                                                }
                                                else
                                                {
                                                        cout << "Invalid input, please enter a valid number selection in range." << endl;
                                                        flag = true; // keeps loop going
                                                        getline(cin, selection); // ask for new input.
                                                }
                                        }
                                }
                                else // player got a question wrong and players turn ends
                                {
                                        // COMPUTER TURN
                                        isPlayer = false;
                                        Vertex* emptyLoc = graph.emptyLocation();
                                        cout << "The empty stirs at its location: " << emptyLoc->label << endl;
                                        // function for Empty to select a node to possibly eat;
                                        Vertex* nodeEmptyisGoingToEat = graph.BFTempty(emptyLoc); // traverses the graph only 1 node away and returns a random node.
                                        cout << "It looks around, hungry and ravenous. It decides to move to a new planet at: " << nodeEmptyisGoingToEat->label << endl;
                                        while(isPlayer == false)
                                        {
                                                //computer turn for empty to eat a node with the lowest weight moves there and mark it as dead.
                                                if(graph.isPlayeronNode(nodeEmptyisGoingToEat)) // first check if player is on the node that empty wants to eat.
                                                {
                                                        //TODO game over if empty eats player.
                                                        cout << "GAME OVER!!" << endl;
                                                        cout << "Your HERO's are defeated by the EMPTY! R.I.P." << endl;
                                                        return 0;
                                                }
                                                else
                                                {
                                                        //TODO eats the node - traverses to node to eat.
                                                        graph.setemptyLocation(nodeEmptyisGoingToEat);
                                                        cout << "The Empty eats the planet: " << nodeEmptyisGoingToEat->label << endl;
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
