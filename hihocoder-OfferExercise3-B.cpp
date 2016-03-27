/**
hihocoder-OfferExercise3-B
27/03/16 14:52:14
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
#include <map>
using namespace std;

const int N = 1000005;

map<long long, bool> t;

int gcd(int a, int b)
{
    if(a < b)
    {
        int tmp = a;
        a = b;
        b = a;
    }
    int r;
    while(b > 0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    long long n, m;
    int a, b, k;
    scanf("%lld %lld", &n, &m);
    a = 0; b = 0; k = 0;
    int mn = (int)sqrt(n);
    int mm = (int)sqrt(m);
    for(int i=1; i<=mn; ++i)
    {
        if(n%i == 0)
        {
            t[i] = true;
            t[n/i] = true;
            a += 2;
        }
    }
    if(abs(n-mn*mn) < 0.00001)
        --a;

    for(int i=1; i<=mm; ++i)
    {
        if(m%i == 0)
        {
            if(t[i])
                ++k;
            if(t[m/i])
                ++k;
            b += 2;
        }
    }
    if(abs(m-mm*mm) < 0.00001)
    {
        --b;
        if(t[m/mm])
        {
            --k;
        }
    }

    int g = gcd(a, k);
    while(g > 1)
    {
        a/=g;
        k/=g;
        g = gcd(a, k);
    }
    g = gcd(b, k);
    while(g > 1)
    {
        b/=g;
        k/=g;
        g = gcd(b, k);
    }

    printf("%lld %d\n", (long long)a*b, k);

    return 0;
}

