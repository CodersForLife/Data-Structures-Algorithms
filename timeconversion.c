#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main()
{
    int hh,mm,ss;
    scanf("%d:%d:%d",&hh,&mm,&ss);
    char a[2];
    scanf("%s",a);
    if(strcmp(a,"PM")==0)
    {
        if(hh==12)
        {
            hh=hh+0;
        }
        else
        {
        hh=hh+12;
        }
    }
    if(strcmp(a,"AM")==0)
    {
        if(hh==12)
        {
            hh=0;
        }
        else
        {
        hh=hh+0;
        }
    }
    printf("%02d:%02d:%02d",hh,mm,ss);
    return 0;

}
