#include "queue.h"

#include <stdio.h>
#include <math.h>

//Проверка на пустоту
int is_queue_empty(Queue* q) {
    return (q->size == 0);
} 

//Функция создания очереди
Queue* create_queue() {
    Queue* result = (Queue*)malloc(sizeof(Queue));
    result->rear = result->front =  NULL;
    result->size = 0;
    return result;
}

//Функция удаления очереди
void destroy_queue(Queue *q) {
    while (!is_queue_empty(q)) {
        pop_node(q);
    }
    free(q);
}

// Функция для добавления элемента в очередь
void push_node(Queue* q, int value)
{
    QueueNode* qn = (QueueNode*)malloc(sizeof(QueueNode));
    qn->next = NULL;
    qn->value = value;
    if (q->rear == NULL)
    {
       q->front = q->rear = qn;
    } else {
        q->rear->next = qn;
        q->rear = qn;
    }
    q->size++;
}

//Функция для удаления элеменат (+возвращает его значение)
int pop_node(Queue* q) {
    int result = q->front->value;
    q->front = q->front->next;
    q->size--;
    return result;
}

//Функция вывода очереди
void print_queue(Queue* q){
    QueueNode* prev = q->front;
    while (prev != NULL) {
        printf("%d ", prev->value);
        prev = prev->next;
    }
    printf("\n");
	
}

//Размер очереди
int queue_size(Queue* q)
{
    return q->size;
}

//Функция поиска и удаления минимального элемента в очереди
//Возвращает значение минимального элемента
int find_and_remove_min(Queue* q) {
    QueueNode *temp = q->front, *prev = NULL;
    int min = temp->value;

    // Пройдемся по очереди и найдем минимальный элемент
    while (temp != NULL) {
        if (temp->value < min) min = temp->value;
        temp = temp->next;
    }

    // Снова пройдемся по очереди и удалим минимальный элемент
    temp = q->front;
    while (temp != NULL) {
        if (temp->value == min) {
            // Если это первый элемент
            if (temp == q->front) {
                q->front = q->front->next;
                free(temp);
                break;
            } else {
                QueueNode *nextNode = temp->next;
                prev->next = nextNode;
                free(temp);
                break;
            }
        }
        prev = temp;
        temp = temp->next;
    }
    // Уменьшим размер очереди на 1, так как удалили элемент
    q->size--;
    return min;
}

//Функция сортировки очереди линейным выбором
Queue* sort_queue(Queue* q) {
    int size = queue_size(q);

    Queue* sorted_q = create_queue();
    
    printf("Изначальная очередь\n");
    print_queue(q);
    
    for (int i = 0; i < size; i++){
	  //Находим и удаляем минимальный элемент из исходной очереди 
	  //Вставляем его в начало отсортированной очереди
        int min = find_and_remove_min(q);
        push_node(sorted_q, min);
    }
    
    printf("Отсортированная очередь\n");
    print_queue(sorted_q);
    
    return sorted_q;
}
