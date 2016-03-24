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

struct Candy{
    double price;
    int want;
};

const int N = 55;
Candy candys[N];

bool isOk(double price)
{
    double a = price/5;
    if(abs(int(a)-a) < 0.00001)
        return true;
    return false;
}

int main()
{
    int q, n;
    int sumWant, ans;
    double sumPrice;
    scanf("%d", &q);
    for(int i=0; i<q; ++i)
    {
        ans = 0;
        scanf("%d", &n);
        for(int j=0; j<n; ++j)
        {
            scanf("%lf %d", &candys[j].price, &candys[j].want);
        }
        candys[n].price = 0;
        candys[n].want = 0;
        candys[n+1].price = 0;
        candys[n+1].want = 0;
        for(int j=0; j<n+2; ++j)
        {
            for(int k=j+1; k<n+2; ++k)
            {
                for(int l=k+1; l<n+2; ++l)
                {
                    sumWant = candys[j].want + candys[k].want + candys[l].want;
                    sumPrice = candys[j].price + candys[k].price + candys[l].price;
                    if(isOk(sumPrice) && ans < sumWant)
                    {
                        ans = sumWant;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

