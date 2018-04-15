#include <stdio.h>

int main()
{
    float num;
    float a[100];
    int n = 0;
    FILE *f;
    f = fopen("numbers.txt", "r");
    while (!feof(f))
    {
        printf("%d\n", n);

        fscanf(f, "%f", &num);
        if ((num-int(num)) != 0)
        {
            a[n++] = num;
        }
    }
    for (int i=0; i<n; i++)
    {
        printf("%f\t", a[i]);
    }
    fclose(f);

}
