#include <stdlib.h>
#include "list.h"

struct list sentinel = {NULL, 0};
struct list *list = &sentinel;

void list_init(struct list *list)
{
    *list = sentinel;
}

int list_is_empty(struct list *list)
{
    if (list->next == NULL)
        return 1;
    return 0;
}

size_t list_len(struct list *list)
{
    size_t res = 0;
    struct list *p;
    p = list;
    while (p->next != NULL)
    {
        res++;
        p = p->next;
    }
    return res;
}

void list_push_front(struct list *list, struct list *elm)
{
    struct list *p = list->next;
    list->next = elm;
    elm->next = p;
}

struct list *list_pop_front(struct list *list)
{
    if (list_is_empty(list))
        return NULL;

    struct list *p = list->next;
    list->next = list->next->next;
    p->next = NULL;
    return p;
}

struct list *list_find(struct list *list, int value)
{
    struct list *p;
    p = list;
    while (p->next != NULL)
    {
        p = p->next;
        if (p->data == value)
        {
            return p;
        }
    }
    return NULL;
}

struct list *list_lower_bound(struct list *list, int value)
{
    struct list *p = list;
    struct list *n = list->next;

    while (n != NULL)
    {
        if (n->data > value)
        {
            return p;
        }
        p = n;
        n = n->next;
    }
    return p;
}

int list_is_sorted(struct list *list)
{
    if (list_len(list) < 2)
        return 1;

    struct list *p = list->next;
    struct list *n = list->next->next;

    while (n != NULL)
    {
        if (n->data < p->data)
        {
            return 0;
        }

        p = n;
        n = n->next;
    }
    return 1;
}

void link(struct list *b, struct list *elm, struct list *n)
{
    b->next = elm;
    elm->next = n;
}

void list_insert(struct list *list, struct list *elm)
{
    if (list_is_empty(list))
    {
        list_push_front(list, elm);
    }

    struct list *b = list_lower_bound(list, elm->data);
    link(b, elm, b->next);
}

void list_rev(struct list *list)
{
    struct list new = {NULL, 0};
    list_init(&new);

    while (!list_is_empty(list))
    {
        list_push_front(&new, list_pop_front(list));
    }
    list->next = new.next;
}

void list_half_split(struct list *list, struct list *second)
{
    list_rev(list);

    for (size_t i = 0; i < list_len(list); i++)
    {
        list_push_front(second, list_pop_front(list));
    }
    list_rev(list);
}