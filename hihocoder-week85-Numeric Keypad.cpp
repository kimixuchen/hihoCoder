/**
 * hihocoder-week85-Numeric Keypad
 * 25/02/16 15:11:25
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

const int N = 10;
const int NOTFOUND = -1;

int keysNexts[N][N] = 
{
    {0},
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
    {0, 2, 3, 5, 6, 8, 9, 9, 9, 9},
    {3, 6, 9, 9, 9, 9, 9, 9, 9, 9},
    {0, 4, 5, 6, 7, 8, 9, 9, 9, 9},
    {0, 5, 6, 8, 9, 9, 9, 9, 9, 9},
    {6, 9, 9, 9, 9, 9, 9, 9, 9, 9},
    {0, 7, 8, 9, 9, 9, 9, 9, 9, 9},
    {0, 8, 9, 9, 9, 9, 9, 9, 9, 9},
    {9, 9, 9, 9, 9, 9, 9, 9, 9, 9}
};

int getIndex(int pre, int now)
{
    int result = NOTFOUND;
    for(int i=0; i<N; i++)
    {
        if(keysNexts[pre][i] == now)
        {
            result = i;
            break;
        }
    }
    return result;
}

bool fitNext(int pre, int now)
{
    int index = getIndex(pre, now);
    if(index == NOTFOUND)
        return false;
    else
        return true;
}

void printNum(char* s, int len)
{
    int pos=0;
    while(s[pos]=='0')
        ++pos;
    while(pos < len)
    {
        printf("%c", s[pos]);
        pos++;   
    }
    printf("\n");
}

char findCloseNum(int pre, int now)
{
    for(int i=0; i<N; i++)
    {
        if(keysNexts[pre][i] >= now)
            return keysNexts[pre][i-1]+'0';
    }
    return keysNexts[pre][N-1]+'0';
}

int main()
{
    int t;
    char strNum[505];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", strNum);
        int len = strlen(strNum);
        int prePos = 0;
        int nowPos = 1;
        while(nowPos < len)
        {
            if(fitNext(strNum[prePos]-'0', strNum[nowPos]-'0'))
            {
                ++prePos;
                ++nowPos;
            }
            else
            {
                break;
            }
        }
        if(nowPos == len)
        {
            printNum(strNum, len);
            continue;
        }
        
        int keyPos = 0;
        if(keysNexts[strNum[prePos]-'0'][0] < strNum[nowPos]-'0')
        {
            keyPos = nowPos;
            strNum[keyPos] = findCloseNum(strNum[prePos]-'0', 
                    strNum[nowPos]-'0');
        }
        else
        {
            nowPos = prePos;
            prePos = nowPos-1;
            while(prePos >= 0)
            {
                if(keysNexts[strNum[prePos]-'0'][0] >= strNum[nowPos]-'0')
                {
                    --nowPos;
                    --prePos;
                }
                else
                {
                    keyPos = nowPos;
                    strNum[keyPos] = findCloseNum(strNum[prePos]-'0', 
                            strNum[nowPos]-'0');
                    break;
                }
            }
            if(prePos<0)
            {
                --strNum[0];
                keyPos = 0;
            }
        }
        for(int i=keyPos+1; i<len; i++)
        {
            strNum[i] = keysNexts[strNum[keyPos]-'0'][N-1]+'0';
        }
        printNum(strNum, len);
        
    }
    return 0;
}

