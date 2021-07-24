#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n][2];
    float j_sum = 0;
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0];
        sum += arr[i][0];
    }

    for (int i = 0; i < n; i++)
        cin >> arr[i][1];

    for (int i = 0; i < n; i++)
    {
        if (arr[i][1] >= 90 && arr[i][1] <= 100)
            j_sum += 4.0 * arr[i][0];
        else if (arr[i][1] >= 85 && arr[i][1] <= 89)
            j_sum += 3.7 * arr[i][0];
        else if (arr[i][1] >= 82 && arr[i][1] <= 84)
            j_sum += 3.3 * arr[i][0];
        else if (arr[i][1] >= 78 && arr[i][1] <= 81)
            j_sum += 3.0 * arr[i][0];
        else if (arr[i][1] >= 75 && arr[i][1] <= 77)
            j_sum += 2.7 * arr[i][0];
        else if (arr[i][1] >= 72 && arr[i][1] <= 74)
            j_sum += 2.3 * arr[i][0];
        else if (arr[i][1] >= 68 && arr[i][1] <= 71)
            j_sum += 2.0 * arr[i][0];
        else if (arr[i][1] >= 64 && arr[i][1] <= 67)
            j_sum += 1.5 * arr[i][0];
        else if (arr[i][1] >= 60 && arr[i][1] <= 63)
            j_sum += 1.0 * arr[i][0];
        else
            j_sum += 0 * arr[i][0];
    }
    cout << fixed << setprecision(2) << j_sum / sum << endl;
}