#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

	char s[10];
	scanf("%s", s);
	int n = strlen(s);
	int sum = 0;

	for (int i = 0; i < n; i++) {

		sum += s[i] - '0';
	}

	int parity = !(sum % 2);
	printf("%d %d %d", n, sum, parity);
	return 0;
}