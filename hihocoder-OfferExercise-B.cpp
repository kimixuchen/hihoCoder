/**
hihocoder-OfferExercise-A
24/03/16 14:12:29
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
using namespace std;

const int N = 1005;

struct Post{
    int x1, y1, x2, y2;
    bool flags[4];
    void read()
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    }
    void init()
    {
        memset(flags, 0, sizeof(flags));
    }
    void cornerCover(Post *s)
    {
        flags[0] |= (x1>s->x1 && x1<s->x2) && (y1>s->y1 && y1<s->y2);
        flags[1] |= (x1>s->x1 && x1<s->x2) && (y2>s->y1 && y2<s->y2);
        flags[2] |= (x2>s->x1 && x2<s->x2) && (y1>s->y1 && y1<s->y2);
        flags[3] |= (x2>s->x1 && x2<s->x2) && (y2>s->y1 && y2<s->y2);
    }
    bool isSee()
    {
        return !(flags[0] && flags[1] && flags[2] && flags[3]);
    }
};

Post posts[N];
vector<int> hurt[N];
bool visit[N];
int dp[N];
int ans;
int id;

void dfs(int x)
{
    visit[x] = true;
    if(dp[x] > 0)
        return;

    int m=1;
    for(int i=0; i<hurt[x].size(); ++i)
    {
        if(!visit[(hurt[x])[i]])
        {
            dfs((hurt[x])[i]);
            m += dp[(hurt[x])[i]];
        }
    }
    dp[x] = m;
}

bool cover(int i, int j)
{
    if(posts[i].x1 >= posts[j].x2 || posts[i].x2 <= posts[j].x1 ||
            posts[i].y1 >= posts[j].y2 || posts[i].y2 <= posts[j].y1)
        return false;
    return true;
}
int main()
{
    int w, h, n;

    scanf("%d%d%d", &w, &h, &n);
    for(int i=0; i<n; ++i)
    {
        posts[i].read();
        posts[i].init();
    }
    for(int i=0; i<n; ++i)
    {
        for(int j=i+1; j<n; ++j)
        {
            if(cover(i, j))
            {
                hurt[i].push_back(j);
                posts[i].cornerCover(&posts[j]);
            }
        }
    }
    for(int i=0; i<n; ++i)
    {
        if(posts[i].isSee())
        {
            memset(visit, 0, sizeof(visit));
            memset(dp, 0, sizeof(dp));
            dfs(i);
            if(dp[i] > ans)
            {
                ans = dp[i];
                id = i+1;
            }
        }
    }
    printf("%d %d\n", ans, id);
    return 0;
}

