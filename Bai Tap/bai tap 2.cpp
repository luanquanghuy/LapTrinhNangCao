/*
1)  Nhap vao 1 mang cac xau ky tu la ten
2)  Ghi ra file voi moi ten tren 1 dong
3)  Doc moi ten va chuyen ky tu dau thanh in hoa
4)  Ghi cac ten sau chuyen cau 3 vao file xx2.txt   */
#include <stdio.h>
#include <ctype.h>


struct TEN{
    char ten[100];
};

// Ham de nhap ten vao mang a
void nhap_mang(TEN a[], int &n) {
    printf("Nhap number: ");
    scanf("%d", &n);
    while(getchar() != '\n');
    for(int i = 0; i < n; i++) {
        printf("Nhap ten thu %d: ", i + 1);
        gets(a[i].ten);
    }
}

// Ghi mang a ra file. Moi ten xuong 1 dong
void ghi_file(TEN a[], int n) {
    FILE *f;
    f = fopen("text.txt", "wt");
    for(int i = 0; i < n; i++) {
        fputs(a[i].ten, f);
        fprintf(f, "\n");
    }
    fclose(f);
}

// Doc ten tu file va chuyen ky tu dau thanh hoa, roi ghi vao file xx2.txt
void doc_file_ghi_file_moi(TEN a[]) {
    FILE *f_doc, *f_ghi;
    f_ghi = fopen("xx2.txt", "wt");
    char ch[100];
    printf("\n\nTen moi la:\n");
    if((f_doc = fopen("text.txt", "rt")) != NULL) {
        while(fgets(ch, 100, f_doc) != NULL) {
            ch[0] = toupper(ch[0]);
            printf("%s", ch);
            fputs(ch, f_ghi);
        }
        fclose(f_doc);
    }
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
