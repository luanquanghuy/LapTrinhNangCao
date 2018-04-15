#include <iostream>
#include <cstdlib>
#include <fstream>


using namespace std;

struct Date
{
    int ngay, thang, nam;
};

struct SinhVien
{
    string ten;
    int tuoi;
    Date ngaysinh;
    string noisinh;
    string quequan;
    string lop;
    int hocluc;
};

void nhap_mang(SinhVien a[], int &n)
{
    int tieptuc;

    n = 0;
    do
    {
        cout << "Nhap sinh vien thu " << n + 1 << endl;

        cout << "Nhap ho ten: ";                    getline(cin, a[n].ten);
        cout << "Nhap tuoi: ";                      cin >> a[n].tuoi;
        cout << "Nhap ngay, thang, nam sinh: ";     cin >> a[n].ngaysinh.ngay >> a[n].ngaysinh.thang >> a[n].ngaysinh.nam;
        cin.ignore(32767, '\n');
        cout << "Nhap noi sinh: ";                  getline(cin, a[n].noisinh);
        cout << "Nhap que quan: ";                  getline(cin, a[n].quequan);
        cout << "Nhap lop: ";                       getline(cin, a[n].lop);
        cout << "Nhap hoc luc: ";                   cin >> a[n].hocluc;

        cout << "Ban co muon nhap them sinh vien? (1.Co/0.Khong): ";
        cin >> tieptuc;
        cin.ignore(32767, '\n');
        system("clear");
        n++;
    } while (tieptuc);
}

void ghi_file(SinhVien a[], int n, char* filename)
{
    ofstream outf;
    // ghi them sinh vien vao cuoi file
    outf.open(filename, ios::app);

    for (int i = 0; i < n; i++)
    {
        outf << a[i].ten << endl;
        outf << a[i].tuoi << endl;
        outf << a[i].ngaysinh.ngay << " " << a[i].ngaysinh.thang << " " << a[i].ngaysinh.nam << endl;
        outf << a[i].noisinh << endl;
        outf << a[i].quequan << endl;
        outf << a[i].lop << endl;
        outf << a[i].hocluc <<endl;
    }
    outf.close();
}

int main()
{
    SinhVien sv[100];
    int n;
    nhap_mang(sv, n);
    ghi_file(sv, n, "student.txt");
}
