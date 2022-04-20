#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
	int capacity;
	int size;
	int elemsize;
	char* type;
	void** buf;
} vector_t;

#define vector vector_t*

vector vec(char* type);
int vec_free(vector v);
int vec_realloc(vector v, int size);
int vec_push(vector v, void* item);
int vec_pop(vector v); 

#endif