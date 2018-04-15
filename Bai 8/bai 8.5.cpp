#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Date {
    int day, month, year;
};

int main() {
    Date *d1, *d2;
    d1 = (Date*) malloc(sizeof(Date));
    d2 = (Date*) malloc(sizeof(Date));

    printf("Nhap ngay thu 1: ");
    scanf("%d%d%d", &d1->day, &d1->month, &d1->year);
    printf("Nhap ngay thu 2: ");
    scanf("%d%d%d", &d2->day, &d2->month, &d2->year);

    int t1, t2;
    t1 = 365*d1->year + d1->year/4 - d1->year/100 + d1->year/400 + d1->day + (153*d1->month + 8)/5;
    t2 = 365*d2->year + d2->year/4 - d2->year/100 + d2->year/400 + d2->day + (153*d2->month + 8)/5;

    printf("Khoang cach giua 2 moc thoi gian la: %d ngay", abs(t1 - t2));
}
