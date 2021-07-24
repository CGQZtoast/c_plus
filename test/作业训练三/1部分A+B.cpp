#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    string A, B;
    char a, b;
    cin >> A >> a >> B >> b;

    int count1 = 0, count2 = 0;  
    int n1 = A.length(), n2 = B.length();
    int pa, pb;
    for (int i = 0; i < n1; i++)
        if (A[i] == a)
            count1++;
    for (int i = 0; i < n2; i++)
        if (B[i] == b)
            count2++;
    pa = (pow(10, count1) - 1) * (a - '0') / 9;
    pb = (pow(10, count2) - 1) * (b - '0') / 9;

    cout << pa + pb << endl;
    }