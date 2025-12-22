#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int sum(int n);
void swap(int *a, int *b) ;
void sort_numbers(int num[], int n);

int main(void) {
	int n;
	scanf("%d", &n);

	int num[n];

	for (int i = 0; i < n; i++) {

		scanf("%d", &num[i]);
	}

	sort_numbers(num, n);

	for (int i = 0; i < n; i++) {

		printf("%d %d\n", num[i], sum(num[i]));
	}

	return 0;
}

int sum(int n) {
	int sum = 0;

	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}

	return sum;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort_numbers(int num[], int n) {
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n - i - 1; j++) {

			int s1 = sum(num[j]);
			int s2 = sum(num[j + 1]);

			if (s1	< s2 || (s1 == s2 && num[j] > num[j + 1])) {
				swap(&num[j], &num[j + 1]);
			}
		}
	}
}