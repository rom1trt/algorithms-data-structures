#include <err.h>
#include "vector.h"

struct vector *vector_new()
{
    struct vector *vector = (struct vector *)malloc(sizeof(struct vector));
    if (!vector)
        return NULL;

    vector->size = 0;
    vector->capacity = 1;

    vector->data = (int *)malloc(vector->capacity * sizeof(int));
    if (!vector->data)
    {
        vector_free(vector);
        return NULL;
    }

    return vector;
}

void vector_free(struct vector *v)
{
    if (v)
    {
        if (v->data)
            free(v->data);
        free(v);
    }
}

void double_capacity(struct vector *v)
{
    if (v->size > v->capacity)
    {
        errx(1, "Not enough memory!");
    }
    int **data = realloc(v->data, v->capacity * 2 * sizeof(int));
    v->capacity *= 2;

    if (v == NULL)
    {
        errx(1, "Not enough memory!");
    }

    if (data != v->data)
        v->data = data;
    data = NULL;
}

void vector_push(struct vector *v, int x)
{
    if (!v || !v->data)
        errx(1, "Not enough memory!");

    if (v->size == v->capacity)
    {
        double_capacity(v);
    }
    v->data[v->size++] = x;
}

int vector_pop(struct vector *v, int *x)
{
    if (!v || !v->data)
        return 0;

    v->data[v->size--];
    int k = 0;
    while (k < v->size)
    {
        k++;
    }
    x = v->data[k];
    return 1;
}

int vector_get(struct vector *v, size_t i, int *x)
{
    if (!v || i > v->capacity)
    {
        return 0;
    }

    size_t k = 0;
    while (k < i)
    {
        k++;
    }
    *x = v->data[k];
    return 0;
}

void vector_insert(struct vector *v, size_t i, int x)
{
    if (!v || !v->data)
        errx(1, "Not enough memory!");

    if (i < 0 || i > v->size)
        errx(1, "Not enough memory!");

    if (i == v->size)
    {
        vector_push(v, i);
    }
    else
    {
        if (v->size == v->capacity)
        {
            double_capacity(v);
        }

        for (size_t k = v->size; k > i; k--)
            v->data[k] = v->data[k - 1];

        v->data[i] = x;
        v->size++;
    }
}

int vector_remove(struct vector *v, size_t i, int *x)
{
    if (!v || !v->data)
        return 0;

    if (i < 0 || i > v->size)
        return 0;

    if (i == v->size)
    {
        int *p = NULL;
        vector_pop(v, p);
    }
    else
    {
        size_t k = 0;
        while (k < i)
        {
            k++;
        }
        *x = v->data[k];
        while (k < v->size - 1)
        {

            v->data[k] = v->data[k + 1];
            k++;
        }
        v->size--;
    }
    return 1;
}