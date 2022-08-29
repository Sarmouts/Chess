#include <iostream>
#include "Pawns.h"

void printG()
{
	std::cout << std::endl << "  ";
	for (int i = 0; i < 8; i++)
		std::cout << i << " ";
	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << i << " ";
		for (int j = 0; j < 8; j++)
		{
			if (Game[i][j] == 0)
				std::cout << "  ";
			else
				std::cout << Game[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
bool MovePawn(bool player, int xo, int yo, int x, int y)
{
	if (Game[yo][xo] == 'Q' || Game[yo][xo] == 'E')
		return Q(player, xo, yo, x, y);
	else if (Game[yo][xo] == 'K' || Game[yo][xo] == 'M')
		return K(player, xo, yo, x, y);
	else if (Game[yo][xo] == 'O' || Game[yo][xo] == 'B')
		return O(player, xo, yo, x, y);
	else if (Game[yo][xo] == 'H' || Game[yo][xo] == 'L')
		return H(player, xo, yo, x, y);
	else if (Game[yo][xo] == 'C' || Game[yo][xo] == 'R')
		return C(player, xo, yo, x, y);
	else if (Game[yo][xo] == 'S' || Game[yo][xo] == 'W')
		return S(player, xo, yo, x, y);
	else
		return 0;
}
int main()
{
	std::string a[2];
	std::cout << "Player 1 enter your name: ";
	std::cin >> a[0];
	std::cout << "Player 2 enter your name: ";
	std::cin >> a[1];
	printG();
	bool i = 0;
	int xo, yo, x, y;
	while (1)
	{
		std::cout << std::endl << a[i] << " is playing:" << std::endl;
		std::cout << "Enter the Current Position of your pawn: ";
		std::cin >> xo >> yo;
		std::cout << "Move To: ";
		std::cin >> x >> y;
		if (MovePawn(i, xo, yo, x, y))
			i -= 1;
		else
			std::cout << std::endl << "Wrong Position or Type, Try Again!!!" << std::endl;
		printG();
	}
}