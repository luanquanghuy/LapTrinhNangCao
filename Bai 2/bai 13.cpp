#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void nhapMang(int *a, int n) {
    for(int i = 0; i < n; i++) {
        printf("nhap a[%d]: ", i);
        scanf("%d", a+i);
    }
}

void inMang(int *a, int n) {
    puts("");
    for(int i = 0; i < n; i++) {
        printf("%d\t", *(a+i));
    }
}

void sortArray(int *a, int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(a[i] < a[j]) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void xuLy(int *a, int n) {
    int min = a[n-1];
    int k = 0;
    while(a[n-1-k] == min) k++;
    for(int i = 1; i < n; i++) {
        if(a[i] != a[0]) {
            for(int j = n-1-k; j >= i; j--) {
                a[j+k] = a[j];
            }
            while(k-- > 0) {
                a[i+k] = min;
            }
            break;
        }
    }

}

int hopLe(int *a, int n) {
    int tongAm = 0, tongDuong = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > 0) tongDuong += a[i];
        else tongAm += a[i];
    }
    if(abs(tongAm) == tongDuong) return 1;
    else return 0;
}

int* xoaSo(int *a, int &n) {
    int *temp, index = 0, nXoa = 0;
    temp = (int*) malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) {
        if(a[i] > 0 && a[i] % 2 != 0) {
            temp[index++] = a[i];
        } else nXoa++;
    }
    n -= nXoa;
    free(a);
    return temp;
}

int main() {
    int *a, n;
    printf("nhap n: ");
    scanf("%d", &n);
    a = (int*) malloc(n * sizeof(int));
    nhapMang(a, n);
    inMang(a, n);
    sortArray(a, n);
    xuLy(a, n);
    inMang(a, n);
    if(hopLe) printf("\na hop le.");
    else printf("\na khong hop le.");
    a = xoaSo(a, n);
    inMang(a, n);
}
