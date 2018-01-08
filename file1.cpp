#include <stdio.h>

void nhap(int a[], int &n) {
    printf("Nhap n: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void writeFile(int a[], int n) {
    FILE *f;
    f = fopen("file.txt", "wt");
    fprintf(f, "%d\n", n);
    for(int i = 0; i < n; i++) fprintf(f, "%d\t", a[i]);
    fclose(f);
}

void readFile(int a[], int &n)  {
    FILE *f;
    f = fopen("file.txt", "rt");
    fscanf(f, "%d\n",  &n);
    for(int i = 0; i < n; i++) {
        fscanf(f, "%d\t", &a[i]);
    }
}

void in(int a[], int n) {
    for(int i = 0; i < n; i++) printf("%d\t", a[i]);
}

int main() {
    int n, a[100];
    readFile(a, n);
    in(a, n);
}
