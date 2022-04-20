#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "vector.h"


void die(char* s) {
	perror(s);
	exit(1);
}

int main(void) {
	vector v = vec("int");
	if (v == NULL) die("vec");
	if (vec_push(v, (void*)10)!= 0) die("vec_push");
	printf("Item: %i\n", (int)v->buf[0]);
	printf("Slots: %i\n", v->size);
	printf("Capacity: %i\n", v->capacity);
	printf("Type: %s\n", v->type);
	printf("Type Size: %i\n", v->elemsize);
	if (vec_free(v)!= 0) die("vec_free");

	puts("");

	vector s = vec("string");
	if (s == NULL) die("vec");
	if (vec_push(s, "Hello World!")!= 0) die("vec_push");
	printf("Item: %s\n", (char*)s->buf[0]);
	printf("Slots: %i\n", s->size);
	printf("Capacity: %i\n", s->capacity);
	printf("Type: %s\n", s->type);
	printf("Type Size: %i\n", s->elemsize);
	vec_pop(s);
	printf("%s\n", (char*)s->buf[0]);
	if (vec_free(s)!= 0) die("vec_free");


	return 0; 
}