#include <iostream>

using namespace std;

int isLeapYear(int y)
{
    return (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
}

int main()
{
    int n;

    cout << "Nhap vao nam: ";
    cin >> n;

    if (isLeapYear(n))
        cout << n << " la nam nhuan" << endl;
    else
        cout << n << " khong phai nam nhuan" << endl;
}
