#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "Sequence.h"

int main(void) {
	int begin = 1, end = 4;
	size_t Row = 9U, Colume = 9U, Continue = 3U;
	Array_2D candy_crush;
	srand((unsigned)time(NULL));

	printf("Start? Y/n:");
	if (toupper(getchar()) == 'Y') {
		do {
			setting(&Row, &Colume, &begin, &end, &Continue);
			initialize(&candy_crush, Row, Colume, begin, end);
			print(&candy_crush);
			execute(&candy_crush, Continue);
			destroy(&candy_crush);
			printf("exit? Y/n:");
			clear(stdin);
		} while (toupper(getchar()) != 'Y');
	}
	return 0;
}
