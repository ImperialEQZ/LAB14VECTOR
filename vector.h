//
// Created by Александр on 25.02.2024.
//
#ifndef LAB14VECTOR_VECTOR_H
#define LAB14VECTOR_VECTOR_H
#include <stdio.h>
#include <malloc.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;
#endif //LAB14VECTOR_VECTOR_H
