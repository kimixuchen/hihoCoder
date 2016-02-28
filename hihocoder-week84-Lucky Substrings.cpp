/**
 * hihocoder-week84-Lucky Substrings
 * 28/02/16 16:23:22
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
bool fibonacci[25];

void init()
{
    memset(fibonacci, 0, sizeof(fibonacci));
    fibonacci[1] = true;
    fibonacci[2] = true;
    fibonacci[3] = true;
    fibonacci[5] = true;
    fibonacci[8] = true;
    fibonacci[13] = true;
    fibonacci[21] = true;
}

int main()
{
    init();
    char s[N];
    vector<string> ans;
    scanf("%s", s);
    int len = strlen(s);

    for(int i=0; i<len; i++)
    {
        bool alphabet[27];
        memset(alphabet, 0, sizeof(alphabet));
        int c = 0;
        for(int j=i; j<len; j++)
        {
            if(!alphabet[s[j]-'a'])
            {
                alphabet[s[j]-'a'] = true;
                ++c;
            }
            if(fibonacci[c])
                ans.push_back(string(s+i, s+j+1));
        }
    }
    sort(ans.begin(), ans.end());
    printf("%s\n", ans[0].c_str());
    for(int i=1; i<ans.size(); ++i)
    {
        if(ans[i] != ans[i-1])
            printf("%s\n", ans[i].c_str());
    }

    return 0;
}

