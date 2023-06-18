#include <stdio.h>
#include <stdlib.h>

struct NODE{
    int value;
    struct NODE *leftNode;
    struct NODE *rightNode;
};

struct TREE
{
    struct NODE *root_node;
};

void inorderTraverse(struct NODE *n){
    if(n != NULL){
        inorderTraverse(n->leftNode);
        printf("%d\n",n->value);
        inorderTraverse(n->rightNode);
    }
}
void preorderTraverse(struct NODE *n){
    if(n != NULL){
        printf("%d\n",n->value);
        preorderTraverse(n->leftNode);
        preorderTraverse(n->rightNode);
    }
}
void postorderTraverse(struct NODE *n){
    if(n != NULL){
        postorderTraverse(n->leftNode);
        postorderTraverse(n->rightNode);
        printf("%d\n",n->value);
    }
}

void addNode(int data, struct NODE *n){
    if(n->value > data){
        if(n->leftNode == NULL){
            n->leftNode = malloc(sizeof(struct NODE));
            n->leftNode->leftNode = NULL;
            n->leftNode->rightNode = NULL;
            n->leftNode->value = data;
        }
        else{
        addNode(data,n->leftNode);
        }
    }
    else{
        if(n->rightNode == NULL){
            n->rightNode = malloc(sizeof(struct NODE));
            n->rightNode->leftNode = NULL;
            n->rightNode->rightNode = NULL;
            n->rightNode->value = data;
        }
        else{
        addNode(data,n->rightNode);
        }
    }
}

void addAllNodes(struct NODE *n, struct NODE *to){
    addNode(n->value,to);
    if(n->leftNode != NULL){
        addAllNodes(n->leftNode,to);
    }
    if(n->rightNode != NULL){
        addAllNodes(n->rightNode,to);
    }
}

void freeTree(struct NODE *n){
    if(n->leftNode != NULL){
        freeTree(n->leftNode);
    }
    if(n->rightNode != NULL){
        freeTree(n->rightNode);
    }
    free(n);
}

int search(int data, struct NODE*n){
    if(data == n->value){
        return 1;
    }
    if(data > n->value){
        if(n->rightNode == NULL){
            return 0;
        }
        return search(data,n->rightNode);
    }
    else{
        if(n->leftNode == NULL)
        {
            return 0;
        }
        return search(data,n->leftNode);
    }
}

void removeNode(int data, struct NODE *n)
{
    struct NODE *tmp, *tmp2;
    if (n->value == data)
    {
        if(n->leftNode == NULL && n->rightNode == NULL)
        {
            free(n);
            n = NULL;
        }
        else if (n->leftNode == NULL)
        {   
            tmp = n->rightNode;
            n->leftNode = tmp->leftNode;
            n->rightNode = tmp->rightNode;
            n->value = tmp->value;
            free(tmp);
        }
        else if (n->rightNode == NULL)
        {
            tmp = n->leftNode;
            n->leftNode = tmp->leftNode;
            n->rightNode = tmp->rightNode;
            n->value = tmp->value;
            free(tmp);
        }
        else
        {
            tmp = n->leftNode;
            tmp2 = n->rightNode;
            n->rightNode = tmp->rightNode;
            n->leftNode = tmp->leftNode;
            n->value = tmp->value;
            
            addAllNodes(tmp2,n);
            freeTree(tmp2);
        }
    }
    else if (n->value > data)
    {
        removeNode(data,n->leftNode);
    }
    else
    {
        removeNode(data,n->rightNode);
    }
    
}

int main(){

    struct TREE *myTree = malloc(sizeof(struct TREE));
    struct NODE *rootNode = malloc(sizeof(struct NODE));
    myTree->root_node = rootNode;
    rootNode->leftNode = NULL;
    rootNode->rightNode = NULL;
    rootNode ->value = 50;

    addNode(30,myTree->root_node);
    addNode(10,myTree->root_node);
    addNode(5,myTree->root_node);
    addNode(18,myTree->root_node);
    addNode(40,myTree->root_node);
    addNode(45,myTree->root_node);
    addNode(80,myTree->root_node);
    addNode(90,myTree->root_node);
    addNode(85,myTree->root_node);
    addNode(83,myTree->root_node);
    addNode(86,myTree->root_node);
    preorderTraverse(myTree->root_node);
    printf("============================================\n");
    removeNode(50,myTree->root_node);
    preorderTraverse(myTree->root_node);
    
    return 0;
}