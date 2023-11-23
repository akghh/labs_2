#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "table.h"

int main() {
    Node node;
    int N = 7;
    int i = 0;
    List* list = create_list();
    list->value = (Node*) malloc(sizeof(Node) * N);
    
    FILE *keys_file = fopen("keys.txt", "r");
    FILE *strings_file = fopen("strings.txt", "r");

    if (keys_file == NULL || strings_file == NULL) {
        printf("Не удалось открыть файл\n");
        return 0;
    }

    while (i < N && !feof(keys_file) && !feof(strings_file)) {
        i++;
        int key;
        char string[STRSIZE];

        fscanf(keys_file, "%d", &key);
        fgets(string, STRSIZE, strings_file);

        list->value[list->size].key = key;
        strcpy(list->value[list->size].string, string);

        list->size++;
        list->value = (Node*)realloc(list->value, (list->size + 1) * sizeof(Node));
    }

    fclose(keys_file);
    fclose(strings_file);
    
    int choice;

    while (1) {
    	printf("1. Напечатать таблицу\n");
    	printf("2. Перемешать строки\n");
    	printf("3. Перевернуть таблицу\n");
        printf("4. Отсортировать таблицу\n");
        printf("5. Найти значение по ключу\n");
        printf("6. Завершить работу программы\n");

        printf("Введите номер команды: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_table(list);
                break;
            case 2:
                scramble_table(list);
                printf("Строки перемешаны\n");
                break;
            case 3:
                reverse_table(list);
                printf("Таблица перевернута\n");
                break;
            case 4:
                sort_table(list);
                printf("Таблица отсортирована\n");
                break;
            case 5:
                printf("Введите ключ: ");
                int i;
				scanf("%d", &node.key);
				i = bin_search(list, node);
				if (i > -1)
					printf("Найдена строка: %s\n", list->value[i].string);
				else
					printf("Строка с таким ключом не найдена. Отсортируйте таблицу\n");
                break;
            case 6:
                remove_table(list);
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
