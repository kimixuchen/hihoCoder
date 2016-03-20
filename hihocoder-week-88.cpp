/**
 * hihocoder-week-88
 * 2016-03-20 18:27:05
**/
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include "stdio.h"
using namespace std;

const int N = 105;
const double ACCUR = 1e-6;

int d1[N], d2[N], d3[N], d4[N];

int main()
{
    int p, q;
    int pos1=0, pos2=0, pos3=0, pos4=0;

    scanf("%d%d", &p, &q);
    double sp = sqrt(1.0*p);
    double sq = sqrt(1.0*q);
    for(int i=1; i<=sp; ++i)
    {
        if(0 == p%i)
        {
            d1[pos1++] = i;
            d2[pos2++] = p/i;
        }
    }
    if(d1[pos1-1]*d1[pos1-1] == p)
    {
        --pos2;
    }
    for(int i=1; i<=pos2; ++i)
    {
        d1[pos1] = d2[pos2-i];
        ++pos1;
    }

    for(int i=1; i<=sq; ++i)
    {
        if(0 == q%i)
        {
            d3[pos3++] = i;
            d4[pos4++] = q/i;
        }
    }
    if(d3[pos3-1]*d3[pos3-1] == p)
    {
        --pos4;
    }
    for(int i=1; i<=pos4; ++i)
    {
        d3[pos3] = d4[pos4-i];
        ++pos3;
    }
    for(int i=0; i<pos1; ++i)
    {
        for(int j=0; j<pos3; ++j)
        {
            printf("%d %d\n", d1[i], d3[j]);
        }
    }
	return 0;
}
