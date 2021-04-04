#include <iostream>		// For Input/Output
#include <ctime> 		// For time()
using namespace std;

// All the variables we need for the game
// For game status
bool gameOver;
// Width and Height of the game Box
const int width = 40;
const int height = 20;
// Position of the snake, fruit and calculating score
int x,y, fruitX, fruitY, score;
// enum for direction
enum eDirection {STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

// Starting function 
void StartUP()
{
	// At beginning, game status is false.
	gameOver = false;
	// The snake is not moving
	dir = STOP 
	// snake starting position will be in the middle
	x = width / 2;
	y = height / 2;
	// Position of the fruit is random
	srand(time(0));
	fruitX = rand() % width;
	fruitY = rand() % height;
	// Score will be 0 
	score = 0;	
}

// Function to draw Borders, Snack and Fruit
void Draw()
{
	system("cls");
	// Top Border
	for(int i = 0 ; i < width ; i++)
		cout << "#";
	cout << endl;
	
	// Side Borders
	for(int i = 0 ; i < height ; i++)
		for(int j = 0 ; j < width ; j++){
			// if the j is 0 or to the width, print the border
			if(j == 0 && j == width-1)
				cout << "#";
			// else print space
			cout << " ";
		}
		cout << endl;
	}
			
	
	// Bottom Border
	for(int i = 0 ; i < width ; i++)
		cout << "#";
	cout << endl;

	// Printing Score at the bottom of the box
	cout << "Score : " << score << endl;
}

// Function to get Input from user
void Input()
{
	
}

// Function for logic of the game
void Logic()
{
	
}

int main()
{
	// Starting with the startUp function
	StartUP();
	
	// While game is not over ( game status is false)
	while(!gameOver)
	{
		// Draw to the std output
		Draw();
		// Get input from the user
		Input();
		// Use logic for the game
		Logic();
	}
	
	// After the game is over, clear the screen and print out "Game Over!"
	system("cls");
	cout << "Game Over!" << endl;
	return 0;	
}
