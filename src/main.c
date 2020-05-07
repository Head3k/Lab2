#include <stdio.h>
#include "IntVector.h"
#include <stdlib.h>
#include <string.h>

int main()
{
    int count, index, item, v, last, count1, index1;
	size_t initial_capacity=16;
    IntVector *z = new_vector(initial_capacity);
    
    printf("Сколько символов добавить в массив 'z'? ");
    scanf("%d", &count);
    int b=int_vector_reserve(z,count);
    check(b);
    
    printf("Введите индекс массива 'z' и чему он будет равен  ");
    scanf("%d %d", &index, &item);
    int a123=int_vector_set_item(z, index, item);
    check(a123);
    printarray(z);

    printf("Какой эллемент добавить в конец массива 'z'?  ");
    scanf("%d",&last);
    int q=vector_push_back(z, last);
    printarray(z);
    check(q);
    
    printf("Уменьшаем емкость массива 'z' до его размера\n");
    int_vector_shrink_to_fit(z);
    printf("z->capacity=%d z->size=%d\n", z->capacity ,z->size);
    printf("\n");

    printf("Введите индекс элемента 'z', который хотите узнать  ");
    scanf("%d", &index1);
    int getitem=vector_get_item(z, index1);
    printf("Элемент под индексом %d=%d\n",index1, getitem);

    printf("Удаляем последний элемент из массива 'z'\n");
    int_vector_pop_back(z);
    printf("\n");
    printarray(z);
    
    int c=int_vector_get_capacity(z);
    printf("Вместимость массива 'z' равна  %d\n", c);
    
    printf("\n");
    printf("Новый скопированный массив d\n");
    IntVector *d=int_vector_copy(z);
    printarray(d);
    printf("Сколько символов добавить в массив 'd'? ");
    scanf("%d", &count1);
    int b1=int_vector_reserve(d,count1);
    check(b1);
    printarray(d);

    printf("На сколько изменить размер 'z' вектора?  ");
    scanf("%d", &v);
    int a12=int_vector_resize(z, v);
    check(a12);
    printarray(z);
    int size=int_vector_get_size(z);
    printf("Размер вектора 'z' равен %d\n", size);
    printf("z->capacity=%d z->size=%d\n", z->capacity ,z->size);
    
    printf("Уменьшаем емкость массива 'z' до его размера\n");
    int_vector_shrink_to_fit(z);
    printf("z->capacity=%d z->size=%d\n", z->capacity ,z->size);
    printf("\n");

    vector_free(d);
    printf("Вектор d очищен\n");
    vector_free(z);
    printf("Вектор z очищен\n");

    return 0;
}