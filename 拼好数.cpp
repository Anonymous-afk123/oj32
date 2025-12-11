#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_STR_LEN 101
#define MAX_NUM_LEN 11
#define MAX_NUM_COUNT 100

int main() {
	char s[MAX_STR_LEN];
	int numbers[MAX_NUM_COUNT];
	int count = 0;

	// 使用 fgets 读取输入
	fgets(s, sizeof(s), stdin);
	s[strcspn(s, "\n")] = '\0'; // 去除末尾的换行符

	for (int i = 0; s[i];) {

		if (!isdigit(s[i])) {
			i++;
			continue;
		}

		int cnt = 0;

		while (isdigit(s[i])) {
			cnt = cnt * 10 + (s[i] - '0');
			i++;
		}

		numbers[count++] = cnt; // 将提取的数字存储到数组中
	}

	// 实现排序（这里可以使用任何排序算法）
	// 例如，使用简单的冒泡排序
	for (int i = 0; i < count - 1; i++) {

		for (int j = 0; j < count - i - 1; j++) {

			if (numbers[j] < numbers[j + 1]) {
				int temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;
			}
		}
	}

	// 输出排序后的数字
	for (int i = 0; i < count; i++) {

		printf("%d", numbers[i]);

		if (i < count - 1) {
			printf(" ");
		}
	}

	printf("\n");

	return 0;
}