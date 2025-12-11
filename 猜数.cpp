#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>

int main() {
	uint32_t secret_num, guess;
	srand(time(NULL));
	secret_num = rand() % 100 + 1;

	puts("猜猜我想的是哪一个数(1-100)?");

	do {
		puts("请输入你的预测:");
		scanf("%d", &guess);

		if (guess < secret_num) {
			puts("太小了，再试试看!");
		} else if (guess > secret_num) {
			puts("太大了，再试试看");
		}
	} while (guess != secret_num);

	printf("恭喜你，猜对了!");


	return 0;
}
