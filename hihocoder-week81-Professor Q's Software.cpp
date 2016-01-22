/**
 * hihocoder-week81-Professor Q's Software
 * 22/01/16 10:12:31
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

const int N = 100005;
const int Modulo = 142857;
vector<int> module[N];
vector<int>_signalList[N];
vector<int> map[N];
int indegree[N];
int activeCount[N];

void init()
{
    for(int i=0; i<N; i++)
    {
        module[i].clear();
        _signalList[i].clear();
        map[i].clear();
    }
    memset(indegree, 0, sizeof(indegree));
    memset(activeCount, 0, sizeof(activeCount));
}

int main()
{
    int T;
    int n, m;
    scanf("%d", &T);
    while(T--)
    {
        init();
        scanf("%d%d", &n, &m);
        int _signal;
        for(int i=0; i<m; i++)
        {
            scanf("%d", &_signal);
            module[0].push_back(_signal);
        }
        
        int k;
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &_signal);
            _signalList[_signal].push_back(i);
            scanf("%d", &k);
            for(int j=0; j<k; j++)
            {
                scanf("%d", &_signal);
                module[i].push_back(_signal);
            }
        }
        
        for(int i=0; i<=n; i++)
        {
            for(vector<int>::iterator it = module[i].begin(); it!=module[i].end(); 
                    it++)
            {
                for(vector<int>::iterator sit = _signalList[*it].begin(); 
                        sit!=_signalList[*it].end(); sit++)
                {
                    map[i].push_back(*sit);
                    ++indegree[*sit];
                }
            }
        }
        
        activeCount[0] = 1;
        queue<int> sequence;
        for(int i=0; i<=n; i++)
        {
            if(indegree[i]==0)
                sequence.push(i);
        }
        while(!sequence.empty())
        {
            int curNode = sequence.front();
            sequence.pop();
            for(vector<int>::iterator it = map[curNode].begin(); 
                    it!=map[curNode].end(); it++)
            {
                activeCount[*it] += activeCount[curNode];
                --indegree[*it];
                if(indegree[*it] == 0)
                    sequence.push(*it);
            }
        }
        for(int i=1; i<=n; i++)
        {
            printf("%d ", activeCount[i] % Modulo);
        }
        printf("\n");
        
    }


    return 0;
}

