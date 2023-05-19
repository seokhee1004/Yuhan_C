#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char menu[465];
int writeStringToBuffer(const char* string, int x, int y)
{
	int i=0;
	while (i<strlen(string))
	{
		menu[i+x+31*y]=string[i];
		i++;
	}

}

int print_title_screen()
{
	
	int i=0;
	// 가로가 0부터 30까지 칸은 총 31개 31번째는 계행문자
	while(i<465)
	{
		int x=i%31;
		int y=i/31;

		if(x==30)
		{
			menu[i]='\n';
		}


		else if(x==0 || x==29 || y==0 || y==14)
		{
			menu[i]='#';
		}
		

		

		else
		{
			menu[i]=' ';
		}

		i=i+1;
	}
	
	menu[464]='\0';


	writeStringToBuffer("Eat Survival",9,2);
	writeStringToBuffer("V.0.1",12,3);
	writeStringToBuffer("1. Start Game",5,7);
	writeStringToBuffer("2. How to Play",5,8);
	writeStringToBuffer("3. Exit",5,9);
	
	printf("%s",menu);
	

	return 0;
}

int print_how_to_play_screen()
{

	
	int i=0;
	// 가로가 0부터 30까지 칸은 총 31개 31번째는 계행문자
	while(i<465)
	{
		int x=i%31;
		int y=i/31;

		if(x==30)
		{
			menu[i]='\n';
		}


		else if(x==0 || x==29 || y==0 || y==14)
		{
			menu[i]='#';
		}
		

		

		else
		{
			menu[i]=' ';
		}

		i=i+1;
	}



	writeStringToBuffer("Survive from hunger",6,6);
	writeStringToBuffer("Press w,a,s,d to move",5,8);
	writeStringToBuffer("Retrun to menu?",8,11);
	writeStringToBuffer("1.yes 2.no",10,12);
	


	printf("%s",menu);
	
	

	return 0;	
}





int Exit_screen()
{
	
	int i=0;
	// 가로가 0부터 30까지 칸은 총 31개 31번째는 계행문자
	while(i<465)
	{
		int x=i%31;
		int y=i/31;

		if(x==30)
		{
			menu[i]='\n';
		}


		else if(x==0 || x==29 || y==0 || y==14)
		{
			menu[i]='#';
		}
		

		

		else
		{
			menu[i]=' ';
		}

		i=i+1;
	}
	
	menu[464]='\0';


	writeStringToBuffer("Are you sure Exit?",6,6);
	writeStringToBuffer("1.yes 2.no",10,7);
	
	printf("%s",menu);
	

	return 0;
}




int main()
{
	

	int game_state = 1;

	while(game_state)
	{
			

		if(game_state == 1)
			{
				system("cls");
				print_title_screen();
				scanf("%d", &game_state);

			}
		else if(game_state == 2)
			{
				system("cls");
				print_how_to_play_screen();
				scanf("%d",&game_state);

				if(game_state == 1)
				{
					game_state=1;
				}

				else if(game_state == 2)
				{
					game_state=2;
				}

				else
				{
					system("cls");
					game_state=2;
				}
			}
		else if(game_state == 3)
			{
				system("cls");
				Exit_screen();
				scanf("%d",&game_state);
				if(game_state == 1)
				{
					game_state=0;
				}
				else if(game_state == 2)
				{
					game_state=1;
				}

				else
				{
					system("cls");
					game_state=3;
				}
			}
		else
		{
			system("cls");
			game_state=1;

		}
		
		
		
	}


	return 0;
}

