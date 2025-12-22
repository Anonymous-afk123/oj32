#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	char word[256];
	int alpha[26] = {0};
	int found_any = 0;

	if (scanf("%s", word) == EOF)
		return 0;

	while (scanf("%s", word) != EOF) {
		// 3. 判断是否为选项：以 '-' 开头，且第二个字符是字母，且长度为2
		// 注意：根据题目样例，选项似乎是单字母格式 "-a"
		if (word[0] == '-' && isalpha(word[1]) && strlen(word) == 2) {
			alpha[word[1] - 'a'] = 1; // 标记该字母出现过
			found_any = 1;
		}
	}

	if (!found_any) {
		printf("no\n");
	} else {
		// 4. 按字母顺序输出
		for (int i = 0; i < 26; i++) {

			if (alpha[i]) {
				printf("-%c ", i + 'a');
			}
		}

		printf("\n");
	}

	return 0;
}