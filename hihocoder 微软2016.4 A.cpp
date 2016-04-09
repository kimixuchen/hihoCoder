/**
 *hihocoder Œ¢»Ì2016.4 A
 *09/04/16 10:12:20
 *xuchen
 * */
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1000005;
int a[N];

int n, w, h, p;
int t;

bool isOk(int s)
{
    if(s>w || s>h)
        return false;
    int lines = 0;
    int a1 = w/s;
    int b1 = h/s;
    int _max = p*b1;
    for(int i=0; i<n; ++i)
    {
        lines += a[i]/a1;
        if(a[i]%a1 != 0)
            ++lines;
    }
    if(lines > _max)
        return false;
    else
        return true;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d%d", &n, &p, &w, &h);
        for(int i=0; i<n; ++i)
        {
            scanf("%d", &a[i]);
        }
        int ans = 0;
        int left=0, right=1005;
        int mid;
        while(left <= right)
        {
            mid = (left+right)>>1;
            if(isOk(mid))
            {
                ans = mid;
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
