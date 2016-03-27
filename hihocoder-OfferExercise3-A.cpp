/**
hihocoder-OfferExercise3-A
27/03/16 14:45:30
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

int main()
{
    int n;
    int pos=0;
    int a[N];
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for(int i=n-1; i>0; --i)
    {
        if(a[i] < a[i-1])
        {
            pos = i-1;
            break;
        }
    }
    for(int i=0; i<=pos; ++i)
    {
        printf("%d ", a[i]);
    }
    return 0;
}

