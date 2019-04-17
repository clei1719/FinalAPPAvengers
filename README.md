# FinalProjectAvengers
Final Project Write Up


Final Idea Consensus for Game: ~ Avenger Maze Trivia! ~

Story: 
	Across the cosmos dwells a dark power which slowly starts to eclipse the light of a nearby star!  The “EMTPY”, as they call it devours all in its path.  Its goal, to wipe out all existence, matter, and life everywhere if not controlled!  There is no escape; no place to run or hide!  The creature known as the “EMTPY”, only obeys one master by the name of Thanatos!  Thousands of years, and countless failures finally yielded a frightening result as the “EMPTY” was born, a weapon like no other, allowing Thanatos to continue his vision of keeping only half of the universe alive!  After his first successful extermination of life via the infinity stones, he now seeks to keep order and balance to his new universe!
	There are three new unlikely Heroes who find out about Thanatos’s master plan!  With the avengers scattered, missing, and some presumed dead, it is up to our new Heroes to save the galaxy!  Our three brave Heroes, Elon Stark, Mr. Moscow, and Lil Red will work together to free the galaxy from Thanatos’s grip!

Problem we are going to solve:
	To get through the maze, answer all the questions, defeat Thanatos, and save what remains of the galaxy while freeing them from oppression!

Design: 
	Players will start at the beginning of the Maze and traverse it.  The move the player will be allowed to move 1 step(node) in any direction allowed.  They are given a choice of paths to take in order to reach Thanatos, before the “EMPTY” eats them alive!
Once a Hero has landed at a “node”, a mini-game/challenge/question will appear for the Hero’s to work out!  If they succeed, then they get to go again and choose another direction, otherwise the turn will end for the player and the computer gets to move.  There are dead ends, and Thanatos spawns at a random location every new game! You will sometimes come upon traps/minions that will try to stop you along the way!
Rules:
The player starts at one node randomly
The player can move 1 node per turn
The player then chooses which direction to go
Once player chooses, they are asked a trivia question(on edges of graph)
If player answers the question correct, then the player is allowed to move to the next planet(node), and that planet is “saved”(meaning the Empty cannot travel there).
If player answers the question incorrectly, then player does not move from current planet(node), and the Empty eats a planet.

Type(s) of Data Structure(s) Used:  

Dynamically sized unDirected Graph using an array of Vertex’s and an array of edges to link. The graph is used for the player to go to and from nodes otherwise known as planets to pose as a maze which is randomly generated, and also destroyed as the enemy ai deletes nodes(planets). Additionally, the Trivia Questions will be stored and called on in form of a dynamic LL, which will provide the Question to the player when trying to move from one vertex to another.
In each LL there will be a list of questions that can be asked based on probability(dice roll), which will look at the LL that stores these questions and then display one for the player to answer.

