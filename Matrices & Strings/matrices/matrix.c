#include <stdio.h>

void print_matrix(char s[], double m[], size_t rows, size_t cols)
{
    printf("%s = \n", s);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            printf("%4g ", m[i * cols + j]);
        }
        printf("\n");
    }
}

void transpose(double m[], size_t rows, size_t cols, double r[])
{
    for (size_t i = 0; i < cols; i++)
        for (size_t j = 0; j < rows; j++)
        {
            r[i * rows + j] = m[j * cols + i];
        }
}

void add(double m1[], double m2[], size_t rows, size_t cols, double r[])
{
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < cols; ++j)
        {
            r[i * cols + j] = m1[i * cols + j] + m2[i * cols + j];
        }
    print_matrix("add", r, rows, cols);
}

void mul(double m1[], double m2[], size_t r1, size_t c1, size_t c2, double r[])
{
    for (size_t i = 0; i < r1; i++)
    {
        for (size_t j = 0; j < c2; j++)
        {
            for (size_t k = 0; k < c1; k++)
            {
                r[i * c2 + j] += m1[i * c1 + k] * m2[k * c2 + j];
            }
        }
    }
}

struct matrix *matrix_mul(struct matrix *A, struct matrix *B)
{
    struct matrix *m = malloc(sizeof(struct matrix));
    m->lines = A->lines;
    m->cols = B->cols
    m->data = calloc(m->lines * m->cols, sizeof(int));
    for (int i = 0; i < m->lines; i++)
    {
        for (int j = 0; j < m->cols; j++)
        {
            int *cell = m->data + (i * m->cols + j;
            *cell = 0;
            for (int k = 0; k < A->cols; k++)
            {
                *cell += A->data[i * A->cols + k] * B->data[k * B->cols + j];
            }
        }
    }
    return m;
}

struct matrix *matrix_transpose(struct matrix *A)
{
    struct matrix *m = malloc(sizeof(struct matrix));
    m->lines = A->cols;
    m->cols = A->lines;
    m->data = calloc(A->cols * A->lines, sizeof(int));
    for (int i = 0; i < m->lines)
    {
        for (int j = 0; j < m->cols; j++)
        {
            m->data[i * m->cols + j] = A->data[j * A->cols + i];
        }
    }
    return m;
}
