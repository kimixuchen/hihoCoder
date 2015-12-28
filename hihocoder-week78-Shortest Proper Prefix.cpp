/**
 * hihocoder-week78-Shortest Proper Prefix
 * 28/12/15 12:25:43
 * xuchen
**/
/**
 * paay attention: 
 * If sets N too large, it may be TLE
 * */
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

const int INF = 0x3f3f3f3f;
const int N = 1000008;

struct TrieNode{
    int count;
    vector<TrieNode*> child;
    TrieNode() :count(0), child(26,NULL){};
    TrieNode(int x) :count(x), child(26,NULL){};
};

void insertTrieTree(TrieNode* root, char* s, int pos)
{
    if(s[pos]==0)
    {
        return;
    }
    int k = s[pos]-'a';
    if(root->child[k]==NULL)
    {
        root->child[k] = new TrieNode();
    }
    root->child[k]->count++;
    insertTrieTree(root->child[k], s, pos+1);
}

int dfs(TrieNode* root)
{
    if(root->count<=5)
    {
        return 1;
    }
    int ans=0;
    for(int i=0; i<26; i++)
    {
        if(root->child[i] != NULL)
            ans+=dfs(root->child[i]);
    }
    return ans;
}
int main()
{
    int n;
    char *queryStr = new char[N];
    TrieNode* root = new TrieNode();
    root->count = INF;
    memset(queryStr, 0, N);
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        memset(queryStr, 0, N);
        scanf("%s", queryStr);
        insertTrieTree(root, queryStr, 0);
    }
    int ans;
    ans = dfs(root);
    printf("%d\n", ans);
    return 0;
}

