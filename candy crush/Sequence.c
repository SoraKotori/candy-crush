#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "Sequence.h"

void setting(size_t *const Row, size_t *const Colume, int *const begin, int *const end, size_t *const Continue) {
	printf("%s:%zu %s:%zu %s:%d~%d %s:%zu \n%s:", "Row", *Row, "Colume", *Colume, "number", *begin, *end, "Continue", *Continue, "Y/n");
	clear(stdin);
	if (toupper(getchar()) != 'Y') {
		key_in_size_t(Row, "Row");
		key_in_size_t(Colume, "Colume");
		key_in_int(begin, "begin");
		key_in_int(end, "end");
		key_in_size_t(Continue, "Continue");
	}
}

void initialize(Array_2D *const _2D, const size_t Row, const size_t Colume, const int begin, const int end) {
	create(_2D, Row, Colume);
	random_interval(begin, end);
	random(_2D);
}

void execute(const Array_2D *const _2D, const size_t Continue) {
	printf("do? Y/n:");
	clear(stdin);
	while (toupper(getchar()) == 'Y') {
		check(_2D, Continue);
		print(_2D);
		printf("do again? Y/n:");
		clear(stdin);
	}
}

void key_in_size_t(size_t *const Value, const char *const intent) {
	while (true) {
		printf("%s:", intent);
		clear(stdin);
		if (scanf_s("%zu", Value)) {
			if (*Value) {
				return;
			}
		}
	}
}

void key_in_int(int *const Value, const char *const intent) {
	while (true) {
		printf("%s:", intent);
		clear(stdin);
		if (scanf_s("%d", Value)) {
			return;
		}
	}
}