#include <stdio.h>

int main() {
	int n;
	int grp[100], evens[100], odds[100];
	int even_count = 0, odd_count = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		scanf("%d", &grp[i]);

		if (grp[i] % 2 == 0) {
			evens[even_count++] = grp[i];
		} else {
			odds[odd_count++] = grp[i];
		}
	}

	for (int i = 0; i < even_count - 1; i++) {

		for (int j = 0; j < even_count - i - 1; j++) {

			if (evens[j] < evens[j + 1]) {
				int temp = evens[j];
				evens[j] = evens[j + 1];
				evens[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < odd_count - 1; i++) {

		for (int j = 0; j < odd_count - i - 1; j++) {

			if (odds[j] < odds[j + 1]) {
				int temp = odds[j];
				odds[j] = odds[j + 1];
				odds[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < even_count; i++) {

		printf("%d\ ", evens[i]);
	}

	for (int i = 0; i < odd_count; i++) {

		printf("%d\ ", odds[i]);
	}

	return 0;
}