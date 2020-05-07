#include <string.h>

typedef struct 
{
    int *ptr; //указатель
    unsigned int size; //количество заполненных элементов счетчик
    unsigned int capacity; //вместимость счетчик
}IntVector;
//typedef используется для создания псевдонима для другого типа данных.
//malloc calloc, realoc в случае успеха возвращает адрес на первый байт памяти, а в случае ошибки NULL
//size_t целочисленный тип size_t обычно применяется для счетчиков циклов, индексации массивов,
//хранения размеров, адресной арифметики.Можно было записать максимальный размер теоретически возможного 
//массива любого типа для 32 разрядных систем 2^32, а для 64 разрядных 2^64	
void printarray(IntVector *z);
void check(int a);
int vector_push_back(IntVector *z, int a);
void vector_free(IntVector* z);
size_t int_vector_get_capacity(const IntVector *v);
IntVector* new_vector(size_t initial_capacity);
void int_vector_pop_back(IntVector* z);
int int_vector_reserve(IntVector* z, size_t new_capacity);
IntVector* int_vector_copy(const IntVector *z);
int int_vector_shrink_to_fit(IntVector* z);
int int_vector_resize(IntVector* z, int new_size);
int int_vector_set_item(IntVector *z, size_t index, int item);
size_t int_vector_get_size(const IntVector *v);
int vector_get_item(const IntVector *z, size_t a); 