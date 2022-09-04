#pragma once
#include<string>
char Game[8][8] = {
	{'R','L','B','M','E','B','L','R'},
	{'W','W','W','W','W','W','W','W'},
	{254,254,254,254,254,254,254,254},
	{254,254,254,254,254,254,254,254},
	{254,254,254,254,254,254,254,254},
	{254,254,254,254,254,254,254,254},
	{'S','S','S','S','S','S','S','S'},
	{'C','H','O','K','Q','O','H','C'}
};
std::string player1 = "KQOHCS";
std::string player2 = "MEBLRW";
bool IsMovingHisPawn(bool player, int xo, int yo)
{
	if (player)
	{
		if (player2.find(Game[yo][xo]) == std::string::npos)
			return 0;
		return 1;
	}
	if (player1.find(Game[yo][xo]) == std::string::npos)
		return 0;
	return 1;
}
bool NotPawnOfSamePlayer(bool player, int x, int y)
{
	if (player)
	{
		if (player2.find(Game[y][x]) == std::string::npos)
			return 1;
		return 0;
	}
	if (player1.find(Game[y][x]) == std::string::npos)
		return 1;
	return 0;
}//returns 1 if move is correct(if it is not the same player's pawn at the given position) 0 if not
bool PositionExists(int x, int y)
{
	if (x > 7 || y > 7 || x < 0 || y < 0)
		return 0;
	return 1;
}
bool CheckDiagonalMove(int xo, int x, int yo, int y)//if there another pawn until it reaches the position given by the player 
{
	int n = (y - yo) / abs(y - yo);
	int z = (x - xo) / abs(x - xo);
	for (yo += n, xo += z; yo != y; yo += n, xo += z)
		if (Game[yo][xo] != char(254))
			return 0;
	return 1;
}//returns 1 if move is correct 0 if not
bool CheckStraightMove(int xo, int yo, int x, int y)//if there another pawn until it reaches the position given by the player
{
	if (x == xo)
	{
		int n = (y - yo) / abs(y - yo);
		for (int i = yo + n; i != y; i += n)
			if (Game[i][xo] != char(254))
				return 0;
		return 1;
	}
	int n = (x - xo) / abs(x - xo); //y=yo
	for (int i = xo + n; i != x; i += n)
		if (Game[yo][i] != char(254))
			return 0;
	return 1;
}//returns 1 if move is correct 0 if not