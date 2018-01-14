#include <stdio.h>

int main(int argc, char const *argv[]) {
  char chuoi[100];
  FILE *f;
  f = fopen("vanban.txt", "wt");
  for(int i = 0; i < 3; i++) {
    gets(chuoi);
    fputs(chuoi, f);
    fputs("\n", f);
    printf("%s\n", chuoi );
  }
  fclose(f);
  return 0;
}
