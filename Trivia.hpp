#include <iostream>
#include <vector>
#include <stdlib.h>

#ifndef Trivia_HPP
#define Trivia_HPP

using namespace std;

// vector<string> trivia // to index a list of questions
// another vector or 2D array? for access to elements in a particular line

// or Artem thinks hashTable will work here. i will kill you!
struct questions
{
        string question;
        string answer;
        string arr[4];
};

class Trivia
{
public:
Trivia();
~Trivia();
void addTrivia();
bool isCorrect(string playerInput,string answer);
vector<questions> tBank;

private:

};
#endif
