#include <stdio.h>
#include <ctype.h>

int main() {
	char s[51];
	scanf("%s", s);

	for (int i = 0; s[i] != '\0';) {

		char ch = s[i++];
		int cnt = 0;

		while (isdigit(s[i])) {
			cnt = cnt * 10 + (s[i] - '0');
			i++;
		}

		if (cnt == 0)
			cnt = 1;

		for (int j = 0; j < cnt; j++) {

			putchar(ch);
		}
	}

	putchar('\n');
	return 0;
}