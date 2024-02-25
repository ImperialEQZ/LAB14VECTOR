//
// Created by Александр on 25.02.2024.
//
#include "vector.h"
vector createVector(size_t n) {
    vector vec;
    vec.data = malloc(n * sizeof(int));
    vec.size = 0;
    vec.capacity = n;

    if (vec.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return vec;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data);
        v->data = NULL;
    } else if (newCapacity < v->size) {
        v->size = newCapacity;
        v->capacity = newCapacity;
        v->data = realloc(v->data, newCapacity * sizeof(int));
    } else {
        int *newData = realloc(v->data, newCapacity * sizeof(int));
        if (newData == NULL) {
            fprintf(stderr, "Error: Unable to allocate memory\n");
            exit(1);
        }
        v->data = newData;
        v->capacity = newCapacity;
    }
}

int main() {
    //vector v = createVector(SIZE_MAX);
    vector v = {NULL, 5, 8};
    reserve(&v, 3);

    for (size_t i = 0; i < 5; i++) {
        v.data[i] = i * 2;
        v.size++;
    }

    for (size_t i = 0; i < v.size; i++) {
        printf("%d ", v.data[i]);
    }
    printf("\n");

    reserve(&v, 3);

    for (size_t i = 0; i < v.size; i++) {
        printf("%d ", v.data[i]);
    }
    printf("\n");

    reserve(&v, 0);

    free(v.data);

    return 0;
}