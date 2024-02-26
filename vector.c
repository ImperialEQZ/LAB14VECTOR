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

    vec.size = 0;
    vec.capacity = n;

    return vec;
}

void deleteVector(vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}

void clearVector(vector *v) {
    v->size = 0;
}

void reserveVector(vector *v, const size_t new_capacity) {
    if ( new_capacity == 0 ) {
        deleteVector(v);
    }
    else {
        if (v->size > new_capacity)
            v->size = new_capacity;

        v->capacity = new_capacity;
        v->data = realloc(v->data,v->capacity);
        if (!v->data) {
            fprintf(stderr, "bad alloc");
        }
    }
}

void shrinkToFit(vector *v) {
    reserveVector(v, v->size);
}


int main() {
    //vector v = createVector(SIZE_MAX);
    vector v = {NULL, 0, 0};
    reserveVector(&v, 5);

    for (size_t i = 0; i < 5; i++) {
        v.data[i] = i * 2;
        v.size++;
    }

    for (size_t i = 0; i < v.size; i++) {
        printf("%d ", v.data[i]);
    }
    printf("\n");

    reserveVector(&v, 3);

    for (size_t i = 0; i < v.size; i++) {
        printf("%d ", v.data[i]);
    }
    printf("\n");

    reserveVector(&v, 0);

    free(v.data);

    return 0;
}