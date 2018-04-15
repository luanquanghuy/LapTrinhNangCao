#include <iostream>

using namespace std;

int main()
{
    float n;

    cout << "Nhap n: ";
    cin >> n;

    cout.setf(ios::fixed);
    cout.precision(3);

    cout << "n=" << n;
}
