#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "vector.h"


vector vec(char* type) {
	vector v = malloc(sizeof(*v));
	if (v == NULL || type == NULL) return NULL;

	v->capacity = 0;
	v->size = -1;
	v->type = malloc(strlen(type) +1);
	if (v->type == NULL) return NULL;
	
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
	} else {
		return NULL;
	}
	
	v->elemsize = size;
	v->buf = malloc(0);
	return v;
}

int vec_free(vector v) {
	if (v == NULL) return -1;
	if (strcmp(v->type, "string") == 0) {
		for (int i=0; i < v->size; i++) {
			free(v->buf[i]);
			v->buf[i] = NULL;
		}
	}
	free(v->buf);
	free(v->type);
	free(v);
	v = NULL;
	return 0;
}

int vec_realloc(vector v, int size) {
	v->capacity = size;
	void** newptr;
	newptr = realloc(v->buf, size);
	v->buf = newptr;
	if (v->buf == NULL) return -1;
	return 0;
}

int vec_push(vector v, void* item) {
	v->size++;
	if (strcmp(v->type, "string") == 0) {
		char* str = (char*)item;
		int len = strlen(str);
		if (vec_realloc(v, v->capacity + len) != 0) {
			return -1;
		}
		v->buf[v->size] = malloc(len +1);
		strcpy((char*)v->buf[v->size], str);
	} else {
		if (vec_realloc(v, v->capacity + v->elemsize) != 0) {
			return -1;
		}
		v->buf[v->size] = item;
	}
	return 0;
}

