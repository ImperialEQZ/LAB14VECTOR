//
// Created by Александр on 25.02.2024.
//
#include "vector.h"
//возвращает структуру-дескриптор вектор из n значений
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
//освобождает память, выделенную вектору
void deleteVector(vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}
//удаляет элементы из контейнера, но не освобождает выделенную память
void clearVector(vector *v) {
    v->size = 0;
}
/*изменяет количество
памяти, выделенное под хранение элементов вектора. */
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
//возвращает i-ый элемент вектора v.
int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}
/*Добавляет элемент x в конец вектора v.
Если вектор заполнен, количество выделенной ему памяти увеличено в
2 раза, используя reserve. */
void pushBackVector(vector *v, const int x) {
    if (!v->capacity)
        reserveVector(v, 1);

    if (v->size >= v->capacity)
        reserveVector(v, v->capacity * 2);

    v->data[v->size++] = x;
}
/*освобождает память, выделенную под
неиспользуемые элементы.*/
void shrinkToFit(vector *v) {
    reserveVector(v, v->size);
}
//является ли вектор пустым
bool vector_isEmpty(const vector v) {
    return v.size == 0;
}
//является ли вектор полным
bool vector_isFull(const vector v) {
    return v.size == v.capacity;
}
//удаляет последний элемент из вектора.
void VectorpopBack(vector *v) {
    if (!v->data) {
        printf("Error: Failed access to vector's memory in VectorpopBack\n");
        return;
    }

    if (v->size == 0) {
        printf("Error: Vector is empty in VectorpopBack\n");
        return;
    }

    v->size--;
    v->data[v->size] = 0;
}

int* atVector(vector *v, size_t index) {
    if (!v->data) {
        printf("Error: Failed access to vector's memory in atVector\n");
        return NULL;
    }

    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[index] is not exists");
        exit(1);
    }

    return v->data + index;
}

int* back(vector *v){

    if (!v->size){
        return &v->data[v->size];
    }

    return &v->data[v->size - 1];
}

int* front(vector *v) {
    if (!v->data) {
        fprintf(stderr, "Error accessing vector memory");
    }

    return v->data;
}


//Тесты функций
void test_pushBackVector_emptyVector() {

    vector v = createVector(5);

    pushBackVector(&v,10);

    printf("pushBack_emptyVector :%d\n", v.data[0]);

}

void test_pushBackVector_fullVector(){

    vector v = createVector(5);

    v.size = 5;
    v.data[0] = 20;
    v.data[1] = 20;
    v.data[2] = 20;
    v.data[3] = 20;
    v.data[4] = 20;

    pushBackVector(&v, 21);

    printf("\n pushBack_fullVector: %d\n", v.data[5]);

}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBackVector(&v, 10);
    assert(v.size == 1);
    VectorpopBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_atVector_notEmptyVector() {

    vector v = createVector(5);

    v.size = 4;
    v.data[0] = 20;
    v.data[1] = 21;
    v.data[2] = 22;
    v.data[3] = 23;

    printf("\n atVector_notEmptyVector address: %d\n", atVector(&v, 2));
    printf("\n atVector_notEmptyVector value: %d\n", *atVector(&v, 2));
}

void test_atVector_requestToLastElement(){

    vector v = createVector(5);

    v.size = 3;
    v.data[0] = 20;
    v.data[1] = 20;
    v.data[2] = 20;

    printf("\n requestToLastElement value: %d \n", *atVector(&v, 2));
    printf("\n requestToLastElement address: %d \n", atVector(&v, 2));
}

void test_back_oneElementInVector(){

    vector v = createVector(5);

    v.size = 1;
    v.data[0] = 20;

    printf("\n back_oneElementInVector address: %d \n", back(&v));
    printf("\n back_oneElementInVector value: %d \n", *back(&v));
}

void test_front_oneElementInVector() {

    vector v = createVector(5);

    v.size = 1;
    v.data[0] = 20;

    printf("\n front_oneElementInVector address: %d \n", back(&v));
    printf("\n front_oneElementInVector value: %d \n", *back(&v));
}
int main() {

    test_popBack_notEmptyVector();
    test_pushBackVector_emptyVector();
    test_pushBackVector_fullVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();

    return 0;
}