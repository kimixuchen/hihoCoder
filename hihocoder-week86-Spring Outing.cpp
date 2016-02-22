/**
 * hihocoder-week86-Spring Outing
 * 22/02/16 09:36:01
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


const int N = 1005;
int trank[N][N];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int t;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=k; j++)
        {
            scanf("%d", &t);
            trank[i][t] = j;
        }
    }

    int result = 0;
    for(int i=k; i>0; i--)
    {
        int vote = 0;
        for(int j=0; j<n; j++)
        {
            if(trank[j][i] < trank[j][result])
            {
                vote++;
            }
            
            if(vote > n/2)
                result = i;
        }
    }
    if(result > 0)
        printf("%d\n", result);
    else
        printf("otaku\n");

    return 0;
}

