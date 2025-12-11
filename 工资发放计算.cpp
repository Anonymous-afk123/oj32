#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		char name[10];
		float basic, floating, expense;

		scanf("%s %f %f %f", name, &basic, &floating, &expense);
		float wage = basic + floating - expense;
		printf("%s %.2f\n", name, wage);
	}

	return 0;
}