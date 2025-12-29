#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char s[21];
	scanf("%s", s);
	int n = strlen(s);
	int alphaNum = 0, numNum = 0;

	for (int i = 0; i < n; i++) {

		if (isdigit(s[i]))
			numNum++;

		if (isalpha(s[i]))
			alphaNum++;
	}

	printf("%d,%d", alphaNum, numNum);
	return 0;
}