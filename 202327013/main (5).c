#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
char menu[465];
char map[40][40*2];
void GotoXY(int x, int y){
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	//콘솔에 정해진 값에 초기화 
}
void hideCursor() {
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        cursorInfo.dwSize = 1;
        cursorInfo.bVisible = FALSE;
        SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
void writeStringToBuffer(const char* string, int x, int y)
{
	int i=0;
	while (i<strlen(string))
	{
		GotoXY(0, 0);
		Sleep(16);
		menu[i+x+31*y]=string[i];
		printf("%s\n", menu);
		i++;
	}
}
void StringToBuffer(const char* string, int x, int y) {
	int i = 0;
	while (i < strlen(string))
	{
		map[y][x+i] = string[i];
		i++;
	}
}
void setConsoleColor(unsigned textColor, unsigned backColor) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor | (backColor << 4));
}

void mapBuffer(){

	for(int y=0;y<40;y++)
	{
		for(int x=0;x<80;x++)
		{
			if (x%80==79)
			{
				map[y][x]='\n';
			}
			else if(x==0||x==78||y==0||y==39)
			{
				map[y][x]='#';
			}
			else
			{
				map[y][x]=' ';
			}
			
		}
	}

	map[39][79]='\0';
}

int Game_Operation()
{
    //게임시작 시 위치 선정

	
    int playerX = 3;
    int playerY = 3;

	int objectX = 0;
	int objectY = 0;
	int object1X = 0;
	int object1Y = 0;
	int object2X = 0;
	int object2Y = 0;

	int currentTick = 0;
	int lastTick = 0;
	int lastCreateTick = 0;
	int lastCreateTick1 = 0;
	int lastCreateTick2 = 0;
	int lastScoreTick = 0;

	int score = 10;

	int second1 =10000;
	int second2 =10000;
	int second3 =10000;
	int Movingspeed = 1000/40;


	objectX = rand() % 40 * 2 - 2;
	objectY = rand() % 40 - 2;
	object1X = rand() % 40 * 2 - 2;
	object1Y = rand() % 40 - 2;
	object2X = rand() % 40 * 2 - 2;
	object2Y = rand() % 40 - 2;
	
	if (objectX > 40 * 2 - 2)
		objectX = 40 * 2 - 2;
	if (objectY > 40 - 2)
		objectY = 40 - 2;
	if (objectX < 1)
		objectX = 1;
	if (objectY < 1)
		objectY = 1;

	if (object1X > 40 * 2 - 2)
		object1X = 40 * 2 - 2;
	if (object1Y > 40 - 2)
		object1Y = 40 - 2;
	if (object1X < 1)
		object1X = 1;
	if (object1Y < 1)
		object1Y = 1;

	if (object2X > 40 * 2 - 2)
		object2X = 40 * 2 - 2;
	if (object2Y > 40 - 2)
		object2Y = 40 - 2;
	if (object2X < 1)
		object2X = 1;
	if (object2Y < 1)
		object2Y = 1;

	while (score) 
	{	

		hideCursor();
			// Input
		currentTick = GetTickCount64();
		if (currentTick - lastTick >Movingspeed)
		{
			if (GetAsyncKeyState(VK_LEFT) & 0x8000) { // 왼쪽
				if (playerX > 1)
					playerX = playerX - 1;
			}
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000) { // 오른쪽
				if (playerX + 1 < 40*2-2)
					playerX = playerX + 1;
			}
			if (GetAsyncKeyState(VK_UP) & 0x8000) { // 위
				if (playerY > 1)
					playerY = playerY - 1;
			}
			if (GetAsyncKeyState(VK_DOWN) & 0x8000) { // 아래
				if (playerY + 1 < 39)
					playerY = playerY + 1;
			}

			lastTick = currentTick;
		}
		if (objectX == playerX && objectY == playerY) {
			score=score+2;
			Movingspeed=Movingspeed-2;
			second1=second1-1000;
			if(second1<1)
				second1=1;

			objectX = rand() % 40 * 2 - 2;
			objectY = rand() % 40 - 2;

			if (objectX > 40 * 2 - 2)
				objectX = 40 * 2 - 2;
			if (objectY > 40 - 2)
				objectY = 40 - 2;
			if (objectX < 1)
				objectX = 1;
			if (objectY < 1)
				objectY = 1;

			lastCreateTick = currentTick;
		}
		else if (currentTick -  lastCreateTick > second1) {
			objectX = rand() % 40 * 2 - 2;
			objectY = rand() % 40 - 2;

			if (objectX > 40 * 2 - 2)
				objectX = 40 * 2 - 2;
			if (objectY > 40 - 2)
				objectY = 40 - 2;
			if (objectX < 1)
				objectX = 1;
			if (objectY < 1)
				objectY = 1;

			lastCreateTick = currentTick;
		}
		if (object1X == playerX && object1Y == playerY) {
			score=score+2;
			Movingspeed=Movingspeed-2;
			second2=second2-1000;

			if(second2<1)
			second2=1;

			object1X = rand() % 40 * 2 - 2;
			object1Y = rand() % 40 - 2;

			if (object1X > 40 * 2 - 2)
				object1X = 40 * 2 - 2;
			if (object1Y > 40 - 2)
				object1Y = 40 - 2;
			if (object1X < 1)
				object1X = 1;
			if (object1Y < 1)
				object1Y = 1;

			lastCreateTick = currentTick;
		}
		else if (currentTick -  lastCreateTick1 > second2) {
			object1X = rand() % 40 * 2 - 2;
			object1Y = rand() % 40 - 2;

			if (object1X > 40 * 2 - 2)
				object1X = 40 * 2 - 2;
			if (object1Y > 40 - 2)
				object1Y = 40 - 2;
			if (object1X < 1)
				object1X = 1;
			if (object1Y < 1)
				object1Y = 1;

			lastCreateTick1 = currentTick;
		}		
		if (object2X == playerX && object2Y == playerY) {
			score=score+2;
			Movingspeed=Movingspeed-2;
			second3=second3-1000;

			if(second3<1)
			second3=1;

			object2X = rand() % 40 * 2 - 2;
			object2Y = rand() % 40 - 2;

			if (object2X > 40 * 2 - 2)
				object2X = 40 * 2 - 2;
			if (object2Y > 40 - 2)
				object2Y = 40 - 2;
			if (object2X < 1)
				object2X = 1;
			if (object2Y < 1)
				object2Y = 1;

			lastCreateTick = currentTick;
		}
		else if (currentTick -  lastCreateTick2 > second3) {
			object2X = rand() % 40 * 2 - 2;
			object2Y = rand() % 40 - 2;

			if (object2X > 40 * 2 - 2)
				object2X = 40 * 2 - 2;
			if (object2Y > 40 - 2)
				object2Y = 40 - 2;
			if (object2X < 1)
				object2X = 1;
			if (object2Y < 1)
				object2Y = 1;

			lastCreateTick2 = currentTick;
		}
		if (currentTick - lastScoreTick > 2000) {
            score=score-1;
            lastScoreTick = currentTick;
        }
		
		
		mapBuffer();
		StringToBuffer("F", objectX, objectY);
		StringToBuffer("A", object1X, object1Y);
		StringToBuffer("B", object2X, object2Y);
		StringToBuffer("P",playerX,playerY);
		char score1[30];
		sprintf(score1,"Hungry score : %d", score);
		StringToBuffer(score1,1,1);
		
		GotoXY(0,0);
		for (int y = 0; y < 40; y++)
		{
			for (int x = 0; x < 40 * 2; x++)
			{
				if (map[y][x] == 'P') {
					setConsoleColor(11,0);
					printf("%c", map[y][x]);
					setConsoleColor(15,0);
				}
				else if (map[y][x] == 'F') {
					// 다른 색 넣기
					setConsoleColor(5,5);
					printf("%c", map[y][x]);
					// 원래 색으로 되돌리기
					setConsoleColor(15,0);
				}
				else if (map[y][x] == 'A') {
					// 다른 색 넣기
					setConsoleColor(5,5);
					printf("%c", map[y][x]);
					// 원래 색으로 되돌리기
					setConsoleColor(15,0);
				}
				else if (map[y][x] == 'B') {
					// 다른 색 넣기
					setConsoleColor(5,5);
					printf("%c", map[y][x]);
					// 원래 색으로 되돌리기
					setConsoleColor(15,0);
				}
				else {
					printf("%c", map[y][x]);
					
				}

			}
		}
		
        
    }
	GotoXY(0,0);
	mapBuffer();
	StringToBuffer("Game Over!",35,20);
	printf("%s",map);
	Sleep(3000);
    return 0;
}

