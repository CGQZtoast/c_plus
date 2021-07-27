#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	float Q; // 最大报销额
	int N; // 发票张数
	while (cin >> Q >> N && N != 0)
	{
		int n; // 每张发票物品件数
		vector<float> price; // 用于储存可以报销的发票的报销额
		while (N--) // 每张发票
		{
			cin >> n; 
			float sum = 0, temp; // 每张发票报销总额，单件物品价值
			bool flag = true; // 用于判断是否可以报销
			while (n--)
			{ 
				getchar();
				string str;
				getline(cin, str, ':');
				if (str != "A" && str != "B" && str != "C")
					flag = false;
				cin >> temp;
				if (temp > 600) // 判断单件物品价值是否超过600元
					flag = false;
				sum += temp;
			}
			if (sum <= 1000 && sum <= Q && flag == true)
				price.push_back(sum);
		}
		sort(price.begin(), price.end(), cmp); // 将满足条件的发票由大到小排序
		float ans = 0; // 可以报销的最大数额
		for (unsigned int i = 0; i < price.size(); i++)
		{
			if (ans + price[i] <= Q)
				ans += price[i];
		}
		printf("%.2f\n", ans);
	}
}
