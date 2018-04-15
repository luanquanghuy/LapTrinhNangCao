#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

struct Date
{
    int ngay, thang, nam;
};

struct SinhVien
{
    char ten[25];
    int tuoi;
    Date ngaysinh;
    char noisinh[20];
    char quequan[20];
    char lop[10];
    int hocluc;
};

void doc_file(SinhVien a[], int &n, char* filename)
{
    n = 0;

    ifstream inf(filename);

    while (inf)
    {
        inf.getline(a[n].ten, 25);
        inf >> a[n].tuoi;
        inf >> a[n].ngaysinh.ngay >> a[n].ngaysinh.thang >> a[n].ngaysinh.nam;
        inf.ignore(32767, '\n');
        inf.getline(a[n].noisinh, 20);
        inf.getline(a[n].quequan, 20);
        inf.getline(a[n].lop, 10);
        inf >> a[n].hocluc;
        inf.ignore(32767, '\n');

        n++;
    }

    inf.close();
    n--;
}

void in_thong_tin(SinhVien a[], int i, char* filename)
{
    ofstream f(filename, ios::app);

    f << a[i].ten << endl;
    f << a[i].tuoi << endl;
    f << a[i].ngaysinh.ngay << " " << a[i].ngaysinh.thang << " " << a[i].ngaysinh.nam << endl;
    f << a[i].noisinh << endl;
    f << a[i].quequan << endl;
    f << a[i].lop << endl;
    f << a[i].hocluc << endl;

    f.close();
}

void ghi_file_moi(SinhVien a[], int n)
{
    int kem = 0, tbinh = 0, gioi = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < strlen(a[i].ten); j++)
            if (toupper(a[i].ten[j]) == 'V' && toupper(a[i].ten[j+1]) == 'I' && toupper(a[i].ten[j+2]) == 'N' && toupper(a[i].ten[j+3]) == 'H')
                in_thong_tin(a, i, "vinh.txt");

        if (strcmp(a[i].quequan, "Ha Noi") == 0)
            in_thong_tin(a, i, "hanoi.txt");

        if (a[i].hocluc < 4)
            kem++;
        else if (a[i].hocluc >= 8)
            gioi++;
        else
            tbinh++;
    }

    ofstream f("hocluc.txt");
    f << "Tong so hoc luc kem: " << kem << endl;
    f << "Tong so hoc luc trung binh: " << tbinh << endl;
    f << "Tong so hoc luc gioi: " << gioi << endl;
    f.close();
}

int main()
{
    SinhVien sv[100];
    int n;
    doc_file(sv, n, "student.txt");
    ghi_file_moi(sv, n);
}
