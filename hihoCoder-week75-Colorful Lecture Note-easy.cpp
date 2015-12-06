/**
 * hihoCoder-week75-Colorful Lecture Note
 * 2015-12-06 19:23:27
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
const int RED = 1;
const int YELLOW = 2;
const int BLUE = 3;

stack<int> tags;
char s[N];
int nums[4];
int main()
{
    cin.getline(s, N);
    int len = strlen(s);
    int pos=0;
    while(pos<len)
    {
        if(s[pos]=='<')
        {
            pos++;
            switch(s[pos])
            {
                case 'y':
                    tags.push(YELLOW);
                    break;
                case 'b':
                    tags.push(BLUE);
                    break;
                case 'r':
                    tags.push(RED);
                    break;
                case '/':
                    tags.pop();
                    break;
            }
            while(s[pos] != '>') pos++;
        }
        else if(s[pos]>='a' && s[pos]<='z')
        {
            if(!tags.empty())
            {
                nums[tags.top()]++;
            }
        }
        pos++;
    }
    printf("%d %d %d", nums[RED], nums[YELLOW], nums[BLUE]);
    return 0;
}
