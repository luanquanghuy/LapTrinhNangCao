#include <iostream>
//#include <ios>
#include <limits>

using namespace std;

int main()
{
    int a;
    char s[100];

    cin >> a;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(s, 100);

    cout << numeric_limits<streamsize>::max() << endl;

}
