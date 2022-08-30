#pragma once
#include "ErrorCheckers.h";
bool Q(bool player, int xo, int yo, int x, int y)
{
	if (IsMovingHisPawn(player, xo, yo) && NotPawnOfSamePlayer(player, x, y))
	{
		if (abs(x - xo) == abs(y - yo))
		{
			if (CheckDiagonalMove(xo, x, yo, y))
			{
				Game[y][x] = Game[yo][xo];
				Game[yo][xo] = 254;
				return 1;
			}
		}
		else if (y == yo)
		{
			if (CheckStraightMove(0, xo, yo, x, y))
			{
				Game[y][x] = Game[yo][xo];
				Game[yo][xo] = 254;
				return 1;
			}
		}
		else if (x == xo)
		{
			if (CheckStraightMove(1, xo, yo, x, y))
			{
				Game[y][x] = Game[yo][xo];
				Game[yo][xo] = 254;
				return 1;
			}
		}
	}
	return 0;
}
bool K(bool player, int xo, int yo, int x, int y)
{
	if (IsMovingHisPawn(player, xo, yo) && NotPawnOfSamePlayer(player, x, y))
	{
		if (y == yo + 1 || y == yo - 1 || x == xo + 1 || x == xo - 1)
		{
			Game[y][x] = Game[yo][xo];
			Game[yo][xo] = 254;
			return 1;
		}
	}
	return 0;
}
bool O(bool player, int xo, int yo, int x, int y)
{
	if (IsMovingHisPawn(player, xo, yo) && NotPawnOfSamePlayer(player, x, y))
	{
		if (abs(x - xo) == abs(y - yo))
		{
			if (CheckDiagonalMove(xo, x, yo, y))
			{
				Game[y][x] = Game[yo][xo];
				Game[yo][xo] = 254;
				return 1;
			}
		}
	}
	return 0;
}
bool H(bool player, int xo, int yo, int x, int y)
{
	if (IsMovingHisPawn(player, xo, yo) && NotPawnOfSamePlayer(player, x, y))
	{
		if ((y == yo - 2 || y == yo + 2) && (x == xo - 1 || x == xo + 1))
		{
			Game[y][x] = Game[yo][xo];
			Game[yo][xo] = 254;
			return 1;
		}
		else if ((y == yo - 1 || y == yo + 1) && (x == xo - 2 || x == xo + 2))
		{
			Game[y][x] = Game[yo][xo];
			Game[yo][xo] = 254;
			return 1;
		}
	}
	return 0;
}
bool C(bool player, int xo, int yo, int x, int y)
{
	if (IsMovingHisPawn(player, xo, yo) && NotPawnOfSamePlayer(player, x, y))
	{
		if (y == yo)
		{
			if (CheckStraightMove(0, xo, yo, x, y))
			{
				Game[y][x] = Game[yo][xo];
				Game[yo][xo] = 254;
				return 1;
			}
		}
		else if (x == xo)
		{
			if (CheckStraightMove(1, xo, yo, x, y))
			{
				Game[y][x] = Game[yo][xo];
				Game[yo][xo] = 254;
				return 1;
			}
		}
	}
	return 0;
}
bool S(bool player, int xo, int yo, int x, int y)
{
	if (IsMovingHisPawn(player, xo, yo) && NotPawnOfSamePlayer(player, x, y))
	{
		if (!player)
		{
			if ((y == yo - 1 && x == xo) || (yo == 6 && y == yo - 2 && x == xo))
			{
				Game[y][x] = Game[yo][xo];
				Game[yo][xo] = 254;
				return 1;
			}
			else if (y == yo - 1 && (x == xo - 1 || x == xo + 1))
			{
				if (Game[y][x] != char(254))
				{
					Game[y][x] = Game[yo][xo];
					Game[yo][xo] = 254;
					return 1;
				}
			}
		}
		else
		{
			if ((y == yo + 1 && x == xo) || (yo == 1 && y == yo + 2 && x == xo))
			{
				Game[y][x] = Game[yo][xo];
				Game[yo][xo] = 254;
				return 1;
			}
			else if (y == yo + 1 && (x == xo - 1 || x == xo + 1))
			{
				if (Game[y][x] != char(254))
				{
					Game[y][x] = Game[yo][xo];
					Game[yo][xo] = 254;
					return 1;
				}
			}
		}
	}
	return 0;
}