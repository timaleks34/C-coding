#include <stdio.h>
#include <stdlib.h>

int main()
{
    int days;
    int weeks;
    int years, months, hours, minutes, seconds;
    printf("введите чесло дней\n");
    scanf("%d", &days);
    hours=days*24;
    minutes=hours*60;
    seconds=minutes*60;
    weeks=(days-days%7)/7;
    months=(days-days%30)/30;
    years=(days-days%365)/365;
    printf("%d\n",seconds);
    printf("%d\n",minutes);
    printf("%d\n",hours);
    printf("%d\n",weeks);
    printf("%d\n",months);
    printf("%d\n",years);

}