/**
 *hihocoder Œ¢»Ì2016.4 C
 *09/04/16 15:43:24
 *xuchen
 * */
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 105;

int dp1[N][N]; //to right
int dp2[N][N]; //to down
char a[N][N];

int main()
{
    int n, m;
    char s[N];
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; ++i)
    {
        scanf("%s", s);
        for(int j=0; j<m; ++j)
        {
            a[i][j] = s[j];
        }
    }
    //init first point
    dp1[0][0] = 0;
    if(a[0][0]=='b')
    {
        dp1[0][0] = 1;
    }
    
    if(n>1 && a[0][1]=='b')
    {
        dp2[0][0] = dp1[0][0];
    }
    else
    {
        dp2[0][0] = dp1[0][0]+1;
    }
    //init first row
    for(int i=1; i<m; ++i)
    {
        if(a[0][i] == 'b')
            dp1[0][i] = dp1[0][i-1] + 1;
        else
            dp1[0][i] = dp1[0][i-1];
        if(i+1==m || a[0][i+1]=='b')
            dp2[0][i] = dp1[0][i];
        else
            dp2[0][i] = dp1[0][i] + 1;
    }
    //init first col
    for(int i=1; i<n; ++i)
    {
        if(a[i][0] == 'b')
            dp2[i][0] = dp2[i-1][0] + 1;
        else
            dp2[i][0] = dp2[i-1][0];
        if(i+1==n || a[i+1][0]=='b')
            dp1[i][0] = dp2[i][0];
        else
            dp1[i][0] = dp2[i][0]+1;
    }
    //next
    int right1, right2;
    int down1, down2;
    for(int i=1; i<n; ++i)
    {
        for(int j=1; j<m; ++j)
        {
            //upper point
            if(a[i][j]=='b')
                down1 = dp2[i-1][j]+1;
            else
                down1 = dp2[i-1][j];
            if(i+1==n || a[i+1][j]=='b')
                right1 = down1;
            else
                right1 = down1+1;
            //left point
            if(a[i][j]=='b')
                right2 = dp1[i][j-1]+1;
            else
                right2 = dp1[i][j-1];
            if(j+1==m || a[i][j+1]=='b')
                down2 = right2;
            else
                down2 = right2+1;
            dp1[i][j] = min(right1, right2);
            dp2[i][j] = min(down1, down2);
        }
    }
    printf("%d\n", min(dp1[n-1][m-1], dp2[n-1][m-1]));


    return 0;
}
