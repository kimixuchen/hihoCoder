/**
hihocoder-OfferExercise3-C
28/03/16 18:17:50
xuchen
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
#include <map>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1005;

int a[N];
int dp[N][N];
int q, n, m, s, t, sum;

bool isok()
{
    if(m*s < sum)
        return false;

    return true;
}

int main()
{
    int ans;
    scanf("%d", &q);
    while(q--)
    {
        ans = INF;
        sum = 0;
        memset(a, 0, sizeof(a));
        scanf("%d %d %d %d", &n, &m, &s, &t);
        for(int i=1; i<=n; ++i)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        if(!isok())
        {
            printf("No\n");
            continue;
        }
        for(int i=0; i<=n; ++i)
            for(int j=0; j<=m; ++j)
                dp[i][j] = INF;
        for(int j=0; j<=m; ++j)
            dp[0][j] = 0;
        
        int q;
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=m; ++j)
            {
                for(int k=0; k<=j; ++k)
                {
                    if(a[i] < k*t)
                    {
                        dp[i][j] = min(dp[i][j], dp[i-1][j-k]);
                        break;
                    }
                    q = (a[i]-k*t)/s;
                    if((a[i]-k*t)%s != 0)
                        ++q;
                    if(k+q <= j)
                    {
                        dp[i][j] = min(dp[i][j], dp[i-1][j-q-k]+q);
                    }
                }
            }
        }
        if(dp[n][m] == INF)
            printf("No\n");
        else
            printf("%d\n", dp[n][m]);
    }

    return 0;
}

