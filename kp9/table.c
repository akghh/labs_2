#include "table.h"

List* create_list () {
    List *list = (List*)malloc(sizeof(list));
    list->value = NULL;
    list->size = 0;
    return list;
}

void print_table(List *list) {
    int i;
    for (i = 0; i < list->size; i++) {
        printf("%d: %s\n", list->value[i].key, list->value[i].string);
    }
}

void swap_nodes(List *list, int a, int b)
{
    if (a >= list->size || b >= list->size) {
        printf("Ыгх.\n");
        return;
    }

    Node tmpNode;

    tmpNode = list->value[a];
    list->value[a] = list->value[b];
    list->value[b] = tmpNode;
}

int is_sorted(List *list)
{
    int i;

    for (i = 0; i < list->size - 1; i++)
        if (list->value[i].key > list->value[i + 1].key)
            return 0;

    return 1;
}

void reverse_table(List *list)
{
    int i, j;
    for (i = 0, j = list->size - 1; i < j; i++, j--)
        swap_nodes(list, i, j);
}


void scramble_table(List *list)
{
    int i, j, z;
    srand((unsigned int)time(0));

    for (z = 0; z < list->size; z++)
    {
        i = rand() % list->size;
        j = rand() % list->size;

        swap_nodes(list, i, j);
    }
}

void sort_table(List *list) {
    int i, j, size = list->size;
    int count[size];
    Node b[size];

    for (i = 0; i < size; i++)
        count[i] = 0;

    for (i = 0; i < size - 1; i++)
        for (j = i + 1; j < size; j++)
            if (list->value[i].key <= list->value[j].key)
                count[j]++;
            else
                count[i]++;

    for (i = 0; i < size; i++)
        b[count[i]] = list->value[i];

    for (i = 0; i < size; i++)
        list->value[i] = b[i];
}

int bin_search(List* list, Node node)
{
    int start = 0, end = list->size - 1, mid;

    if (list->size <= 0)
        return -1;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (list->value[mid].key == node.key)
            return mid;
        else if (list->value[mid].key > node.key)
            end = mid - 1;
        else
            start = mid + 1;
    }
    
    return -1;
}

void remove_table(List* list) {
    if(list != NULL) {
        free(list->value);
        free(list);
    }
}
