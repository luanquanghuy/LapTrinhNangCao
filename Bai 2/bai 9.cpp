// bai 9
#include <stdio.h>
#include <string.h>

int main() {
	char s1[25], s2[25], s3[25];
	char *p1, *p2, *p3;
	
	puts("nhap chuoi 1:");
	gets(s1);
	puts("nhap chuoi 2:");
	gets(s2);
	p1 = s1;
	p2 = s2;
	p3 = s3;
	
	int n1 = strlen(p1);
	for(int i=0; i<=n1; i++) {
		*(p3+i) = *(p1+i);
	}
	int n2 = strlen(p2);
	for(int i=0; i<=n2; i++) {
		*(p3+n1+i) = *(p2+i);
	}
	puts(p3);
}
