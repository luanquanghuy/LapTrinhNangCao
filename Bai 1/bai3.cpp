#include <iostream>
#include <iomanip>

using namespace std;

void nhap_mang(float a[], float b[], int &n)
{
    cout << "Nhap n: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap a[" << i << "]: ";
        cin >> a[i];
        b[i] = a[i];
    }
}

void sap_xep(float a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
            {
                float temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

void in_mang(float a[], float b[], int n)
{
    cout.fill('-');
    cout.precision(3);
    cout << setw(5) << "TT";
    cout << setw(20) << "Mang chua sap xep";
    cout << setw(20) << "Mang da sap xep" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << setw(5) << i;
        cout << setw(20) << a[i];
        cout <<setw(20) << b[i] << endl;
    }
}

int main()
{
    float a[100], b[100];
    int n;

    nhap_mang(a, b, n);
    sap_xep(b, n);
    in_mang(a, b, n);
}
