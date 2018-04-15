#include <stdio.h>

int main() {
    int a[100], n = 0;
    FILE *f;
    f = fopen("mangso", "rt");

    while(!feof(f)) {
        fscanf(f, "%d", &a[n++]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}
