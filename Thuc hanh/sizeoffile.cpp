#include <stdio.h>

int main()
{
    int si = 0;
    FILE *f;
    f = fopen("sizefile1.txt", "r");
    while(fgetc(f) != EOF)
    {
    si++;
    }
    printf("%d", si);
}
