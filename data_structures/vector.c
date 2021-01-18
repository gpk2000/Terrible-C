#include "../helper/prints.h"
#include <stdbool.h>

#define DEF_CAPACITY 16
#define SHRINK_FACTOR 4
#define GROW_FACTOR 2

typedef struct {
	int *array;
	size_t size;
	size_t capacity;
} vector;

void initVector (vector *v) {
	v -> array = malloc(DEF_CAPACITY * sizeof(int));
	v -> size = 0;
	v -> capacity = DEF_CAPACITY;
}

size_t getSize (vector *v) {
	return v -> size;
}

size_t getCapacity (vector *v) {
	return v -> capacity;	
}

bool isEmpty (vector* v) {
	return getSize (v) == 0;
}

int at (vector *v, int index) {
	return v -> array[index];
}

void push (vector *v, int element) {
	if (v -> size == v -> capacity) {
		v -> capacity *= GROW_FACTOR;
		v -> array = realloc (v -> array, (v -> capacity) * sizeof(int));
	}
	v -> size += 1;
	v -> array[v -> size] = element;
}


int main (void) {
	struct vector v;
	printf ("%d %d", v.capacity, v.size);
	return 0;
}
