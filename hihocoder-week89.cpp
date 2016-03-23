/**
 * hihocoder-week89
 * 23/03/16 10:01:39
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

const long long N = 1e16;

int prime[13] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
long long n;
long long ans;
int pNum;
int maxpNum;

void DFS(int prime, long long currentNum, int lastPrimeNum);

int main()
{
    scanf("%lld", &n);
    ans = 1;
    pNum = 1;
    maxpNum = 1;
    DFS(0, 1, 100);
    printf("%lld\n", ans); 

    return 0;
}

void DFS(int primePos, long long currentNum, int lastPrimeNum)
{
    if(currentNum > n || primePos >= 13)
    {
        return;
    }
    int i=0;
    for( ; i<lastPrimeNum; ++i)
    {
        currentNum *= prime[primePos];
        if(currentNum > n)
        {
            break;
        }
        pNum *= (i+2);
        if(pNum > maxpNum || (pNum==maxpNum && ans>currentNum))
        {
            maxpNum = pNum;
            ans = currentNum;
        }
        DFS(primePos+1, currentNum, i+1);
        pNum /= (i+2);
    }
}
