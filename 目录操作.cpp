#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 201
#define MAX_DIRS 100  // 最大目录深度

int main() {
	char current[MAX_LEN];
	char dirs[MAX_DIRS][MAX_LEN];  // 目录名数组
	int depth = 0;  // 当前目录深度

	// 读取初始目录
	fgets(current, MAX_LEN, stdin);
	current[strcspn(current, "\n")] = '\0';

	// 解析初始目录到数组
	if (strcmp(current, "/") == 0) {
		depth = 0;  // 根目录，深度为0
	} else {
		// 跳过开头的'/'
		char *token = strtok(current + 1, "/");
		depth = 0;

		while (token != NULL && depth < MAX_DIRS) {
			strcpy(dirs[depth], token);
			depth++;
			token = strtok(NULL, "/");
		}
	}

	char command[MAX_LEN];
	char target[MAX_LEN];

	// 处理命令
	while (fgets(command, MAX_LEN, stdin)) {
		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "pwd") == 0) {
			break;
		}

		// 解析cd命令
		if (sscanf(command, "cd %s", target) == 1) {
			if (strcmp(target, "/") == 0) {
				// 切换到根目录
				depth = 0;
			} else if (strcmp(target, "..") == 0) {
				// 返回上级目录
				if (depth > 0) {
					depth--;
				}
			} else if (target[0] == '/') {
				// 绝对路径
				depth = 0;
				char *token = strtok(target + 1, "/");

				while (token != NULL && depth < MAX_DIRS) {
					if (strcmp(token, "..") == 0) {
						if (depth > 0)
							depth--;
					} else if (strcmp(token, ".") != 0) {
						strcpy(dirs[depth], token);
						depth++;
					}

					token = strtok(NULL, "/");
				}
			} else {
				// 相对路径，需要处理可能包含多个目录和".."
				char temp[MAX_LEN];
				strcpy(temp, target);
				char *token = strtok(temp, "/");

				while (token != NULL && depth < MAX_DIRS) {
					if (strcmp(token, "..") == 0) {
						if (depth > 0)
							depth--;
					} else if (strcmp(token, ".") != 0) {
						strcpy(dirs[depth], token);
						depth++;
					}

					token = strtok(NULL, "/");
				}
			}
		}
	}

	// 输出结果
	if (depth == 0) {
		printf("/\n");
	} else {
		for (int i = 0; i < depth; i++) {

			printf("/%s", dirs[i]);
		}

		printf("\n");
	}

	return 0;
}