#include <stdio.h>
#include <string.h>

int main() {
	char n[10];
	int sum = 0;
	scanf("%s", n);

	for (int i = 0; i < strlen(n); i++) {

		sum += n[i] - '0';
	}

	printf("%d\n", sum);

	return 0;
}
