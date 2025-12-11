#include <stdio.h>

int main() {
	float s, c;
	int t;
	scanf("%f %d", &s, &t);

	if (s <= 3) {
		c = 10;
	} else if (s <= 10) {
		c = 2 * (s - 3) + 10;
	} else {
		c = 3 * (s - 10) + 24;
	}

	c = c + (t / 5) * 2;
	printf("%.0f", c);
	return 0;
}