#include <iostream>
#include<algorithm>
using namespace std;
const int maxn = 1000 * 30 * 100;
int max_value;
int dp[maxn];
int capacity;
int val[maxn];

int main()
{
	double v;
	int n;
	while (cin>>v>>n && n)
	{
		capacity = 0;
		max_value = (int)(v * 100);
		for (int i = 1;i <= n;i++)
		{
			int num;
			char type;
			double va = 0, vb = 0, vc = 0;
			scanf("%d", &num);
			bool flag = true;
			while (num--)
			{
				scanf(" %c:%lf", &type, &v);
				if (type == 'A') va += v; 
				else if (type == 'B') vb += v; 
				else if (type == 'C') vc += v; 
				else flag = false; 
			}
			if (flag && va <= 600 && vb <= 600 && vc <= 600 && va + vb + vc <= 1000)
			{
				val[++capacity] = (int)((va + vb + vc) * 100);
			}
		}
		for (int i = 0; i < maxn; i++)
            dp[i] = 0;
		for (int i = 1;i <= capacity;i++)
		{
			for (int j = max_value;j >= val[i];j--)
			{
				dp[j] = max(dp[j], dp[j - val[i]] + val[i]);
			}

		}
		printf("%.2lf\n", (dp[max_value]) / 100.0);
	}
}
