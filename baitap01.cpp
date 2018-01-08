#include <stdio.h>

void docFile(int &m, int &n) {
    FILE *f;
    f = fopen("file.txt", "rt");
    fscanf(f, "%d\t%d", &m, &n);
    fclose(f);
}

void nhapMaTran(int a[][100], int m, int n) {
    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) {
        printf("Nhap a[%d][%d]: ", i, j);
        scanf("%d", &a[i][j]);
    }
}

void inMaTran(int a[][100], int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) printf("%d\t", a[i][j]);
        printf("\n");
    }
}

void tinhMaTran(int a[][100], int b[][100], int m, int n)   {
    int c[100][100];

// Tong 2 ma tran
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            c[i][j] = a[i][j] + b[i][j];
    puts("Tong 2 ma tran la: ");
    inMaTran(c, m, n);

// Hieu 2 ma tran
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            c[i][j] = a[i][j] - b[i][j];
    puts("Hieu 2 ma tran la: ");
    inMaTran(c, m, n);

// Tich 2 ma tran
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++){
            c[i][j] = 0;
            for(int k = 0; k < n; k++) c[i][j] += a[i][k] * b[k][j];
        }
    puts("Tich 2 ma tran la: ");
    inMaTran(c, m, n);
}

int doiXung(int a[][100], int m, int n) {
    if(m != n) return -1;
    for(int i = 1; i < m; i++)
        for(int j = 0; j < i; j++)
            if(a[i][j] != a[j][i]) return 0;
    return 1;
}

void sapXep(int a[][100], int m, int n) {
    int tmp;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m - 1; j++)
            for(int k = j+1; k < m; k++)
                if(a[j][i] < a[k][i]) {
                    tmp = a[j][i];
                    a[j][i] = a[k][i];
                    a[k][i] = tmp;
                }
    puts("Ma tran sau khi sap xep la: ");
    inMaTran(a, m, n);
}

void tongBien(int a[][100], int m, int n) {
    int s = 0;

    for(int i = 0; i < m; i++) s += a[i][0];
    for(int i = 0; i < m; i++) s += a[i][n-1];
    for(int i = 0; i < n; i++) s += a[0][i];
    for(int i = 0; i < n; i++) s += a[m-1][i];
    s -= a[0][0] + a[0][n-1] + a[m-1][n-1] + a[m-1][0];

    printf("Tong cac phan tu tren bien la %d", s);
}

int main(){
    int a[100][100], b[100][100], m, n;
    docFile(m, n);
    printf("m = %d, n = %d\n", m, n);
    nhapMaTran(a, m, n);
    puts("Ma tran A: ");
    inMaTran(a, m, n);
    nhapMaTran(b, m, n);
    puts("Ma tran B: ");
    inMaTran(b, m, n);
    tinhMaTran(a, b, m, n);
    switch(doiXung(a, m, n)) {
        case -1:
            puts("Ma tran khong phai la ma tran vuong");
        case 1:
            puts("Ma tran doi xung");
        case 0:
            puts("Ma tran khong doi xung");
    }
    sapXep(a, m, n);
    tongBien(a, m, n);
}
