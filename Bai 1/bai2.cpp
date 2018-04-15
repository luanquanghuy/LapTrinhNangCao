#include <iostream>

using namespace std;

int isPrime(int n)
{
    int so_uoc = 0;

    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            so_uoc++;

    return (so_uoc == 2);
}

int main()
{
    int n;

    cout << "Nhap vao so n: ";
    cin >> n;

    if (isPrime(n))
        cout << n << " la so nguyen to" << endl;
    else
        cout << n << " khong phai la so nguyen to" << endl;
}
