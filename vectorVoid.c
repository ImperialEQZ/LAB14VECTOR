#include "vectorVoid.h"
//Создание вектора с baseTypeSize типом
vectorVoid createVectorV(size_t n, const size_t baseTypeSize) {
    vectorVoid vec;
    vec.data = malloc(n * baseTypeSize);
    vec.size = 0;
    vec.capacity = n;

    if (vec.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    vec.size = 0;
    vec.capacity = n;
    vec.baseTypeSize = baseTypeSize;

    return vec;
}
/*изменяет количество
памяти, выделенное под хранение элементов вектора. */
void reserveVectorV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0){
        v->data = NULL;
    }

    if (newCapacity < v->size){
        v->size = newCapacity;
    }

    v->capacity = newCapacity;
    v->data = (int *) realloc(v->data, newCapacity * v->baseTypeSize);

    if (v->data == NULL){
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}
/*освобождает память, выделенную под
неиспользуемые элементы.*/
void shrinkToFitV(vectorVoid *v) {
    reserveVectorV(v, v->size);
}
//удаляет элементы из контейнера, но не освобождает выделенную память
void clearVectorV(vectorVoid *v) {
    v->size = 0;
}
//освобождает память, выделенную вектору
void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
    v->baseTypeSize = 0;
}