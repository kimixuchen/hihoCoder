/**
 * hihoCoder-week77-Korch Snowflake
 * 20/12/15 10:25:40
 * xuchen
**/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    int T, i, n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &i, &n);
        while(i%4==1 || i%4==0)
        {
            if(i==1)
            {
                n=0;
                break;
            }
            n--;
            i = (i+3)/4;
        }
        printf("%d\n", n);
    }
    return 0;
}

