#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int value;
    struct NODE *next;
};

int search(int target, struct NODE *h){
    int cnt = 0;
    struct NODE *nowNode = h;

    while (nowNode != NULL)
    {
        if(target == nowNode->value){
            printf("%d: %d\n",cnt,nowNode->value);
            return 1;
        }
        else{
            nowNode = nowNode->next;
            cnt++;
        }
    }
    return 0;
    
}

int main() {
    int SIZE_OF_NODE = sizeof(struct NODE);
    struct NODE *head = malloc(SIZE_OF_NODE);
    struct NODE *node1 = malloc(SIZE_OF_NODE);
    struct NODE *node2 = malloc(SIZE_OF_NODE);

    head->next = node1;
    head->value = 33;
    node1->next = node2;
    node1->value = 20;
    node2->next = NULL;
    node2->value = 50;

    int target;
    scanf("%d",&target);
    if(search(target,head)){
        printf("the target is in the linked list\n");
    }
    else{
        printf("the target is not in the linked list\n");
    }
    return 0;
}
