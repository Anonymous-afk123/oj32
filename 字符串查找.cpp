#include <stdio.h>
#include <string.h>
#include <ctype.h>

void fun(char *s);
int main() {

	char s[100];
	scanf("%s", s);
	fun(s);

	return 0;
}

void fun(char *s) {
	int n = strlen(s);
	int sum = 0;

	for (int i = 0; i < n; i++) {

		if (isalpha(s[i]))
			sum++;
	}

	printf("%d", sum);
}