#include <stdio.h>
#include <stdlib.h>

struct QUEUE
{
    struct NODE *node;
};


struct NODE
{
    int value;
    struct NODE *next;
};

void enqueue(int data, struct QUEUE *q) {
    struct NODE *tmp = malloc(sizeof(struct NODE));
    tmp->value = data;
    tmp->next = q->node;
    q->node = tmp;
}


int dequeue(struct QUEUE *q){
    if(q->node != NULL){
        int result;
        if(q->node->next == NULL){
            result = q->node->value;
            free(q->node);
            q->node = NULL;
            return result;
        }
        struct NODE *tmp = q->node;
        struct NODE *tmp2;
        while (tmp->next != NULL)
        {
            if(tmp->next->next == NULL){
                tmp2 = tmp;
            }
            tmp = tmp->next;

        }
        result = tmp->value;
        free(tmp);
        tmp2->next = NULL;
        return result;
    }
    else{
        printf("There is no data to dequeue!\n");
    }
}

void prt_queue(struct QUEUE *q){
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
        printf("The queue is empty\n");
    }
}

int main() {

    struct QUEUE *datas = malloc(sizeof(struct QUEUE));
    datas->node = NULL;

    enqueue(10,datas);
    prt_queue(datas);
    enqueue(20,datas);
    enqueue(30,datas);
    enqueue(40,datas);
    prt_queue(datas);
    printf("%d\n",dequeue(datas));
    prt_queue(datas);
    dequeue(datas);
    prt_queue(datas);
    dequeue(datas);
    prt_queue(datas);
    dequeue(datas);
    prt_queue(datas);
    dequeue(datas);

    return 0;
}
