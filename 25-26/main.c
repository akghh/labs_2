#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {
    Queue* q_main = create_queue();
    int choice;
    while (1) {
    	printf("1. Добавить элемент\n");
        printf("2. Удалить элемент\n");
        printf("3. Распечатать очередь\n");
        printf("4. Отсортировать очередь\n");
	    printf("5. Найти и удалить минимальный элемент\n");
        printf("6. Завершить работу программы\n");

        printf("Введите номер команды: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Введите значение элемента: ");
                int x;
                scanf("%d", &x);
        		push_node(q_main, x);
		        printf("Элемент добавлен\n");
                break;
            case 2:
                if (!is_queue_empty(q_main)) {
        	        pop_node(q_main);
        	        printf("Элемент удален\n");
                } else {
                    printf("Очередь пустая. Нечего удалять\n");
                }
                break;
            case 3:
                if (!is_queue_empty(q_main)) {
        	        print_queue(q_main);
               	    printf("\n");
                } else {
                    printf("*пустая очередь*\n");
                }
                break;
            case 4:
                if (!is_queue_empty(q_main)) {
        	        q_main = sort_queue(q_main);
                } else {
                    printf("Очередь пустая. Нечего сортировать\n");
                }
                break;
            case 5:
                if (!is_queue_empty(q_main)) {
        	        int min_elem = find_and_remove_min(q_main);
                    printf("Удалён элемент со значением %d\n", min_elem);
                } else {
                    printf("Очередь пустая. Минимального нет\n");
                }
                break;
            case 6:
                destroy_queue(q_main);
		        printf("Работа программы завершена\n");
    		    return 0;
                break;
            default:
                printf("Ошибка: неправильный ввод. Попробуйте еще раз.\n");
                break;
        }
	}
    return 0;
}
