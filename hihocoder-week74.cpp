/**
 * hihocoder-week74
 * 2015-11-29 21:05:43
 * xuchen
**/
/**
**/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
using namespace std;

const int N = 8;
const int INF = 0x3f3f3f3f;
int main()
{
    int tax,salary, remained;
    double tmp=0;
    double rates[N] = {0.03, 0.1, 0.2, 0.25, 0.3, 0.35, 0.45};
    int grades[N] = {0, 45, 345, 1245, 7745, 13745, 22495};
    int salarys[N] = {3500, 5000, 8000, 12500, 38500, 58500, 83500};
    scanf("%d", &tax);
    int step = 6;
    int part;
    while(step>=0)
    {
        if(tax>grades[step])
        {
            tmp = (tax-grades[step])/(rates[step]) + salarys[step];
            break;
        }
        step--;
    }
    salary = tmp;
    printf("%d\n", salary);

}
