#include <stdio.h>
# include <string.h>
#include <ctype.h>

int main() {
	char s[81];
	scanf("%s", s);
	printf("%s\n", s);

	int n = strlen(s);
	int isPalindrome = 1;

	for (int i = 0; i < n / 2; i++) {

		if (tolower(s[i]) != tolower(s[n - 1 - i])) {
			isPalindrome = 0;
			break;
		}
	}

	if (isPalindrome)
		puts("Yes");
	else
		puts("No");
	return 0;
}
