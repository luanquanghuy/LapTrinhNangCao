#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SinhVien {
    char masv[20];
    char ten[25];
    int ngay, thang, nam;
    double diemToan, diemLy, diemHoa, diemTB;
};

void nhapSV(SinhVien *sv, int n) {
    for(int i=0; i<n; i++){
        printf("\nnhap sinh vien %d:\n", i);
        while(getchar() != '\n');
        puts("nhap ma sinh vien: ");
        gets((sv+i)->masv);
        puts("nhap ten: ");
        gets((sv+i)->ten);
        puts("Nhap ngay, thang, nam sinh: ");
        scanf("%d%d%d", &(sv+i)->ngay, &(sv+i)->thang, &(sv+i)->nam);
        puts("Nhap diem toan, ly, hoa: ");
        scanf("%lf%lf%lf", &(sv+i)->diemToan, &(sv+i)->diemLy, &(sv+i)->diemHoa);
        (sv+i)->diemTB = ((sv+i)->diemToan + (sv+i)->diemLy + (sv+i)->diemHoa) / 3;
        printf("Diem TB: %lf", (sv+i)->diemTB);
    }
}

void xuatSV(SinhVien *sv, int n) {
    puts("Danh sach sinh vien: ");
    for(int i=0; i<n; i++) {
        printf("\n%d. %s", i, (sv+i)->ten);

    }
}

void maxTB(SinhVien *sv, int n) {
    char tempTen[25];
    double tempDiem=0;
    for(int i=0; i<n; i++) {
        if((sv+i)->diemTB > tempDiem) {
            tempDiem = (sv+i)->diemTB;
            strcpy(tempTen, (sv+i)->ten);
        }
    }
    printf("\nSinh vien co diem trung binh cao nhat: %s", tempTen);
}

int main() {
    SinhVien *sv;
    int n;
    printf("Nhap so sinh vien: ");
    scanf("%d", &n);
    sv = (SinhVien*) malloc(sizeof(SinhVien)*n);
    nhapSV(sv, n);
    xuatSV(sv, n);
    maxTB(sv, n);
}
