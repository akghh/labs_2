#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    Tree* root = NULL;
    int value;
    int min;
    int max;
    int choice = 0;

    while (1) {
    	printf("1. Добавить вершину\n");
        printf("2. Удалить вершину\n");
        printf("3. Распечатать дерево\n");
        printf("4. Проверить, находятся ли во всех листьях элементы со значениями в заданном диапазоне\n");
        printf("5. Завершить работу программы\n");

        printf("Введите номер команды: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Введите значение элемента: ");
        		scanf("%d", &value);
       	 	    root = insert_node(root, value);
                printf("Вершина добавлена\n");
                break;
            case 2:
                if (root == NULL) {
                    printf("Дерево и так пустое\n");
                    break;
                }
                printf("Введите значение элемента для удаления: ");
        	    scanf("%d", &value);
        	    root = remove_node(root, value);
                printf("Вершина удалена\n");
                break;
            case 3:
                if (root == NULL) {
                    printf("~Пустое дерево~\n");
                    break;
                }
    		    printf("\n\n");
    		    print_tree(root, 1);
    		    printf("\n\n");
                break;
            case 4:
                if (root == NULL) {
                    printf("Дерево пустое. Создайте дерево\n");
                    break;
                }
                printf("Введите границы диапазона: ");
        	    scanf("%d%d", &min, &max);
                if (is_leaf_in_range(root, min, max)) {
        		    printf("Да.\n");
    		    } else {
                    printf("Нет.\n");
    			      }
                break;
            case 5:
                free_tree(root);
                printf("Работа программы завершена\n");
    			return 0;
                break;
            default:
                printf("Ошибка: неправильный ввод. Попробуйте еще раз.\n");
                break;
        }
    }
    free_tree(root);
    
    return 0;
}
