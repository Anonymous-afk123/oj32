#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <math.h>

int main() {
	uint32_t num;
	scanf("%" SCNu32, &num);
	printf("³Ë·¨±í %"PRIu32":\n", num);

	for (uint32_t i = 1; i < 10; i++) {

		printf("%" PRIu32 " * %" PRIu32 " = %" PRIu32 "\n", num, i, num * i);

	}

	return 0;
}