/*======================================================
    > File Name: road.c
    > Author: lyh
    > E-mail:  
    > Other :  
    > Created Time: 2016年04月08日 星期五 20时10分43秒
 =======================================================*/

#include<stdio.h>

typedef struct Point
{
    int x;
    int y;
}Point;

int result[100];

int get_d(Point s,Point t)
{
    int   d,i;
    int   d1,d2;
    if(s.x == t.x && s.y < t.y)
    {   
        d = t.y-s.y;
        for(i=0;i<d;i++)
            result[i] = 2;
    }
    if(s.x == t.x && s.y > t.y)
    {
        d = s.y-t.y;
        for(i=0;i<d;i++)
            result[i] = 3;
    }
    if(s.y == t.y && s.x > t.x)
    {
        d = s.x-t.x;
        for(i=0;i<d;i++)
            result[i] = 0;
    }
    if(s.y == t.y && s.x < t.x)
    {
        d = t.x-s.x;
        for(i=0;i<d;i++)
            result[i] = 1;
    }
    if(s.x < t.x && s.y < t.y)
    {
        if(t.x-s.x > t.y-s.y)
        {
            d1 = t.y-s.y;
            d2 = t.x-s.x-d1;
            d = d1+d2;
            for(i=0;i<d1;i++)
                result[i] = 6;
            for(;i<d;i++)
                result[i] = 2;
        }
        else
        {
            d1 = t.x-s.x;
            d2 = t.y-s.y-d1;
            d = d1+d2;
            for(i=0;i<d1;i++)
                result[i] = 6;
            for(;i<d;i++)
                result[i] = 1;
        }
    }
    if(s.x < t.x && s.y > t.y)
    {
        if(t.x-s.x > s.y-t.y)
        {
            d1 = s.y-t.y;
            d2 = t.x-s.x-d1;
            d = d1+d2;
            for(i=0;i<d1;i++)
                result[i] = 7;
            for(;i<d;i++)
                result[i] = 1;
        }
        else
        {
            d1 = t.x-s.x;
            d2 = s.y-t.y-d1;
            d = d1+d2;
            for(i=0;i<d1;i++)
                result[i] = 7;
            for(;i<d;i++)
                result[i] = 3;
        }
    }
    if(s.x > t.x && s.y < t.y)
    {
        if(s.x-t.x > t.y-s.y)
        {
            d1 = t.y-s.y;
            d2 = s.x-t.x-d1;
            d = d1+d2;
            for(i=0;i<d1;i++)
                result[i] = 4;
            for(;i<d;i++)
                result[i] = 0;
        }
        else
        {
            d1 = s.x-t.x;
            d2 = t.y-s.y-d1;
            d = d1+d2;
            for(i=0;i<d1;i++)
                result[i] = 4;
            for(;i<d;i++)
                result[i] = 2;
        }
    }
    if(s.x > t.x && s.y > t.y)
    {
        if(s.x-t.x > s.y-t.y)
        {
            d1 = s.y-t.y;
            d2 = s.x-t.x-d1;
            d = d1+d2;
            for(i=0;i<d1;i++)
                result[i] = 5;
            for(;i<d;i++)
                result[i] = 0;
        }
        else
        {
            d1 = s.x-t.x;
            d2 = s.y-t.y-d1;
            d = d1+d2;
            for(i=0;i<d1;i++)
                result[i] = 5;
            for(;i<d;i++)
                result[i] = 3;
        }

    }
    return d;
}

void print(int flag)
{
    if(flag == 0)
        printf("L\n");
    if(flag == 1)
        printf("R\n");
    if(flag == 2)
        printf("U\n");
    if(flag == 3)
        printf("D\n");
    if(flag == 4)
        printf("LU\n");
    if(flag == 5)
        printf("LD\n");
    if(flag == 6)
        printf("RU\n");
    if(flag == 7)
        printf("RD\n");
}

int main()
{
    int   d,i;
    Point  s,t;
    char sp[3];
    scanf("%s",sp);
    s.x = sp[0]-'a'+1;
    s.y = sp[1]-'0';
    scanf("%s",sp);
    t.x = sp[0]-'a'+1;
    t.y = sp[1]-'0';
    d = get_d(s,t);
    printf("%d\n",d);
    for(i=0;i<d;i++)
        print(result[i]);
}
