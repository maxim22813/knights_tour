#include <iostream>
#define D 7

int desk[D][D];
int step[8][2] = { {1,-2}, {2,-1}, {2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2} };
int n;

bool move_horse(int x, int y)
{
	if ((x < 0) || (x >= D) || (y < 0) || (y >= D))
		return false;

	if (desk[x][y] != 0)
		return false;

	n++;
	desk[x][y] = n;

	if (n == D * D)
		return true;

	for (int i = 0; i < 8; i++)
		if (move_horse(x + step[i][0], y + step[i][1]))
			return true;
	n--;
	desk[x][y] = 0;

	return false;
}

void print_result()
{
	printf("n=%d\n\n", n);
	for (int i = 0; i < D; i++)
	{
		for (int j = 0; j < D; j++)
			printf(" %2d", desk[i][j]);
		printf("\n");
	}
}

int main()
{
	move_horse(6, 6);

	print_result();
}
