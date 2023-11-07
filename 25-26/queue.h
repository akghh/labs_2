#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <stdlib.h>

typedef struct queueNode {
    int value;
    struct queueNode *next;
} QueueNode;

typedef struct queue {
    QueueNode* rear;
    QueueNode* front;
    int size;
} Queue;

int is_queue_empty(Queue *q);
Queue* create_queue();
void destroy_queue(Queue *q);
void push_node(Queue* q, int value);
int pop_node(Queue *q);
void print_queue(Queue* q);
int queue_size(Queue* q);
int find_and_remove_min(Queue* q);
Queue* sort_queue(Queue* q);
#endif
