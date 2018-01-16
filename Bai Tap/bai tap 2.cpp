/*
1)  Nhap vao 1 mang cac xau ky tu la ten
2)  Ghi ra file voi moi ten tren 1 dong
3)  Doc moi ten va chuyen ky tu dau thanh in hoa
4)  Ghi cac ten sau chuyen cau 3 vao file xx2.txt   */
#include <stdio.h>
#include <ctype.h>

// Tao kieu cau truc TEN co thuoc tinh ten kieu du lieu char gom 100 phan tu
struct TEN{
    char ten[100];
};

// Ham de nhap ten vao mang a
void nhap_mang(TEN a[], int &n) {
    // Nhap tong so ten can nhap vao.
    printf("Nhap number: ");
    scanf("%d", &n);

    // Xoa ky tu xuong dong khi nhap n
    while(getchar() != '\n');

    // Nhap n so ten vao mang a
    for(int i = 0; i < n; i++) {
        printf("Nhap ten thu %d: ", i + 1);
        gets(a[i].ten);
    }
}

// Ghi mang a ra file. Moi ten xuong 1 dong
void ghi_file(TEN a[], int n) {
    FILE *f;
    f = fopen("text.txt", "wt");

    // Ghi moi ten trong mang a vao file text.txt
    for(int i = 0; i < n; i++) {
        fputs(a[i].ten, f);
        fprintf(f, "\n");
    }
    //

    fclose(f);
}

// Doc ten tu file va chuyen ky tu dau thanh hoa, roi ghi vao file xx2.txt
void doc_file_ghi_file_moi(TEN a[]) {
    // bien ch de luu gia tri moi ten doc tu file
    char ch[100];
    // f_doc la con tro de doc file, f_ghi la con tro de ghi file
    FILE *f_doc, *f_ghi;
    f_ghi = fopen("xx2.txt", "wt");
    //

    printf("\n\nTen moi la:\n");
    // Neu mo file text.txt thanh cong thi bat dau doc, ghi du lieu
    if((f_doc = fopen("text.txt", "rt")) != NULL) {
        //doc ten cua tung dong trong file ghi vao bien ch, den khi nao het file
        while(fgets(ch, 100, f_doc) != NULL) {
            // chuyen ky tu dau thanh chu Hoa
            ch[0] = toupper(ch[0]);
            // ghi moi ten doc dc tu file text.txt ghi lan luot vao file xx2.txt
            fputs(ch, f_ghi);
            /*In ra man hinh cac ten duoc doc tu file text.txt*/
            printf("%s", ch);
        }
        //
        fclose(f_doc);
    }
    //
    fclose(f_ghi);
}


int main() {
    TEN a[100];
    int n;
    nhap_mang(a, n);
    ghi_file(a, n);
    doc_file_ghi_file_moi(a);
    return 0;
}
