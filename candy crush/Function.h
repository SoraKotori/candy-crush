#pragma once

#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <stddef.h>

typedef struct {
	int *Place_1D;
	int **Place_2D;
	size_t Row;
	size_t Colume;
}Array_2D;

void create(Array_2D *const _2D, const size_t Row, const size_t Colume);
void destroy(Array_2D *const _2D);
void random(const Array_2D *const _2D);
void random_interval(const int begin, const int end);
void print(const Array_2D *const _2D);
void check(const Array_2D *const _2D, const size_t continuous);

#endif 
