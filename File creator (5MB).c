#include <stdio.h>
int main(void) 
{
        int Size = 5 * 1024 * 1024 - 1;
        FILE *fp = fopen("random file", "w");
        fseek(fp, Size , SEEK_SET);
        fputc('\0', fp);
        fclose(fp);
}