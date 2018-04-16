#pragma once
#ifndef _SEQUENCE_H_
#define _SEQUENCE_H_

#include "Function.h"

void setting(size_t * const Row, size_t * const Colume, int * const begin, int * const end, size_t * const Continue);
void initialize(Array_2D *const _2D, const size_t Row, const size_t Colume, const int begin, const int end);
void execute(const Array_2D *const _2D, const size_t Continue);
void key_in_size_t(size_t *const Value, const char *const intent);
void key_in_int(int *const Value, const char *const intent);

static inline void clear(FILE *_Stream) {
	while (fgetc(_Stream) != '\n');
}

#endif
