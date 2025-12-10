#include <stdio.h>
#include <inttypes.h>

#define EMPLOYEES 5

void update_salary(uint32_t *salaries, uint32_t increment);
void print_emp(uint32_t *salaries);
uint32_t calc_bonus(uint32_t salary);
uint32_t *find_highest_salary(const uint32_t *salaries);
int main() {

	uint32_t salaries[EMPLOYEES] = { 3000, 4000, 3500, 4500, 4200};

	uint32_t increment = 10000;

	update_salary(salaries, increment);
	print_emp(salaries);
	uint32_t *highest_salary = find_highest_salary(salaries);

	printf("Highest salary: %"PRIu32"\n", *highest_salary);
	printf("calc_bouns: %"PRIu32"\n", calc_bonus(*highest_salary));
	return 0;
}

void update_salary(uint32_t *salaries, uint32_t increment) {
	for (size_t i = 0; i < EMPLOYEES; ++i) {

		salaries[i] += increment;

	}

}

void print_emp(uint32_t *salaries) {
	for (size_t i = 0; i < EMPLOYEES; ++i) {

		printf("%d ", salaries[i]);
	}

	printf("\n");
}

uint32_t calc_bonus(uint32_t salary) {
	return salary / 10;
}

uint32_t *find_highest_salary(const uint32_t *salaries) {
	const uint32_t *highest = salaries;

	for (int  i = 0; i < EMPLOYEES; i++) {

		if (*highest < salaries[i])
			highest = &salaries[i];
	}

	return (uint32_t *)highest;
}
