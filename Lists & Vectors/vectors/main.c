#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

void vector_int_print(struct vector *vector);

int main()
{
    int i;
    struct vector *vector = vector_new();
    if (!vector)
    {
        fprintf(stderr, "Cannot allocate vector.\n");
        exit(EXIT_FAILURE);
    }

    int even[3] = {2, 4, 6};
    for (i = 0; i < 3; i++)
        vector_push(vector, even[i]);
    vector_int_print(vector); /* [ 2 4 6 ] */

    printf("%zu \n", (vector->capacity)); // 4
    double_capacity(vector);
    printf("%zu \n", (vector->capacity)); // 8

    int *p = NULL;
    vector_pop(vector, p);
    vector_int_print(vector); /* [ 2 4 ] */

    int odd[2] = {1, 3};
    vector_insert(vector, 0, odd[0]);
    vector_insert(vector, 2, odd[1]);
    vector_int_print(vector); /* [ 1 2 3 4 ] */

    int x = 3;
    vector_remove(vector, 1, &x);
    vector_int_print(vector); /* [ 1 3 4 ] */

    vector_free(vector);

    return 0;
}

void vector_int_print(struct vector *vector)
{
    printf("[ ");
    for (size_t i = 0; i < vector->size; i++)
        printf("%d ", vector->data[i]);
    printf("]\n");
}
