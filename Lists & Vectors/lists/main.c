#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void print_list(struct list *list)
{
    printf("list_is_empty() = %s\n", list_is_empty(list) ? "yes" : "no");
    printf("list_is_sorted() = %s\n", list_is_sorted(list) ? "yes" : "no");
    printf("list_len() = %zu\n", list_len(list));

    int line = 1;

    printf("[");
    if (list->next)
    {
        goto pastfst;
        while (list->next)
        {
            line += printf(";");

            if (line > 72)
            {
                printf("\n ");
                line = 1;
            }

        pastfst:
            line += printf(" %2d", list->next->data);
            list = list->next;
        }
    }

    printf(" ]\n");
}

void list_insert_sort(struct list *list)
{
    if (list_is_empty(list))
        return;

    struct list fake_head = {0, 0};

    while (!list_is_empty(list))
    {
        struct list *elm = list_pop_front(list);
        list_insert(&fake_head, elm);
    }

    list->next = fake_head.next;
}

int main()
{
    struct list *emptylist = malloc(sizeof(struct list));
    list_init(emptylist);

    for (size_t i = 0; i < 5; i++)
    {
        struct list *j = malloc(sizeof(struct list));
        list_init(j);
        j->data = i;
        j->next = NULL;
        list_push_front(emptylist, j);
    }
    list_insert_sort(emptylist);
    struct list *j2 = malloc(sizeof(struct list));
    list_init(j2);
    j2->data = 3;
    j2->next = NULL;
    list_push_front(emptylist, j2);
    list_pop_front(emptylist);
    list_rev(emptylist);
    print_list(emptylist);

    return 0;
}