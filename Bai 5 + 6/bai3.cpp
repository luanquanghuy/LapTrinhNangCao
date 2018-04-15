#include <iostream>
#include <fstream>

using namespace std;

int filesize(char* filename)
{
    ifstream f(filename, ios::ate);
    int res =  f.tellg();
    f.close();
    return res;
}

int main()
{
    ofstream f("all.txt");
    f << "Kich thuoc file student.txt la: " << filesize("student.txt") << " bytes." << endl;
    f << "Kich thuoc file vinh.txt la: " << filesize("vinh.txt") << " bytes." << endl;
    f << "Kich thuoc file hanoi.txt la: " << filesize("hanoi.txt") << " bytes." << endl;
    f << "Kich thuoc file hocluc.txt la: " << filesize("hocluc.txt") << " bytes." << endl;
    f.close();
}
