#include <stdio.h>
#include <stdlib.h>

int main()
{
    int days;
    int weeks;
    int years, months, hours, minutes, seconds;
    printf("введите чесло дней\n");
    scanf("%d", &days);
    years=(days-days%365)/365;
    months=(days-years*365)/30;
    weeks=(days-years*365-months*30)/7;
    days=days-years*365-months*30-weeks*7;
    printf("%d\n",weeks);
    printf("%d\n",months);
    printf("%d\n",years);

}