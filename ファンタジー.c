#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int intelligence, stamina, charisma;
    int remaining = 20;
    
    srand(time(0));
    
    intelligence = rand() % (remaining +1);
    remaining = intelligence;
    
    stamina = rand() % (remaining +1);
    remaining = stamina;
    
    charisma = remaining;
    
    printf("--- ステータス---\n");
    printf("itelligence: %d\n", intelligence);
    printf("stamina:     %d\n", stamina);
    printf("charisma:    %d\n", charisma);
    printf("-----------------\n");
    
    if (intelligence >=stamina & intelligence >=charisma) {
        printf("クラス: 魔法使い　[mage]\n");
    }else if (stamina >= intelligence & stamina >= charisma){
        printf("クラス:ファイター系[knight]\n");
    }else{
        printf("クラス: 盗人系[thief]\n");
    }

    return 0;
}