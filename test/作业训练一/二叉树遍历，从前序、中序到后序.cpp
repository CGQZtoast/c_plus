#include <iostream>
using namespace std;

void solve(string pre_str, string pose_str, int n)
{
    if(n == 0)
        return ;
    if(n == 1)
    {
        cout << pre_str;
        return ;
    }
        
    int pos = pose_str.find(pre_str[0]);
    solve(pre_str.substr(1, pos), pose_str.substr(0, pos), pos);
    solve(pre_str.substr(pos+1,pre_str.length()-pos-1),pose_str.substr(pos+1,pose_str.length()-pos-1), n - pos - 1);
    cout << pre_str[0];
}

int main()
{
    int n;
    string pre_str, pose_str;
    while(cin >> n && n != 0)
    {
        cin >> pre_str >> pose_str;
        solve(pre_str, pose_str, n);
        cout << endl;
    }
}