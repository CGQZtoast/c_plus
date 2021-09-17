#include <iostream>
#include <vector>
using namespace std;

int main() {  //: T5-2
    int n; cin >> n;
    vector<int> sum(n+1);  // 前缀和数组
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] += sum[i-1];
    }

    int max_z = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            /**
             * 「翻转」选定区间后 1 的总数
             * = 原来 1 的总数 + 翻转区间中 0 的数量 - 翻转区间中 1 的数量
             * = 总和 + (区间长 - 区间求和) - 区间求和
             */
             max_z = max(max_z, sum[n] + (j-i+1) - 2*(sum[j]-sum[i-1]));
        }
    }

    cout << max_z << endl;
    return 0;
}