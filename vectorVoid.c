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
//является ли вектор пустым
bool vector_isEmptyV(const vectorVoid v) {
    return v.size == 0;
}
//является ли вектор полным
bool vector_isFullV(const vectorVoid v) {
    return v.size == v.capacity;
}
//записывает по адресу destination index-ый элемент вектора v.
void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    if (!v->data) {//Ошибка доступа к памяти
        fprintf(stderr, "Error accessing vector memory");
    }
    if (v->size <= index) {//индекс за пределами вектора
        fprintf(stderr, "index has gone beyond range of vector");
    }

    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}
/*записывает на index-ый элемент вектора v значение, расположенное по
адресу source */
void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    if (!v->data) {//Ошибка доступа к памяти
        fprintf(stderr, "Error accessing vector memory");
    }
    if (v->size <= index) {//индекс за пределами вектора
        fprintf(stderr, "index has gone beyond range of vector");
    }

    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}
//Добавляет
void pushBackVectorV(vectorVoid *v, void *source) {
    if (!v->capacity)
        reserveVectorV(v, 1);

    if (v->size >= v->capacity)
        reserveVectorV(v, v->capacity * 2);

    setVectorValueV(v, v->size++, source);
}
//удаляет
void popBackVectorV(vectorVoid *v) {
    if (!v->data) {
        fprintf(stderr, "Error: Failed access to vector's memory in VectorpopBack\n");
    }

    if (v->size == 0) {
        fprintf(stderr,"Error: Vector is empty in VectorpopBack\n");
    }

    (v->size)--;
}





