#include <stdio.h>

int main(int argc, char const *argv[]) {
  char chuoi[50];
  FILE *f;
  f = fopen("vanban.txt", "rt");

  // Đọc đến khi hết tệp thì dừng lại
  while (fgets(chuoi, 50, f) != NULL) {
    printf("%s", chuoi);
  }
  //
  fclose(f);
  return 0;
}
