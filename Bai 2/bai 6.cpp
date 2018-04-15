#include <stdio.h>
#include <stdlib.h>

void nhapMang(int *a, int &n) {
	for(int i=0; i<n; i++) {
		printf("nhap a[%d]: ", i);
		scanf("%d", a + i);
	}
}

void inMang(int *a, int n) {
	puts("");
	for(int i=0; i<n; i++) {
		printf("%d\t", *(a+i));
	}
}

int solution(int *a, int n) {
	for(int i=1; i<n; i++){
		if(*(a+i) % *a == 0) return *(a+i);
	}
	return -1;
}

int main() {
	int *pa = NULL;
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	pa = (int*) malloc(sizeof(int)*n);
	nhapMang(pa, n);
	inMang(pa, n);
	printf("\nKet qua: %d", solution(pa, n));
}
