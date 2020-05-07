#include <string.h>
#include "IntVector.h"
#include <stdlib.h>
#include <stdio.h>

void printarray(IntVector *z)//выводит массив
{
    for (int i = 0; i < z->capacity; ++i)
    {
        printf("a[%d]=%d ",i ,z->ptr[i]);
    }
    printf("\n");
}

void check(int a) //проверка return
{
    if (a==-1)
    {
        printf("Ошибка! Программа завершена\n");
        exit(-1);
    }
}

int vector_push_back(IntVector *z, int item)
{
    if (z->capacity == z->size)
    {
        int *array=realloc(z->ptr,(sizeof(int)*2*z->capacity));
        if (!array)
        {
            return -1;
        }
        z->ptr = array;
        z->capacity=z->capacity*2;
        for (int i =z->size ; i < z->capacity; ++i)
        {
            z->ptr[i]=0;
        }
    }
 z->ptr[z->size]=item;
 z->size++;
 return 0;
}

void vector_free(IntVector* z)
{
 free(z->ptr);
 z->size=0;
 z->capacity=0;
 free(z);
}

size_t int_vector_get_capacity(const IntVector *z)
{
    return z->capacity;
}

IntVector* new_vector(size_t initial_capacity) //создает новый массив
{   
    IntVector *z=malloc(sizeof(IntVector));
    if (z==NULL)
    {
        return -1;
    }
    z->ptr=malloc(initial_capacity*sizeof(int));
    if (z->ptr==NULL)
    {
        return -1;
    }
    z->capacity = initial_capacity;
    z->size=0;
    return z;
}

void int_vector_pop_back(IntVector* z) // удаляет последний элемент из массива
{
    if (z->capacity!=0 || z->size!=0)
    {
        z->ptr[z->size - 1] = 0;
        z->size--;      
    }
}

int int_vector_reserve(IntVector* z, size_t new_capacity) // изменяет емкость массива
{
    if (new_capacity<0)
    {
        return -1;
    }

    if (z->capacity == new_capacity) 
    {
        return 0;
    }
    int* array = realloc(z->ptr, (new_capacity * sizeof(int)));
    if (!array) 
    {
        return -1;
    }
    z->ptr = array;
    z->capacity = new_capacity;
    for (int i = z->size; i < z->capacity; i++) 
    {
        z->ptr[i] = 0;
    } 
    return 0;
}  

IntVector* int_vector_copy(const IntVector *z) //копирует массив 
{
    IntVector *a = new_vector(5);
    if (!a)
    {
        return -1;
    }
    int c=int_vector_reserve(a, z->capacity);
    check(c);
    a->ptr = memcpy(a->ptr, z->ptr, (sizeof(int)*(z->capacity)));
    if (!a->ptr || !a)
    {
    return -1;
    }
    a->size = z->size;
    a->capacity = z->capacity;
    return a;
}

int int_vector_shrink_to_fit(IntVector* z) //уменьшает массив до использованных эллементов 
{
 if (z->size==0)
 {
     vector_free(z);
     return 0;
 }
 int* array=realloc(z->ptr, (z->size * sizeof(int)));
 if (!array) 
 {
 return -1;
 }
 z->ptr = array;
 z->capacity = z->size;
 return 0;
}

int int_vector_resize(IntVector* z, int new_size)//изменить размер вектора
{
 if (new_size<0)
 {
     return -1;
 }
 
 if (z->size ==new_size)
 {
     return 0;
 }

 if (z->size < new_size)
    {
    int* array = realloc(z->ptr, (new_size * sizeof(int)));
        if (!array) 
        {
        return -1;
        }
    z->ptr =array;
    z->capacity = new_size;
        for (int i = z->size; i < z->capacity; i++)
        {
            z->ptr[i] = 0;
        }
        z->size = new_size;
    }
    if (z->size>new_size)
        {
        z->size=new_size; 
        }
 
 return 0;
}

int int_vector_set_item(IntVector *z, size_t index, int item)
{
    if (index<0 || z->capacity<index)
    {
        return -1;
    }

 if (!z->ptr[index])//Проверка, если эллемент пустой, то добавляем размер 
    { 
    if (index > z->size) 
        { 
        z->size = index + 1; 
        }
    }
    z->ptr[index] = item; 
    return 0;  
}

size_t int_vector_get_size(const IntVector *z)
{
    return z->size;
}

int vector_get_item(const IntVector *z, size_t a)
{
    if (a<0 || z->capacity < a)
    {
        return -1;
    }

    return z->ptr[a];
}