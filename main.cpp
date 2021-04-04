#include <iostream>		// For Input/Output
#include <ctime> 		// For time()
#include <conio.h> 		// For _kbhit and _getch()
#include <Windows.h>
using namespace std;

// All the variables we need for the game
// For game status
bool gameOver;
// Width and Height of the game Box
const int width = 40;
const int height = 20;
// Position of the snake, fruit and calculating score
int x, y, fruitX, fruitY, score;
// enum for direction
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
// For tail of the snake, we need two arrays of position for all the tails
int tailX[100] ,tailY[100];
int nTail;	// Size of the snake

// Starting function 
void StartUP()
{
	// At beginning, game status is false.
	gameOver = false;
	// The snake is not moving
	dir = STOP;
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
	for (int i = 0; i < width+1; i++)
		cout << "#";
	cout << endl;

	// Side Borders
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			// if the j is 0 or to the width, print the border
			if (j == 0 || j == width - 1)
				cout << "#";
			// printing the Snake
			if(i == y && j == x)
				cout << "O";
			// printing the Fruit
			else if(i == fruitY && j == fruitX)
				cout << "F";
			// else print space
			else{
				// for checking if we should print the tail or the space
				bool print = false;
				for(int k = 0 ; k < nTail ; k++)
				{
					if(tailX[k] == j && tailY[k] == i)
					{
						// printing the tail of the snake
						cout << "o" ;
						print=true;
					}
				}
				if(!print)
					cout << " ";
			}
		}
		cout << endl;
	}


	// Bottom Border
	for (int i = 0; i < width+1; i++)
		cout << "#";
	cout << endl;

	// Printing Score at the bottom of the box
	cout << "Score:" << score << endl;
}

// Function to get Input from user
void Input()
{
	// cheching to see if the keyborder is hit
	if (_kbhit)
	{
		// getting the input from the user
		switch (_getch())
		{
			// Using keyboards w,a,s,d keys to move the snake up, left,down and right accordingly
		case 'a':
			dir = LEFT;
			break;

		case 'd':
			dir = RIGHT;
			break;

		case 'w':
			dir = UP;
			break;

		case 's':
			dir = DOWN;
			break;

			// If user wants to quit the game
		case 'x':
			gameOver = true;
			break;
		}
	}
}

// Function for logic of the game
void Logic()
{
	// For the direction of the tail, we need to use the previous element's direction of the tail
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	// we need to store the prev elements direction to the current direction for all the tails, starting from 1 to the size of the snake
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	// According to the direction, updating the position of the snake's x and y coordinates
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}

	// if user hits the border, game is over
	/*if (x >= width || x < 0 || y >= height || y < 0)
		gameOver = true;*/
	// Just an update, user can now go through walls and to the other side. 
	if (x >= width) x = 0; else if (x < 0) x = width - 1;
	if (y >= height) y = 0; else if (y < 0) y = height - 1;
	
	// cheching if the user hits it's own tail, then game is over
	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;
	}

	// if user eats the fruit, update score, change the fruit's location and add tail to the snake
	if (x == fruitX && y == fruitY)
	{
		score += 10;
		srand(time(0));
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
}

int main()
{
	// Starting with the startUp function
	StartUP();

	// While game is not over ( game status is false)
	while (!gameOver)
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
