#include "head.h"
void menu()
{
	printf("       Mine Sweeping       \n    1.play       0.exit\n");
}

void game()
{
	char backstage[ROWS][COLS] = { 0 };
	char clientside[ROWS][COLS] = { 0 };
	Initialization(backstage, ROWS, COLS, '0');
	Initialization(clientside, ROWS, COLS, '*');
	Display(clientside, ROW, COL);
	SetMine(backstage, ROW, COL);
	FindMine(backstage, clientside, ROW, COL);
}

	int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			game();
			break;
		case 0:
			system("cls");
			printf("�����˳���Ϸ...");
			Sleep(1000);
			system("cls");
			break;
		default:
			system("cls");
			printf("�޷�ʶ�����������룡");
			Sleep(1000);
			system("cls");
			break;
		}
	} while (input);
		return 0;
}


	
