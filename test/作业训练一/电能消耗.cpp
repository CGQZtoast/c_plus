#include <iostream>
using namespace std;
int main()
{
    int n, P1, P2, P3, T1, T2;
    cin >> n >> P1 >> P2 >> P3 >> T1 >> T2;

    int time_[n][2];
    for(int i = 0; i < n; i++)
        cin >> time_[i][0] >> time_[i][1];

    int sum = 0;
    for(int i = 0; i < n - 1; i++)
    {
        sum += (time_[i][1] - time_[i][0]) * P1;

        if(time_[i + 1][0] - time_[i][1] < T1)
            sum += (time_[i + 1][0] - time_[i][1]) * P1;

        else if(time_[i + 1][0] - time_[i][1] >= T1 && time_[i + 1][0] - time_[i][1] < (T1 + T2))
        {
            sum += T1 * P1;
            sum += (time_[i + 1][0] - time_[i][1] - T1) * P2;
        }
        else
        {
            sum += T1 * P1;
            sum += T2 * P2;
            sum += (time_[i + 1][0] - time_[i][1] - T1 - T2) * P3;
        } 
    }
    sum += (time_[n - 1][1] - time_[n - 1][0]) * P1;
    cout << sum << endl;
}