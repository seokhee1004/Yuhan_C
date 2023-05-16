#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int print_title_screen()
{
	char menu[465];
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

//test sun
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
	char msg[20]="Eat Survival";
	int j=0;
	while (j<strlen(msg))
	{
		menu[j+(30/2)-(strlen(msg)/2)+31*2]=msg[j];
		j++;
	}


	char msg1[10]="V.0.1";
	int a=0;
	while (a<strlen(msg1))
	{
		menu[a+(30/2)-(strlen(msg1)/2)+31*3]=msg1[a];
		a++;
	}

	char msg2[20]="1. Start Game";
	int b=0;
	while (b<strlen(msg2))
	{
		menu[b+(30/3/2)+31*7]=msg2[b];
		b++;
	}


	char msg3[20]="2. How to Play";
	int c=0;
	while (c<strlen(msg3))
	{
		menu[c+(30/3/2)+31*8]=msg3[c];
		c++;
	}


	char msg4[20]="3. Exit";
	int d=0;
	while (d<strlen(msg4))
	{
		menu[d+(30/3/2)+31*9]=msg4[d];
		d++;
	}
	
	printf("%s",menu);
	

	return 0;
}

int print_how_to_play_screen()
{

	char menu[465];
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
	char msg[30]="Survive from hunger";
	int j=0;
	while (j<strlen(msg))
	{
		menu[j+(30/2)-(strlen(msg)/2)+31*6]=msg[j];
		j++;
	}


	char msg1[30]="Press w,a,s,d to move";
	int a=0;
	while (a<strlen(msg1))
	{
		menu[a+(30/2)-(strlen(msg1)/2)+31*8]=msg1[a];
		a++;
	}


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
				printf("\ninput>");
				scanf("%d", &game_state);

			}
		else if(game_state == 2)
			{
				system("cls");
				print_how_to_play_screen();
				printf("\nReturn to menu? (1.yes 2.no)");
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
				printf("Are you sure Exit? (1.yes 2.no)");
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
