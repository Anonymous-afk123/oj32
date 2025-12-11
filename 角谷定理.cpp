#include <stdio.h>

int main() {
	int i;
	int count = 0;
	scanf("%d", &i);

	while (i > 1) {
		if (i % 2 == 0) {
			i = i / 2;
			count += 1;
		} else {
			i = 3 * i + 1;
			count += 1;
		}
	}

	printf("%d", count);
	return 0;
}