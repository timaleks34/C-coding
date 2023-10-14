#include <stdio.h>
#include <math.h>
int main ()
{
    float r,h,v;
            printf ("введите радиус и высоту");
            scanf ("%f%f",&r,&h);
            v=3.14*r*r*h;
            printf ("v=%f",v);
    return 0;
}
