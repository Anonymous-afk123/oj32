#include <stdio.h>
#include <string.h>

int main() {
	char s1[1005], s2[1005];
	int n1[1005] = {0};
	int n2[1005] = {0};
	int sum[1005] = {0};

	// 输入
	scanf("%s", s1);
	scanf("%s", s2);

	int len1 = strlen(s1);
	int len2 = strlen(s2);

	for (int i = 0; i < len1; i++) {

		n1[i] = s1[len1 - 1 - i] - '0';
	}

	for (int i = 0; i < len2; i++) {

		n2[i] = s2[len2 - 1 - i] - '0';
	}

	// 确定运算的最大长度
	int max_len = len1 > len2 ? len1 : len2;

	for (int i = 0; i < max_len; i++) {

		sum[i] += n1[i] + n2[i]; // 当前位累加

		if (sum[i] >= 10) {      // 处理进位
			sum[i + 1] += 1;     // 下一位加1
			sum[i] %= 10;        // 当前位保留个位
		}
	}

	int result_len = max_len;

	if (sum[result_len] > 0) {
		result_len++;
	}

	// 6. 倒序打印 (去除前导零的逻辑其实就是确定了 result_len)
	// 从最高位往回打印
	for (int i = result_len - 1; i >= 0; i--) {

		printf("%d", sum[i]);
	}

	printf("\n");

	return 0;
}