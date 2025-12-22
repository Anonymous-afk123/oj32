#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <io.h> // Windows 下使用 _chsize 截断文件

#define BUFFER_SIZE 1000

errno_t update_log_record(const char *filename, const char *search_str, const char *replace_str);

int main() {

	const char *log_file = "C:\\Users\\Administrator\\Desktop\\hello.log";
	const char *search_str = "[2023-10-27 10:00:01] INFO: System startup initiated.";
	const char *replace_str = "[2023-10-27 10:00:01] Memory usage exceeding 75%.";
	errno_t result = update_log_record(log_file, search_str, replace_str);

	if (result != 0) {
		char error_msg[256];
		strerror_s(error_msg, sizeof(error_msg), result);
		fprintf(stderr, "An error ocurred: %s\n", error_msg);
	} else {
		printf("Recorded updated successfully.\n");
	}

	_fcloseall();
	return 0;
}

errno_t update_log_record(const char *filename, const char *search_str, const char *replace_str) {
	if (filename == NULL || search_str == NULL || replace_str == NULL) {
		return EINVAL;
	}

	FILE *fp = NULL;
	errno_t err = fopen_s(&fp, filename, "r+");

	if (err != 0 || fp == NULL) {
		char error_msg[256];

		strerror_s(error_msg, sizeof(error_msg), errno);

		fprintf(stderr, "FAILED TO OPEN: %s", error_msg);
		exit(EXIT_FAILURE);
	}

	char buffer[BUFFER_SIZE];
	long target_pos = -1;
	long next_line_pos = -1;

// 1. 寻找目标位置
	while (1) {
		long current_line_start = ftell(fp);

		if (fgets(buffer, sizeof(buffer), fp) == NULL)
			break;

		if (strstr(buffer, search_str)) {
			target_pos = current_line_start;
			next_line_pos = ftell(fp); // 目标行下一行的起点
			break;
		}
	}

	if (target_pos == -1) {
		fclose(fp);
		return ENOENT; // 没找到
	}

	// 2. 将目标行之后的所有内容读入内存
	fseek(fp, 0, SEEK_END);
	long file_size = ftell(fp);
	long tail_size = file_size - next_line_pos;
	char *tail_data = NULL;

	if (tail_size > 0) {
		tail_data = (char *)malloc(tail_size);
		fseek(fp, next_line_pos, SEEK_SET);
		fread(tail_data, 1, tail_size, fp);
	}

	// 3. 回到目标位置，开始覆盖写入
	fseek(fp, target_pos, SEEK_SET);
	fputs(replace_str, fp);
	fputc('\n', fp); // 补一个换行

	// 4. 把尾巴接回来
	if (tail_data) {
		fwrite(tail_data, 1, tail_size, fp);
		free(tail_data);
	}

	// 5. 重要：截断文件（处理新内容比旧内容短的情况）
	long final_pos = ftell(fp);
	_chsize(_fileno(fp), final_pos); // Windows 强制截断多余部分

	fclose(fp);
	return 0;
}