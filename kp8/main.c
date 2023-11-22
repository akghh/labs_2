#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    List* list = create_list();
    int choice;

    while (1) {
        printf("1.Добавить элемент\n");
        printf("2.Удалить элемент\n");
        printf("3.Распечатать список\n");
        printf("4.Узнать размер списка\n");
        printf("5.Удалить из списка элементы со значениями в заднном диапазоне\n");
        printf("6. Завершить работу программы\n");

        printf("Введите номер команды: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                uint64_t value;
                printf("Введите значение элемента: ");
                scanf("%lu", &value);
                push_node(list, value);
                printf("Элемент добавлен\n\n");
                break;
            case 2:
                if (list->head == NULL) {
                    printf("Список пустой\n\n");
                } else {
                    pop_node(list);
                    printf("Элемент удален\n\n");
                }
                break;
            case 3:
                if (list->head == NULL) {
                    printf("Список пустой\n\n");
                } else {
                    print_list(list);
                    printf("\n");
                }
                break;
            case 4:
                int size;
                size = size_of_list(list);
                printf("Размер списка: %d\n\n", size);
                break;
            case 5:
                if (list->head == NULL) {
                    printf("Список пустой\n\n");
                } else {
                    uint64_t lower;
                    uint64_t upper;
                    printf("Введите нижнюю границу диапазона: ");
                    scanf("%lu", &lower);
            		printf("Введите верхнюю границу диапазона: ");
            		scanf("%lu", &upper);
            		remove_range(list, lower, upper);
                    printf("Все подходящие элементы удалены\n\n");
                }
                break;
            case 6:
                destroy_list(list);
		        printf("Работа программы завершена\n");
    		    return 0;
                break;
            default:
                printf("Ошибка: неправильный ввод. Попробуйте еще раз\n\n");
                break;
        }
	}
    return 0;
}
