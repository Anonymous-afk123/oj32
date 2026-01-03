#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int year;
	int month;
	int day;
	int size;
} File;

int compare(const void *a, const void *b) {
	File *f1 = (File *)a;
	File *f2 = (File *)b;

	if (f1->year != f2->year) {
		return f2->year - f1->year;
	}

	if (f1->month != f2->month) {
		return f2->month - f1->month;
	}

	if (f1->day != f2->day) {
		return f2->day - f1->day;
	}

	return f2->size - f1->size;
}


int main() {

	int n;

	if (scanf("%d", &n) != 1)
		return 0;

	File file[n];

	for (int i = 0; i < n; i++) {

		scanf("%d/%d/%d %d", &file[i].year, &file[i].month, &file[i].day, &file[i].size);
	}

	qsort(file, n, sizeof(File), compare);


	for (int i = 0; i < n; i++) {

		printf("%d/%d/%d %d\n", file[i].year, file[i].month, file[i].day, file[i].size);
	}

	return 0;
}