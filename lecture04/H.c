#include <stdio.h>

int main()
{	
	int hp=30;
	int at =0;
	printf("주인공의 공격력을 입력하세요:");
	scanf("%d",&at);
	int b= hp-at;

	if(at>30)
	{	
		printf("주인공의 공격력은 %d입니다.\n주인공이 적을 공격하여 %d의 데미지를 입혔습니다.\n적의 잔여HP : 0 \n적을 물리쳤습니다!\n Happy End",at);

	}

	else
	{
		printf("주인공의 공격력이 %d입니다.\n주인공이적을 공격하여 %d의 데미지를 입혔습니다.\n잔여HP :%d  적이주인공을 공격하여 뒤졌습니다.\nGame Over",at,at,b);
	}
		return 0;
}
