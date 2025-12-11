#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char c;
	int n;
	char s[110];

	scanf("%c %d", &c, &n);
	scanf("%s", s);
	int len;
	len = strlen(s);
	int count = 0;

	for (int i = 0; i < len; i++) {

		if (n == 1) {
			// 大小写敏感
			if (s[i] == c)
				count++;
		} else {
			// 大小写不敏感，统一转换为小写比较
			if (tolower(s[i]) == tolower(c))
				count++;
		}
	}

	printf("%d\n", count);
	return 0;
}