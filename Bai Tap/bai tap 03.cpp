#include <stdio.h>
#include <string.h>
#include <ctype.h>

void ghi_file() {
    char ten[100];
    FILE *f;
    f = fopen("SV.txt", "wt");
    puts("Ban hay nhap ten (muon ket thuc hay nhap chuoi rong):");
    do {
        gets(ten);
        fprintf(f, "%s\n", ten);
    } while (strlen(ten));
    fclose(f);

}

char* in_hoa(char *ten) {
    int n = strlen(ten);
    for (int i = 0; i < n; i++) {
        if (i == 0 || ten[i-1] == ' ')
            ten[i] = toupper(ten[i]);
    }
    return ten;
}

void ghi_ten_hoa() {
    char ten[100];
    FILE *fi, *fo;
    fo = fopen("TenHoa.txt", "wt");
    if (fi = fopen("SV.txt", "rt")) {
        while (fgets(ten, 100, fi)) {
            fputs(in_hoa(ten), fo);
        }
        fclose(fi);
    }
    fclose(fo);
}

int main(){
    ghi_file();
    ghi_ten_hoa();
    rename("SV.txt", "SV_thg.txt");
}
