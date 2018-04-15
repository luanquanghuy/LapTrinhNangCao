// bai 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *s;
	s = (char*) malloc(sizeof(char) * 100);
	
	puts("Nhap chuoi: ");
	gets(s);
	int n = strlen(s);
	for(int i=0; i<n/2; i++) {
		char temp;
		*(s+i) = *(s+n-1-i);
	}
	
	puts(s);
}
