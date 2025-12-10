#include <stdio.h>
#include <string.h>
void copystr(const char *s, int m);

int main() {
	char s[100];

	fgets(s, sizeof(s), stdin);
	int len = strlen(s);

	if (len > 0 && s[len - 1] == '\n')
		s[len - 1] = '\0';
	int m;
	scanf("%d", &m);
	copystr(s, m);
	return 0;
}

void copystr(const char *s, int m) {
	int n = strlen(s);

	if (n < m)
		puts("error");

	for (int i = m - 1; i < n; i++) {

		printf("%c", s[i]);
	}

}