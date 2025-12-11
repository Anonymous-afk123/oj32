#include <stdio.h>
#include <string.h>

int main() {
	char line[101];        // 当前读入的行
	char longest[101];     // 最长的那一行
	int max_length = 0;    // 最长行的长度
	int current_length;    // 当前行的长度

	// 循环读取每一行
	while (1) {
		// 读取一行
		gets(line);

		// 检查是否结束
		if (strcmp(line, "***end***") == 0) {
			break;
		}

		// 计算当前行的长度
		current_length = strlen(line);

		// 如果比之前的最长行还要长，就更新
		if (current_length > max_length) {
			max_length = current_length;
			strcpy(longest, line);
		}
	}

	// 输出结果
	printf("%d\n", max_length);
	printf("%s\n", longest);

	return 0;
}