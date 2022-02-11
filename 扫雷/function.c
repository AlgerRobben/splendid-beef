#include "head.h"
void Initialization(char arr[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for(i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}

void Display(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
		    printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char arr[ROWS][COLS], int row, int col)
{
	int mine = EASY_COUNT;
	while (mine)
	{
		int i = rand() % row + 1;
		int j = rand() % col + 1;
		if (arr[i][j] == '0')
		{
			arr[i][j] = '1';
			mine--;
		}
	}
}

void FindMine(char backstage[ROWS][COLS], char clientside[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int win = 0;
	while (win<row*col-EASY_COUNT)
	{
		printf("请输入坐标：");
		scanf("%d%d", &i, &j);
		if ((0 < i && i <= row) && (0<j && j <= col))
		{
			if(backstage[i][j]!='1')
			{
				system("cls");
				int count = Mindcount(backstage,i,j );
				clientside[i][j] = '0'+count;
				Display(clientside, row, col);
				win++;
			}
			else
			{
				system("cls");
				clientside[i][j] = '#';
				Display(clientside, row, col);
				printf("Boom!Game Over!\n");
				Sleep(1000);
				system("cls");
				break;
			}
		}
		else
		{
			printf("无法识别坐标，请重新输入！");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("排雷成功！\n");
		Sleep(1000);
		system("cls");
	}
}

int Mindcount(char backstage[ROWS][COLS],int i,int j)
{
	int a = 0;
	int b = 0;
	int count = 0;
	for (a = i - 1; a <= i + 1; a++)
	{
		for (b = j - 1; b <= j + 1; b++)
		{
			if (backstage[a][b] == '1')
			{
				count++;
			}
		}
	}
	return count;
}