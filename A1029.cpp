#include<iostream>
using namespace std;
void maxmin_0(int a, int b, int c, int * max, int * min)
{
    *max = a > b? a: b;
    *max = *max > c? *max: c;
    *min = a < b? a: b;
    *min = *min < c? *min: c;
}
void maxmin_1(int a, int b, int c, int & max, int & min)
{
    max = a > b? a: b;
    max = max > c? max: c;
    min = a < b? a: b;
    min = min < c? min: c;
}
int main()
{
    int a, b, c, se, min, max;
    cin >> a >> b >> c >> se;
    if (se == 0)
        maxmin_0(a, b, c, &max, &min);
    else
        maxmin_1(a, b, c, max, min);
    cout << max << ' ' << min << endl;
}
