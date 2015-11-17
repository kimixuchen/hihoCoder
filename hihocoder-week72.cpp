/**
 * hihocoder-week72-Disk Storage
 * 2015-11-17 16:38:35
 * xuchen
**/
/**
**/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

const int N = 100005;
const int _MAX = 1e8+5;


int main()
{
	int n, m, h, r;
	int num=0, ans=0;
	int d[N];
	
	scanf("%d%d%d%d", &n, &m, &h, &r);
	for(int i=0; i<n; i++)
		scanf("%d", &d[i]);
	sort(d, d+n);

	int low, up;
	low = d[0];
	if(low>r)
	{
		printf("0\n");
		return 0;
	}
	num++;
	for(int i=1; i<n; i++)
	{
		if(d[i]>r+num || num>h)
		{
			break;
		}
		
		if(d[i]-low<=m)
		{
			num++;
			low = d[i];
		}
		else
		{
			if(d[i]>r)
			{
				break;	
			}
			else
			{
				ans+=num;
				low = d[i];
				num = 1;
			}
		}
	}
	ans += num;
	ans = min(ans, h);
	printf("%d\n", ans);
	return 0;
}
