#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "vector.h"


vector vec(char* type) {
	vector v = malloc(sizeof(vector));

	v->capacity = 0;
	v->size = -1;
	v->type = malloc(strlen(type));
	
	volatile int size = 0;
	if (strcmp(type, "char") == 0) {
		size = sizeof(char);
		strcpy(v->type, "char");
	} else if (strcmp(type, "int") == 0) {
		size = sizeof(int);
		strcpy(v->type, "int");
	} else if (strcmp(type, "string") == 0) {
		size = 0;	// string is not a type
		strcpy(v->type, "string");
	} else if (strcmp(type, "struct") == 0) {
		size = sizeof(int ) * 2;
		strcpy(v->type, "struct");
	} else {
		return NULL;
	}
	
	v->elemsize = size;
	v->buf = malloc(0);
	return v;
}

void vec_free(vector v) {
	if (strcmp(v->type, "string") == 0) {
		for (int i=0; i < v->size; i++) {
			free(v->buf[i]);
		}
	}
	free(v->buf);
	free(v->type);
	free(v);
	v = NULL;
}

int vec_realloc(vector v, int size) {
	v->capacity = size;
	v->buf = realloc(v->buf, size);
	if (v->buf == NULL) return -1;
	return 0;
}

int vec_push(vector v, void* item) {
	v->size++;
	// string (char array)
	if (strcmp(v->type, "string") == 0) {
		char* str = (char*)item;
		int len = strlen(str);
		if (vec_realloc(v, v->capacity + len) != 0) {
			return -1;
		}
		v->buf[v->size] = realloc(v->buf[v->size], len +1);
		strcpy((char*)v->buf[v->size], str);
	} else {
		if (vec_realloc(v, v->capacity + v->elemsize) != 0) {
			return -1;
		}
		v->buf[v->size] = item;
	}
	return 0;
}