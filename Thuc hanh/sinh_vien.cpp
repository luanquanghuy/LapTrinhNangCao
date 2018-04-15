#include <stdio.h>

struct SinhVien
{
    char masv[20];
    char hoten[25];
    float mon1, mon2, mon3, tb;
};

void doc_file1(SinhVien sv[], int &n)
{
    FILE *f;
    f = fopen("SV.inp", "r");
    while (!feof(f))
    {
        fgets(sv[n].masv, 20, f);
        fgets(sv[n].hoten, 25, f);
        fscanf(f, "%f%f%f\n", &sv[n].mon1, &sv[n].mon2, &sv[n].mon3);
        sv[n].tb = (sv[n].mon1 + sv[n].mon2 + sv[n].mon3) / 3;
        n++;
    }
    fclose(f);
}

void doc_file2(SinhVien sv[], int &n)
{
    FILE *f;
    f = fopen("SV1.inp", "r");
    while (!feof(f))
    {
        fscanf(f, "%[^-]-%[^-]-%f%f%f", &sv[n].masv, &sv[n].hoten, &sv[n].mon1, &sv[n].mon2, &sv[n].mon3);
        sv[n].tb = (sv[n].mon1 + sv[n].mon2 + sv[n].mon3) / 3;
        n++;
    }
    n--;
    fclose(f);
}

void ghi_file1(SinhVien sv[], int n)
{
    FILE *f;
    f = fopen("SV.out", "w");
    for (int i=0; i<n; i++)
    {
        fprintf(f, "%s", sv[i].masv);
        fprintf(f, "%s", sv[i].hoten);
        fprintf(f, "%f\n", sv[i].tb);
    }
    fclose(f);
}

void ghi_file2(SinhVien sv[], int n)
{
    FILE *f;
    f = fopen("SV.out", "w");
    for (int i=0; i<n; i++)
    {
        fprintf(f, "%s-%s-%f", sv[i].masv,sv[i].hoten, sv[i].tb);
    }
    fclose(f);
}

int main()
{
    SinhVien a[100];
    int n = 0;
    //doc_file1(a, n);
   // ghi_file1(a, n);
    doc_file2(a, n);
    ghi_file2(a, n);
    printf("There are %d students", n);
}
