#include <stdio.h>
#include <string.h>

int main() {
	char word[101];
	int max = 0;

	while (scanf("%s", word) != EOF) {
		int len = strlen(word);

		// 检查最后一个字符是不是点号
		if (word[len - 1] == '.') {
			len--; // 不计入点号的长度

			if (len > max)
				max = len;
			break; // 读到点号，按照题目说明，句子结束了
		}

		if (len > max) {
			max = len;
		}
	}

	printf("%d", max);
	return 0;
}