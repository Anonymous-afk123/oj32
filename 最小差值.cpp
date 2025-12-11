#include <stdio.h>
#include <stdlib.h>

int main() {
	int number;
	scanf("%d", &number);

	int group[number]; // C99变长数组

	for (int i = 0; i < number; i++) {

		scanf("%d", &group[i]);
	}

	int min_diff = 1000000;

	for (int i = 0; i < number; i++) {

		for (int j = i + 1; j < number; j++) {

			int diff = abs(group[i] - group[j]);

			if (diff < min_diff) {
				min_diff = diff;
			}
		}
	}

	printf("%d", min_diff);
	return 0;
}