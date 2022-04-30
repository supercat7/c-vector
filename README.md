# c-vector
dynamic array library for C


# Example Usage
```C
vector v = vec("int");
vector v = vec("string");
int status = vec_push(v, 10);
if (status != 0) {
	// handle error
}
// print out content
printf("%i\n",(int) v->buf[0]);
// or
for (int i=0; i <= v->size; i++) {
	printf("%i\n", v->buf[i]);
}
```