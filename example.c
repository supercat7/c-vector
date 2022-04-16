#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "vector.h"


int main(void) {
	vector v = vec("int");
	vec_push(v, 10);
	printf("Item: %i\n", (int)v->buf[0]);
	printf("Slots: %i\n", v->size);
	printf("Capacity: %i\n", v->capacity);
	printf("Type: %s\n", v->type);
	printf("Type Size: %i\n", v->elemsize);

	vec_free(v);
}