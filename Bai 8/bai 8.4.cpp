#include <stdio.h>
#include <stdlib.h>

struct Time{
    int hour, minute, second;
};

int main() {
    Time *t1, *t2;
    t1 = (Time*) malloc(sizeof(Time));
    t2 = (Time*) malloc(sizeof(Time));

    printf("Nhap t1: ");
    scanf("%d%d%d", &t1->hour, &t1->minute, &t1->second);
    printf("Nhap t2: ");
    scanf("%d%d%d", &t2->hour, &t2->minute, &t2->second);
    int t = abs((t2->hour - t1->hour) * 3600 + (t2->minute - t1->minute) * 60 + (t2->second - t1->second));
    printf("Khoang cach giua t1 va t2 la: %d gio %d phut %d giay", t/3600, (t % 3600) / 60, t % 60);
}
