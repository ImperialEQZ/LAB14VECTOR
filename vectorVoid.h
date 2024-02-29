//
// Created by Александр on 29.02.2024.
//
#ifndef LAB14VECTOR_VECTORVOID_H
#define LAB14VECTOR_VECTORVOID_H
#include <limits.h>
#include <stdio.h>
#include <malloc.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
typedef struct vectorVoid {
    void *data; // указатель на нулевой элемент вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; /* размер базового типа:
например, если вектор хранит int -
то поле baseTypeSize = sizeof(int)
если вектор хранит float - то поле baseTypeSize = sizeof(float) */
} vectorVoid;
#endif //LAB14VECTOR_VECTORVOID_H
