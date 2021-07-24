#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
    double x1, x2, x3, y1, y2, y3;
    double a, b, c;
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 && !(x1 == 0 && x2 == 0 && x3 == 0 && y1 == 0 && y2 == 0 &&y3 == 0 ))
    {
        a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
        c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));

        double P;
        P = (a + b + c) / 2;
        
        double S;
        S = sqrt(P * (P - a) * (P - b) * (P - c));
            cout << fixed << setprecision(6) << S << endl;
    }
}