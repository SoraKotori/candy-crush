#include <stdio.h>
#include <stdlib.h>
#include "Function.h"

static inline int random_number(void);
static inline int digit(int number);
static inline void move(const Array_2D *const _2D, size_t Row, const size_t Colume);
static inline int compare(const int begin, const int end);

static struct {
	int begin;
	int difference;
	int length;
}rand_number;

void create(Array_2D *const _2D, const size_t Row, const size_t Colume) {
	if (Row && Colume) {
		_2D->Place_1D = (int*)malloc(sizeof(int) * Row * Colume);
		_2D->Place_2D = (int**)malloc(sizeof(int*) * Row);
		_2D->Row = Row;
		_2D->Colume = Colume;
		if (_2D->Place_2D && _2D->Place_1D) {
			for (size_t i = 0; i < Row; i++) {
				_2D->Place_2D[i] = &_2D->Place_1D[i* _2D->Colume];
			}
		}
	}
}

void destroy(Array_2D *const _2D) {
	free(_2D->Place_2D);
	free(_2D->Place_1D);
	_2D->Place_2D = NULL;
	_2D->Place_1D = NULL;
}

void random(const Array_2D *const _2D) {
	for (size_t i = 0, size = _2D->Row * _2D->Colume; i < size; i++) {
		_2D->Place_1D[i] = random_number();
	}
}

void random_interval(const int begin, const int end) {
	if (end > begin) {
		rand_number.begin = begin;
		rand_number.difference = end - begin + 1;
		rand_number.length = compare(begin, end);
	}
}

static inline int random_number(void) {
	return rand() % rand_number.difference + rand_number.begin;
}

static inline int digit(int number) {
	int count = 0;
	do {
		count++;
		number /= 10;
	} while (number);
	return count;
}

static inline int compare(const int begin, const int end) {
	int a = begin >= 0 ? digit(begin) : digit(begin) + 1;
	int b = end >= 0 ? digit(end) : digit(end) + 1;
	return (a > b ? a : b) + 1;
}

void print(const Array_2D *const _2D) {
	for (size_t i = 0, size = _2D->Row * _2D->Colume; i < size; i++) {
		printf("%*d%s", rand_number.length, _2D->Place_1D[i], ((i + 1) % _2D->Colume) ? "" : "\n");
	}
}

void check(const Array_2D *const _2D, const size_t Continue) {
	for (size_t i = _2D->Row - 1; (signed)i >= 0; i--) {
		for (size_t j = 0, count = 1U, end = _2D->Colume - 1U; j <= end; j++) {
			if (j < end && _2D->Place_2D[i][j] == _2D->Place_2D[i][j + 1U]) {
				count++;
			}
			else if (count < Continue) {
				count = 1U;
			}
			else {
				do {
					move(_2D, i, j - --count);
				} while (count);
				return;
			}
		}
	}
}

static inline void move(const Array_2D *const _2D, size_t Row, const size_t Colume) {
	while (Row) {
		_2D->Place_2D[Row][Colume] = _2D->Place_2D[Row - 1][Colume];
		Row--;
	}
	_2D->Place_2D[Row][Colume] = random_number();
}