#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char s[110];
	int def, n;

	// 读取模式字符串
	scanf("%s", s);

	// 读取大小写敏感选项
	scanf("%d", &def);

	// 读取行数
	scanf("%d", &n);

	// 处理每一行
	for (int i = 0; i < n; i++) {

		char line[110];
		scanf("%s", line);

		int found = 0;
		int line_len = strlen(line);
		int s_len = strlen(s);

		if (def == 1) { // 大小写敏感
			// 在line中查找s
			for (int j = 0; j <= line_len - s_len; j++) {

				int match = 1;

				for (int k = 0; k < s_len; k++) {

					if (line[j + k] != s[k]) {
						match = 0;
						break;
					}
				}

				if (match) {
					found = 1;
					break;
				}
			}
		} else { // 大小写不敏感
			// 在line中查找s（忽略大小写）
			for (int j = 0; j <= line_len - s_len; j++) {

				int match = 1;

				for (int k = 0; k < s_len; k++) {

					if (tolower(line[j + k]) != tolower(s[k])) {
						match = 0;
						break;
					}
				}

				if (match) {
					found = 1;
					break;
				}
			}
		}

		// 如果找到匹配，输出该行
		if (found) {
			printf("%s\n", line);
		}
	}

	return 0;
}