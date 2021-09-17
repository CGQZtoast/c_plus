#include <bits/stdc++.h>
using namespace std;
const int max_day = 101;
int arr[max_day];
int dp[max_day][3]; //用来记录休息的天数，0代表休息 ，2代表去健身房 ，1代表去参加互联网比赛
int main()
{
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		dp[i][0] = 2147483646;
		dp[i][1] = 2147483646;
		dp[i][2] = 2147483646;
	}
	if (arr[0] == 1)
		dp[0][1] = 0;
	if (arr[0] == 2)
		dp[0][2] = 0;
	if (arr[0] == 3)
	{
		dp[0][1] = 0;
		dp[0][2] = 0;
	}
	dp[0][0] = 1; //如果休息
	for (int i = 1; i < n; i++)
	{
		if (arr[i] == 1)
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
		else if (arr[i] == 2)
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
		else if (arr[i] == 3)
		{
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
		}

		dp[i][0] = min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]) + 1;
		//		cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<" ";
	}
	int result = min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
	cout << result << endl;
}
