#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int N = 1010;
map<string, set<string>> ans;
bool cmp(string a, string b)
{
    return a.size() < b.size();
}
bool vjude(string a, string b)
{
    for (int i = 0; i < a.size(); i++)
        if (a[a.size() - i - 1] != b[b.size() - i - 1])
            return 0;
    return 1;
}
int main()
{
    int n;
    set<string> name;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        int t;
        cin >> a >> t;
        name.insert(a);
        for (int j = 0; j < t; j++)
        {
            cin >> b;
            ans[a].insert(b);
        }
    }
    map<string, set<string>>::iterator it_a;
    set<string>::iterator it_b;
    vector<string> V;
    set<string> S;
    for (auto it_a = ans.begin(); it_a != ans.end(); it_a++)
    {
        V.clear();
        S.clear();
        for (it_b = it_a->second.begin(); it_b != it_a->second.end(); it_b++)
            V.push_back(*it_b);
        sort(V.begin(), V.end(), cmp);
        for (int i = 0; i < V.size(); i++)
        {
            bool flag = 1;
            for (int j = i + 1; j < V.size(); j++)
                if (vjude(V[i], V[j]))
                    flag = 0;
            if (flag)
                S.insert(V[i]);
        }
        it_a->second = S;
    }
    cout << name.size() << endl;
    for (it_a = ans.begin(); it_a != ans.end(); it_a++)
    {
        cout << it_a->first << " " << it_a->second.size();
        for (it_b = it_a->second.begin(); it_b != it_a->second.end(); it_b++)
            cout << " " << *it_b;
        cout << endl;
    }
    return 0;
}
