#include <stdio.h>

int main() {
	char s[110];
	char left[110], right[110];//left：放 ASCII > 首字符 的字符; right：放 ASCII ≤ 首字符 的字符
	int L = 0, R = 0;//分别记录 left/right 的长度

	fgets(s, sizeof(s), stdin);

	int len = 0;

	while (s[len] != '\0') {
		if (s[len] == '\n')
			s[len] = '\0';
		len++;
	}	//fgets 会把换行符 \n 读进来，因此要处理掉

	char c = s[0]; //记录首字符

	for (int i = 1; s[i] != '\0'; i++) {

		if ((unsigned char)s[i] > (unsigned char)c)
			left[L++] = s[i];
		else
			right[R++] = s[i];
	}

	for (int i = 0; i < R - 1; i++) {

		for (int j = 0; j < R - i - 1; j++) {

			if ((unsigned char)right[j] > (unsigned char)right[j + 1]) {
				char tmp = right[j];
				right[j] = right[j + 1];
				right[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < L; i++)

		printf("%c", left[i]);
	printf("%c", c);

	for (int i = 0; i < R; i++)

		printf("%c", right[i]);
	return 0;
}