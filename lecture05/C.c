#include <windows.h>
#include <stdio.h>
int print_title_screen()
{
	printf("############################\n");
	printf("##                        ##\n");
	printf("##       Dino Run         ##\n");
	printf("##         V.0.1          ##\n");
	printf("##                        ##\n");
	printf("##     1.Start Game       ##\n");
	printf("##     2.How to Play      ##\n");
	printf("##     3. Exit            ##\n");
	printf("############################\n");



	return 0;}

int print_how_to_play_screen()
{
	printf("############################\n");
	printf("##                         ##\n");
	printf("##    ��� ���� ������      ##\n");
	printf("##   ��� �Ͻðڽ��ϱ�?     ##\n");
	printf("##  ���� �ʴ� �� �����մϴ� ##\n");
	printf("##    ����� �Ȱŵ��.     ##\n");
	printf("##                        ##\n");
	printf("############################\n");
	return 0;
}
int main()
{
	int game_state = 1;
	
	while(game_state)
	{
		int input;
		int N =0;
		if(game_state ==1){
			print_title_screen();
			printf("input>");
			scanf("%d", &input);
			if(input == 1)
			{	
				game_state = 1;
				continue;
			}
			else if(input == 2){
				game_state = 2;
				continue;
			}
			else if(input == 3){
				game_state = 3;
				continue;
			}
			
			
			
				
		}
		else if (game_state == 2){
			print_how_to_play_screen();
			printf("return to menu?(1.yes 2.no)");
			scanf("%d", &input);

			if(input==1) 
			{
				game_state = 1;
				continue;
			}

			else if(input==2)
			{
				continue;
			}
			else
				continue;

		
		}
		
		else if( game_state == 3)
		{
			system("cls");
			printf("���� ������ �����Ͻðڽ��ϱ�? :  1.yes  2. no");
			scanf("%d",&N);
			if(N ==1)
			{
				return 0;
			}
			else if (N == 2)
			{
				game_state =1;

			}
		
		}
		
		

	}
	return 0;
}
