#include <iostream>		// For Input/Output
using namespace std;

// For game status
bool gameOver;

// Starting function 
void StartUP()
{
	
}

// Function to draw Borders, Snack and Fruit
void Draw()
{
	
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
