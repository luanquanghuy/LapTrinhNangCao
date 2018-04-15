#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    ofstream outf;
    outf.open("Sample.dat", ios::out);

    if (!outf)
    {
        cout << "Khong co tep" << endl;
        cerr << "Khong the mo file Sample.dat de ghi" << endl;
        exit(1);
    }

    outf << "This is line 1" << endl;
    outf << "This is line 2" << endl;

    outf.close();

}
