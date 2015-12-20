/**
 * hihoCoder-week76-Suzhou Adventure
 * 13/12/15 18:29:00
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

const int N = 105;
const int INVALID = 50000;
struct node{
    int to;
    int next;
};
bool must[N];
int recos[N];
int dp[N][N];
int attr[N];
int heads[N];
node edges[N];
int n, k, m;
int cnt=0;

void addEdge(int from, int to)
{
    cnt++;
    edges[cnt].to = to;
    edges[cnt].next = heads[from];
    heads[from] = cnt;
}

bool isReco(int x)
{
    for(int i=0; i<k; i++) 
        if(recos[i]==x)
            return true;
    return false;
}
int mark(int root)
{
    int mustNum=0;
    int visRecoNum = 0;
    queue<int> q;
    bool vis[N];
    int pre[N];
    memset(vis, false, sizeof(vis));
    memset(pre, 0, sizeof(pre));
    q.push(root);
    vis[root]=true;
    while(!q.empty())
    {
        if(visRecoNum == k)
            break;
        int cur = q.front();
        q.pop();
        for(int i=heads[cur]; i!=0; i = edges[i].next)
        {
            if(vis[edges[i].to])
                continue;
            vis[edges[i].to] = true;
            q.push(edges[i].to);
            pre[edges[i].to] = cur;
            if(isReco(edges[i].to))
                visRecoNum++;
            
        }
    }
    for(int i=0; i<k; i++)
    {
        int pos = recos[i];
        while(pos!=0)
        {
            must[pos] = true;
            pos = pre[pos];
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(must[i])
            mustNum++;
    }
    return mustNum;

}
int getChildNum(int root)
{
    int num=0;
    for(int i=heads[root]; i!=0; i=edges[i].next)
    {
        num++;
    }
    return num;
}
int travel(int root, int num)
{
    if(num==0)
    {
        if(must[root])
            return INVALID;
        return 0;
    }
    
    if(dp[root][num]!=-1)
        return dp[root][num];

    //don't choose this node
    if(must[root])
        dp[root][num] = INVALID;
    else
        dp[root][num] = 0;

    int g[N][N];
    memset(g, 0, sizeof(g));
    int childNum=0;
    int childs[N];
    for(int i=heads[root]; i!=0; i=edges[i].next)
    {
        childNum++;
        childs[childNum] = edges[i].to;
    }

    for(int i=1; i<=childNum; i++)
    {
        for(int j=0; j<=num-1; j++)
        {
            g[i][j] = INVALID;
            for(int t=0; t<=j; t++)
            {
                if(travel(childs[i], t)!=INVALID && g[i-1][j-t]!=INVALID)
                {
                    if(g[i][j]==INVALID || 
                            g[i][j] < travel(childs[i], t)+g[i-1][j-t])
                    {
                        g[i][j] = travel(childs[i], t)+g[i-1][j-t];
                    }
                }
            }
            
        }
    }
    if(g[childNum][num-1]==INVALID)
        dp[root][num] = INVALID;
    else
        dp[root][num] = g[childNum][num-1]+attr[root];

    //printf("dp[%d][%d]=%d\n", root, num, dp[root][num]);
    return dp[root][num];
    
}
int main()
{
    scanf("%d%d%d", &n, &k, &m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &attr[i]);
    }
    for(int i=0; i<k; i++)
    {
        scanf("%d", &recos[i]);
    }
    int from, to;
    for(int i=0; i<n-1; i++)
    {
        scanf("%d%d", &from, &to);
        addEdge(from, to);
    }

    memset(dp, -1, sizeof(dp));
    if(mark(1) > m)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", travel(1, m));
    }

    
    return 0;
}
