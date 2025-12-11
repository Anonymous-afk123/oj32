#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <math.h>
#include <windows.h>

int main() {
	// 进度条
	const uint32_t total_steps = 100;

	puts("处理中，请稍候：");

	for (uint32_t i = 0; i <= total_steps; i++) {

		printf("\r[");

		for (uint32_t j = 0; j < i; j++) {

			printf("#");
		}

		for (uint32_t j = i; j < total_steps; j++) {

			printf(" ");
		}

		printf("] %"PRIu32 "%%", (i * 100) / total_steps);

		Sleep(100);
	}

	puts("\n处理完成！");
}