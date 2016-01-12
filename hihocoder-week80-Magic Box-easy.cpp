/**
 * hihocoder-week80-Magic Box
 * 12/01/16 15:28:57
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

const int N = 20005;
const int R = 0;
const int Y = 1;
const int B = 2;

int nums[3];
int x, y, z;
char sequence[N];

bool isOk(int a, int b, int c, int x, int y, int z)
{
    int a1 = abs(a-b);
    int a2 = abs(b-c);
    int a3 = abs(a-c);
    if(a1==x && a2==y && a3==z || a1==x && a2==z && a3==y)
        return true;
    if(a1==y && a2==x && a3==z || a1==y && a2==z && a3==x)
        return true;
    if(a1==z && a2==x && a3==y || a1==z && a2==y && a3==x)
        return true;
    return false;
}
int main()
{
    scanf("%d %d %d", &x, &y, &z);
    scanf("%s", sequence);
    int pos=0;
    int length = strlen(sequence);
    int maxNum = 0;
    int sum=0;
    while(pos<length)
    {
        if(sequence[pos]=='R')
        {
            nums[R]+=1;
        }
        else if(sequence[pos]=='Y')
        {
            nums[Y]+=1;
        }
        else if(sequence[pos]=='B')
        {
            nums[B]+=1;
        }
        sum+=1;
        maxNum = max(maxNum, sum);
        if(isOk(nums[R], nums[B], nums[Y], x, y, z))
        {
            sum=0;
            memset(nums, 0, sizeof(nums));
        }
        pos+=1;
    }
    printf("%d\n", maxNum);


    return 0;
}

