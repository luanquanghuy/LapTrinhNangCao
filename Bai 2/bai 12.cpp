// bai 11
#include <stdio.h>
#include <stdlib.h>

int nhapMang(int *a, int n) {
	int hopLe = 0;
		for(int i=0; i<n; i++) {
			printf("nhap a[%d]: ", i);
			scanf("%d", a+i);
			if(*(a+i) < 0) hopLe = 1;
		}
		
		return hopLe;
}

void inMang(int *a, int n) {
	puts("");
	for(int i=0; i<n; i++) {
		printf("%d\t", *(a+i));
	}
}

int* xuLyHopLe(int *a, int n) {
	int *temp, index=0;
	temp = (int*) malloc(sizeof(int)*n);
	for(int i=0; i<n; i++) {
		if(*(a+i) < 0) *(temp + index++) = *(a+i);
	}
	for(int i=0; i<n; i++) {
		if(*(a+i) >= 0) *(temp + index++) = *(a+i);
	}
	free(a);
	return temp;
}

int* xuLyKhongHopLe(int *a, int &n) {
	int *temp, index = 0, added = 0;
	temp = (int*) malloc(sizeof(int)*(n+1));
	int max = *a, min = *a;
	for(int i=0; i<n; i++) {
		if(*(a+i) > max) max = *(a+i);
		if(*(a+i) < min) min = *(a+i);
	}
	int K = min - max;
	for(int i=0; i<n; i++) {
		*(temp + index++) = *(a + i);
		if(*(a+i) == min && !added) {
			*(temp + index++) = K;
			added = 1;
		}
	}
	free(a);
	n++;
	return temp;
}

int main() {
	int *a, n;
	printf("nhap n: ");
	scanf("%d", &n);
	a = (int*) malloc(sizeof(int)*n);
	if(nhapMang(a, n)) a = xuLyHopLe(a, n);
	else a = xuLyKhongHopLe(a, n);
	inMang(a, n);
	
	
}
