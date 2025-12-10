#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>

#define EXP_PER_LEVEL 100
#define MAX_LEVEL 10
#define HINT_COUNT 10
void increase_exp(int32_t *exp, int32_t amount);
const char *get_treasure_hint(int32_t level);
bool check_level_up(int32_t *exp,  int32_t *level);


int main() {

	int32_t player_exp = 0;
	int32_t player_level = 1;
	increase_exp(&player_exp, 50);
	increase_exp(&player_exp, 175);

	if (!check_level_up(&player_exp, &player_level)) {
		printf("Need more exp to level up!\n");
	}

	return 0;
}

void increase_exp(int32_t *exp, int32_t amount) {
	*exp += amount;
}

bool check_level_up(int32_t *exp,  int32_t *level) {
	bool is_level_up = false;  // 标记是否升级

	// 循环：只要经验足够且等级未到上限，就连续升级
	while (*exp >= EXP_PER_LEVEL && *level < MAX_LEVEL) {
		*exp -= EXP_PER_LEVEL;
		(*level)++;
		is_level_up = true;  // 标记已升级
		// 每升一级，立即打印对应等级的提示
		printf("up to %" PRId32 " level!\n", *level);
		printf("Unlock %" PRId32 " level treasure chest: %s\n",
		       *level, get_treasure_hint(*level));
	}

	return is_level_up;  // 循环结束后返回是否升级
}

const char *get_treasure_hint(int32_t level) {
	static const char *hints[HINT_COUNT] = {
		"hint 1 (level 1)",
		"hint 2 (level 2)",
		"hint 3 (level 3)",
		"hint 4 (level 4)",
		"hint 5 (level 5)",
		"hint 6 (level 6)",
		"hint 7 (level 7)",
		"hint 8 (level 8)",
		"hint 9 (level 9)",
		"hint 10 (level 10)"
	};

	if (level > 0 && (size_t)level <= HINT_COUNT) {
		return hints[(size_t)level - 1];
	}

	return "Unknown hint, please ensure you are in the valid range!";

}



