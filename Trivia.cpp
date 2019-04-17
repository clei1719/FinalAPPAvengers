#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Trivia.hpp"

using namespace std;

// vector<string> trivia // to index a list of questions
// another vector or 2D array? for access to elements in a particular line

// or Artem thinks hashTable will work here. i will kill you!
Trivia::Trivia()
{

}
Trivia::~Trivia()
{

}
void Trivia::addTrivia()
{
        //read in the file and sort the data into saved variables.
        ifstream input("MarvelTrivia.csv");
        string line;
        if(input.is_open())
        {
                while(getline(input, line))
                {
                        stringstream ss;
                        ss << line;
                        questions q;
                        getline(ss, q.question, ',');
                        getline(ss, q.arr[0], ',');
                        getline(ss, q.arr[1], ',');
                        getline(ss, q.arr[2], ',');
                        getline(ss, q.arr[3], ',');
                        getline(ss, q.answer, ',');
                        tBank.push_back(q);
                }
        }
        else
        {
                cout << "MarvelTrivia.csv was not read in" << endl;
        }
}
bool Trivia::isCorrect(string playerInput,string answer) // checks if trivia question is correct against actual answer..
{
        bool flag = true;
        while(flag == true)
        {
                // convert player input to lower case.
                char ansPlayer = tolower(playerInput[0]);
                if(ansPlayer >= 97 && ansPlayer <= 100)
                {
                        if(playerInput == answer)
                        {
                                cout << "Congratulations! You are correct!" << endl;
                                cout << "You have saved the planet and get to move again! " << answer << endl;
                                flag = false; // correct input
                                return true;
                        }
                        else
                        {
                                cout << "The answer is incorrect" << endl;
                                cout << "The correct answer is: " << answer << endl;
                                cout << "You failed to save the next planet and are stuck at your current location" << endl;
                                cout << "THANATOS takes action by commanding his pet, the EMPTY!" << endl;
                                flag = false; // correct input
                                return false;
                        }
                }
                else
                {
                        cout << "Invalid Input, please select the the appropriate letter choice." << endl;
                        flag = true;
                        getline(cin,playerInput);

                }
        }
        return false;
}
