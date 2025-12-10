#include <stdio.h>
#include <inttypes.h>
//匿名结构体
typedef struct {
	char name[50];
	int id;
	float score;
} Student;

void print_stu(Student stu);

void update_score_by_value(Student *stu, float new_score);
int main() {

	Student stu = { "John DOe", 123, 89};

	puts("Before update:\n");

	print_stu(stu);

	update_score_by_value(&stu, 100);

	puts("After update by reference:\n");

	print_stu(stu);

	return 0;
}

void print_stu(Student stu) {
	printf("Student Name: %s\n", stu.name);
	printf("Student Id: %d\n", stu.id);
	printf("Student Score: %.2f\n", stu.score);
}

void update_score_by_value(Student *stu, float new_score) {
	stu->score = new_score;
}