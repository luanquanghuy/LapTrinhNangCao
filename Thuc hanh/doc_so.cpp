// bai 5
#include <stdio.h>

void doc_file()
{
    float a;
    int n=0, nguyen=0, thuc=0;
    FILE *f;
    char ch;
    int ok;
    f = fopen("numbers.txt", "r");
    while((ch = fgetc(f)) != EOF)
    {
        if (ch >= '0' && ch <= '9')
        {
            ok = 0;
            while((ch=fgetc(f))!=EOF)
            {
                if (ch == '.')
                {
                    thuc++;
                    ok = 1;
                }

                if (ch == ' ' || ch == '\n')
                {
                    if (ok == 0)
                        nguyen++;
                    break;
                }
            }
        }
    }
    fclose(f);
    printf("%d\t%d", nguyen, thuc);
}

int main()
{
    doc_file();
}
