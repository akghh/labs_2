#include "list.h"

List* create_list() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    return list;
}


void push_node(List* list, uint64_t data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;

    if (list->head == NULL) {
        list->head = node;
        list->head->next = list->head;
        push_node(list, data);
    } else {
        Node* current = list->head;
        while (current->next != list->head) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
}


void pop_node(List* list) {
    if (list->head->next == list->head) {
        free(list->head);
        list->head = NULL;
        return;
    }

    Node* current = list->head;
    while (current->next->next != list->head) {
        current = current->next;
    }

    Node* temp = current->next;
    current->next = list->head;
    free(temp);
}

void print_list(List* list) {
    Node* current = list->head->next;
    while (current != list->head) {
        uint64_t value = current->data;
        printf("%lu\t", value);
        current = current->next;
    }
    printf("\n");
}

int size_of_list(List* list) {
    if (list->head == NULL) {
        return 0;
    }

    int size = 0;
    Node* current = list->head->next;
    while (current != list->head) {
        size++;
        current = current->next;
    }

    return size;
}

void remove_range(List* list, uint64_t lower, uint64_t upper) {
    Node* current = list->head;
    Node* prev = NULL;
    
    int list_size = size_of_list(list);
    int count = 1;
    
    for (int i = 0; i <= list_size; i++) {
        if (current->data >= lower && current->data <= upper) {
            if (count == list_size) {
                list->head = NULL;
            } else { 
                Node* temp = current;
                current = current->next;
                if (prev == NULL) {
                    list->head = current;
                } else {
                    prev->next = current;
                }
                free(temp);
                count++;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}


void destroy_list(List* list) {
    if (list->head == NULL) {
        return;
    }

    Node* current = list->head->next;
    while (current != list->head) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    free(list->head);
    list->head = NULL;
}
