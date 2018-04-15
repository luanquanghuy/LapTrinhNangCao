#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    ifstream inf("Sample.dat");

    if (!inf)
    {
        cerr << "Sample.dat could not be opened for reading" << endl;
        exit(1);
    }

    while (inf)
    {
        string strInput;
        getline(inf, strInput);
        cout << strInput << endl;
    }
    cout << "Het!";
    inf.close();
}
