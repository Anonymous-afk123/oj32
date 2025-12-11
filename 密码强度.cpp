#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char s[60];
	int hasUpper = 0, hasLower = 0, hasDigit = 0, hasOther = 0;
	int score = 0;
	fgets(s, sizeof(s), stdin);
	int len = 0;

	while (s[len] != '\0' && s[len] != '\n') {
		len++;
	}

	if (len == 0) {
		printf("0");
		return 0;
	}

	score = 1;

	for (int i = 0; i < len; i++) {

		char c = s[i];

		if (c >= 'A' && c <= 'Z')
			hasUpper = 1;
		else if (c >= 'a' && c <= 'z')
			hasLower = 1;
		else if (c >= '0' && c <= '9')
			hasDigit = 1;
		else
			hasOther = 1;
	}

	if (len > 8)
		score += 1;
	score +=  hasUpper + hasLower + hasDigit + hasOther - 1;
	printf("%d", score);
	return 0;
}
