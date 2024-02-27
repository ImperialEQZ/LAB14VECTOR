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

void reserveVector(vector *v, size_t newCapacity) {
    if (newCapacity == 0){
        v->data = NULL;
    }

    if (newCapacity < v->size){
        v->size = newCapacity;
    }

    v->capacity = newCapacity;
    v->data = (int *) realloc(v->data, newCapacity * sizeof(int));

    if (v->data == NULL){
        fprintf(stderr, "bad alloc");
        exit(1);
    }

}

void pushBackVector(vector *v, const int x) {
    if (!v->capacity)
        reserveVector(v, 1);

    if (v->size >= v->capacity)
        reserveVector(v, v->capacity * 2);

    v->data[v->size++] = x;
}

void shrinkToFit(vector *v) {
    reserveVector(v, v->size);
}

bool vector_isEmpty(const vector v) {
    return v.size == 0;
}

bool vector_isFull(const vector v) {
    return v.size == v.capacity;
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