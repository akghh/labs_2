#include "tree.h"
#include <ctype.h>

int main(){
    
    queue* q = new_queue();
    stack* st = new_stack();
    Node* node = create_node(BRACKET, -1);
    node->data.is_left_bracket = true;
    Node* prev_node = create_node(BRACKET, -1);
    prev_node->data.is_left_bracket = false;
    char symb;
    printf("Введите выражение:\n");
    scanf("%c", &symb);
    
    while (symb != '\n'){
        printf("Считал символ %c\n", symb);
        if (isdigit(symb)) {
            prev_node = node;
            node = create_node(NUMBER, -1);
            if (prev_node->type == NUMBER) {
                node->data.value_int = prev_node->data.value_int * 10 + (symb - '0');
            } else {
                node->data.value_int = symb - '0';
            }
            push_queue(q, node);
            
        } else if (isalpha(symb)) {
            prev_node = node;
            node = create_node(VARIABLE, -1);
            node->data.variable = symb;
            push_queue(q, node);
            //printf("aaaæâaaaā\n");
            
        } else {
            switch(symb) {
                case '(':
                    prev_node = node;
                    node = create_node(BRACKET, -1);
                    node->data.is_left_bracket = true;
                    push_stack(st, node);
                    break;
                case ')':
                    prev_node = node;
                    node = create_node(BRACKET, -1);
                    node->data.is_left_bracket = false;
                    from_st_to_q(st, q, node);
                    break;
                case '-':
                    /*prev_node = node;
                    node = create_node(OPERATOR, 1);
                    node->data.operation = '-';
                    from_st_to_q(st, q, node);
                    */
                    if (!(prev_node->type == NUMBER || prev_node->type == VARIABLE || (prev_node->type == BRACKET && prev_node->data.is_left_bracket == false))){
                        printf("Обычный минус\n");
                        prev_node = node;
                        node = create_node(OPERATOR, 1);
                        node->data.operation = '-';
                        from_st_to_q(st, q, node);
                    } else {
                        printf("Унитарный минус\n");
                        node = create_node(NUMBER, -1);
                        node->data.value_int = -1;
                        push_queue(q, node);
                        node = create_node(OPERATOR, 2);
                        node->data.operation = '*';
                        push_stack(st, node);
                    }
                    break;
                case '+':
                    //printf("ooóòoooœœ\n");
                    prev_node = node;
                    node = create_node(OPERATOR, 1);
                    node->data.operation = '+';
                    from_st_to_q(st, q, node);
                    break;
                case '*':
                    //printf("eēeeéëęęęe\n");
                    prev_node = node;
                    node = create_node(OPERATOR, 2);
                    node->data.operation = '*';
                    from_st_to_q(st, q, node);
                    break;
                case '/':
                    prev_node = node;
                    node = create_node(OPERATOR, 3);
                    node->data.operation = '/';
                    from_st_to_q(st, q, node);
                    break;
                case '^':
                    prev_node = node;
                    node = create_node(OPERATOR, 4);
                    node->data.operation = '^';
                    from_st_to_q(st, q, node);
                    break;
            }
        }
        scanf("%c", &symb);
    }
    
    printf("Перемещаем в очередь оставшееся на стеке\n");
    //from_st_to_q(st, q, st->head);
    Node* last_node = create_node(BRACKET, -1);
    last_node->data.is_left_bracket = false;
    from_st_to_q(st, q, last_node);
    //while (st->head != NULL) {
    //    from_st_to_q(st, q, st->head);
    //} 
    //reverse_queue(q);
    //printf("Выражение в постфиксной форме:\n");
    //print_queue(q);

    tree* main_tree = new_tree();
    main_tree = create_tree(q);
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("Дерево исходного выражения:\n\n");
    print_tree(main_tree->root, 1);
    printf("\n\n");
    remove_zeroes(main_tree->root);
    printf("Преобразованное выражение:\n");
    print_inf(main_tree->root);
    //print_infix(main_tree);
    printf("\n");
    printf("Дерево преобразованного выражения:\n\n");
    print_tree(main_tree->root, 1);
    free_tree(main_tree);
    return 0;
}