int clear_screen()
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
	return 0;
}


int main()
{
	clock_t start,end;
	start=clock();
	int cpu_time;
	int inputValue = 0;
	int game_state = 1;
	int game_play =1;
	setConsoleColor(15,0);
	clear_screen();
	writeStringToBuffer("Loding...",6,6);
	Sleep(2000);

	while(game_state)
	{
		
		
		setConsoleColor(15,0);
		GotoXY(0, 0);
		clear_screen();

		
		if(game_state == 1){
			writeStringToBuffer("Eat Survival",9,2);
			writeStringToBuffer("V.0.1",12,3);
			writeStringToBuffer("1. Start Game",5,7);
			writeStringToBuffer("2. How to Play",5,8);
			writeStringToBuffer("3. Exit",5,9);
		}
		else if(game_state == 2){
			writeStringToBuffer("Survive from hunger",6,6);
			writeStringToBuffer("Press the arrow key to move",1,8);
			writeStringToBuffer("Retrun to menu?",8,11);
			writeStringToBuffer("1.yes 2.no",10,12);
		}
		else if(game_state == 3){
			writeStringToBuffer("Are you sure Exit?",6,6);
			writeStringToBuffer("1.yes 2.no",10,7);
		}
		
		GotoXY(0, 15);
		scanf("%d", &inputValue);
		system("cls");
		
		
		
		// 메인메뉴에서 입력을 처리함
		if (game_state == 1){
			if (inputValue == 1){
				system("cls");
				Game_Operation();
				system("cls");
				setConsoleColor(15,0);
				game_state=1;
				
			}
				
			else if (inputValue == 2)
				game_state = 2;
			else if (inputValue == 3)
				game_state = 3;
		}
		else if (game_state == 2){
			if (inputValue == 1)
				game_state = 1;
			else if(inputValue==2)
				game_state = 2;
			else
				game_state =2;
				
		}
		else if (game_state == 3){
			if (inputValue == 1){
				clear_screen();
				end = clock();
				cpu_time=((int)(end-start)/CLOCKS_PER_SEC);
				char time[20];
				sprintf(time,"%d",cpu_time);
				writeStringToBuffer("Program execution time",3,6);
				writeStringToBuffer(time,25,6);
				Sleep(1000);
				writeStringToBuffer("Exit...",6,9);
				Sleep(2000);
				game_state = 0;
			}
			else if (inputValue == 2)
				game_state = 1;
			else
				game_state =3;
		}

	}
	
	return 0;
}
