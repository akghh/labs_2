#include "tree.h"

stack* new_stack() {
    stack* result = (stack*)malloc(sizeof(stack));
    result->head = NULL;
    return result;
}

queue* new_queue() {
    queue* result = (queue*)malloc(sizeof(queue));
    result->front = NULL;
    result->rear = NULL;
    return result;
}

tree* new_tree() {
    tree* result = (tree*)malloc(sizeof(tree));
    result->root = NULL;
    return result;
}

Node* create_node(Type type, int rang) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->type = type;
    n->rang = rang;
    n->l = NULL;
    n->r = NULL;
    return n;
}


////////////////////////////////////////////////

void push_stack(stack* n, Node* a) {
    if (n->head == NULL){
        printf("В стек добавлен первый элемент\n");
        n->head = a;
        return;
    }
    a->r = n->head;
    n->head = a;
    printf("В стек добавлен элемент\n");
}

void push_queue(queue* q, Node* a) {
    if (q->rear == NULL) {
        printf("В очередь добавлен первый элемент\n");
        q->rear = q->front = a;
        return;
    }
    printf("В очередь добавлен элемент\n");
    a->r = q->front;
    q->front = a;
}

Node* pop_stack(stack* n) {
    Node* t = n->head;
    if (n->head == NULL)
        return NULL;
    if (n->head->l == NULL) {
        n->head = NULL;
        t->l = NULL;
        t->r = NULL;
        return t;
    }
    n->head = t->l;
    t->l = NULL;
    t->r = NULL;
    return t;
}

Node* pop_queue(queue* q) {
    if (q->front == NULL)
        return NULL;

    Node* t = q->front;

    if (q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = q->front->r;
    }

    t->l = NULL;
    t->r = NULL;
    return t;
}

void reverse_queue(queue* q) {
    Node* prev = NULL;
    Node* current = q->front;
    Node* temp;

    while (current != NULL) {
        temp = current->r;
        current->r = prev;
        prev = current;
        current = temp;
    }

    temp = q->front;
    q->front = q->rear;
    q->rear = temp;
}

void print_queue(queue* q) {
    if(q->front == NULL) {
        printf("Empty queue!\n");
    }
    else {
        Node* temp = q->front;
        while(temp != NULL) {
            switch(temp->type) {
                case OPERATOR:
                    printf("%c", temp->data.operation);
                    break;
                case NUMBER:
                    printf("%d", temp->data.value_int);
                    break;
                case VARIABLE:
                    printf("%c", temp->data.variable);
                    break;
                case BRACKET:
                    printf("%s", temp->data.is_left_bracket ? "(" : ")");
                    break;
            }
            temp = temp->r;
        }
    }
    printf("\n");
}

////////////////////////////////////////////////////////

void from_st_to_q(stack* st, queue* q, Node* n) {
    if (n->type == BRACKET) {
        if (n->data.is_left_bracket) {
            push_stack(st, n);
        } else {
            Node* tmp = pop_stack(st);
            while (tmp != NULL && (tmp->type != BRACKET || !tmp->data.is_left_bracket)) {
                printf("Переместили %c в очередь\n", tmp->data.operation);
                push_queue(q, tmp);
                tmp = pop_stack(st);
            }
            free(tmp);

        }
    }
    else if (n->type == OPERATOR) {
        Node* tmp = pop_stack(st);
        while (tmp != NULL && tmp->rang <= n->rang) {
            printf("Переместили %c в очередь\n", tmp->data.operation);
            push_queue(q, tmp);
            tmp = pop_stack(st);
        }
        if (tmp != NULL) {
            push_stack(st, tmp);
        }
        push_stack(st, n);
    } else {
        if (n->type == NUMBER)
            printf("Переместили %d в очередь\n", n->data.value_int);
        else printf("Переместили %c в очередь\n", n->data.variable);
        push_queue(q, n);
    }
}


Node* add_to_tree(Node* n, queue* q) {
    if (n == NULL) {
        return NULL;
    }
    if (n->type == NUMBER || n->type == VARIABLE) {
        return n;
    }
    Node* temp = n;
    temp->r = add_to_tree(pop_queue(q), q);
    temp->l = add_to_tree(pop_queue(q), q);
    return temp;
}

tree* create_tree(queue* q) {
    queue* reverse_q = new_queue();
    Node* stack[100];
    int top = -1;
    while (q->front != NULL) {
        top++;
        stack[top] = pop_queue(q);
    }
    while (top >= 0) {
        push_queue(reverse_q, stack[top]);
        top--;
    }
    tree* t = (tree*)malloc(sizeof(tree));
    t->root = pop_queue(reverse_q);
    t->root->r = add_to_tree(pop_queue(reverse_q), reverse_q);
    t->root->l = add_to_tree(pop_queue(reverse_q), reverse_q);
    free(reverse_q);
    return t;
}

void print_tree(Node* root, int n) {
    if (root == NULL) {
        return;
    }
    //int n = 1;
    print_tree(root->r, n + 1);
    for (int i = 1; i < n; i++) printf("\t");
    if (root->type == OPERATOR) {
        switch(root->data.operation) {
            case '-':
                printf("-");
                break;
            case '+':
                printf("+");
                break;
            case '*':
                printf("*");
                break;
            case '/':
                printf("/");
                break;
            default:
                printf("^");
                break;
        }
    } else if (root->type == VARIABLE) {
        printf ("%c",root->data.variable);
    } else if (root->type == NUMBER) {
        printf ("%d",root->data.value_int);
    }
    printf("\n");
    print_tree(root->l, n + 1);
}

void remove_zeroes(Node* node) {
    if (node == NULL) {
        return;
    }
    remove_zeroes(node->l);
    remove_zeroes(node->r);
    if (node->type == OPERATOR && node->data.operation == '+') {
        if (node->l != NULL && node->l->type == NUMBER && node->l->data.value_int == 0) {
            Node* new_node = node->r;
            new_node->rang = node->rang;
            *node = *new_node;
        } else if (node->r != NULL && node->r->type == NUMBER && node->r->data.value_int == 0) {
            Node* new_node = node->l;
            new_node->rang = node->rang;
            *node = *new_node;
        }
    } else if (node->type == OPERATOR && node->data.operation == '-' && node->r != NULL && node->r->type == NUMBER && node->r->data.value_int == 0) {
        Node* new_node = node->l;
        new_node->rang = node->rang;
        *node = *new_node;
    }
}

void print_inf(Node* n) {
    if (n == NULL) {
        return;
    }

    if (n->type == OPERATOR) {
        printf("(");
    }

    print_inf(n->l);

    switch(n->type) {
        case NUMBER:
            printf("%d", n->data.value_int);
            break;
        case VARIABLE:
            printf("%c", n->data.variable);
            break;
        case OPERATOR:
            printf("%c", n->data.operation);
            break;
        case BRACKET:
            if (n->data.is_left_bracket) {
                printf("(");
            } else {
                printf(")");
            }
            break;
    }

    print_inf(n->r);

    if (n->type == OPERATOR) {
        printf(")");
    }
}

void print_tree_new(tree* t) {
    print_inf(t->root);
    printf("\n");
}


/////////////////////////////////////////////

void free_node(Node* n) {
    if (n->l != NULL)
        free_node(n->l);
    if (n->r != NULL)
        free_node(n->r);
    free(n);
}

void free_tree(tree* t) {
    free_node(t->root);
    t->root = NULL;
}
