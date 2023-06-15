#include <stdio.h>
#include <stdlib.h>

struct STACK
{
    struct NODE *node;
};


struct NODE
{
    int value;
    struct NODE *next;
};

void push(int data, struct STACK *q) {
    struct NODE *tmp = malloc(sizeof(struct NODE));
    tmp->value = data;
    tmp->next = q->node;
    q->node = tmp;
}


int pop(struct STACK *q){
    if(q->node != NULL){
        int result = q->node->value;
        if(q->node->next == NULL){
            free(q->node);
            q->node = NULL;
            return result;
        }
        struct NODE *tmp = q->node;
        q->node = tmp->next;
        free(tmp);
        return result;
    }
    else{
        printf("There is no data to POP!\n");
        return -1;
    }
}

void prt_stack(struct STACK *q){
    if(q->node != NULL){
        struct NODE *tmp = q->node;
        printf("----------------\n");
        while (tmp != NULL)
        {
            printf("%d\n",tmp->value);
            tmp = tmp->next;
        }
        printf("----------------\n");
    }
    else{
        printf("The stack is empty\n");
    }
}

int main() {

    struct STACK *datas = malloc(sizeof(struct STACK));
    datas->node = NULL;

    push(10,datas);
    prt_stack(datas);
    push(20,datas);
    push(30,datas);
    push(40,datas);
    prt_stack(datas);
    printf("%d\n",pop(datas));
    prt_stack(datas);
    pop(datas);
    prt_stack(datas);
    pop(datas);
    prt_stack(datas);
    pop(datas);
    prt_stack(datas);
    pop(datas);

    return 0;
}
