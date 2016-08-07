// Assignment 1: Heapsort 
// Brandon Vowell
// CS 201

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "node.h"
#include "dsnode.h"
#include "linkedlist.h"
#include "heap.h"

void heapifyTree(lldatastructure *, lldatastructure *, char **, int);
void printSortedOrder(lldatastructure *, node *, char **, int);

int main(int argc, char *argv[]) {

    int choice;
    FILE *fp;
    if(argv[1][0] == '-') {
        fp = fopen(argv[2], "r");
        choice = 1;
    }
    else {
        fp = fopen(argv[1], "r");
        choice = 0;
    }
    if(argv[1][1] == 'v') {
        system ("cat info.txt");
        return 0;
    }
    int num;
    node *treeNode;
    node *root = malloc(sizeof(node));
    lldatastructure *q = newStructure();
    lldatastructure *stk = newStructure();
    fscanf(fp, "%d", &num);
    while(!feof(fp)) {
        treeNode = makeAndFillNode(num);
        root = buildHeap(q, treeNode, root);
        push(stk, treeNode);
        fscanf(fp, "%d", &num);
    }
    fclose(fp);
    lldatastructure *q2 = newStructure();
    heapifyTree(stk, q2, argv, choice);
    printSortedOrder(q2, root, argv, choice);
    printf("\n\n");
    free(treeNode); free(root); free(q); free(stk); free(q2);
    return 0;
}

/////////////////////////////////////////////

void heapifyTree(lldatastructure *stk, lldatastructure *q2, char *argv[], int choice) {
    while(stk->head != NULL) {
         node *poppedOff = pop(stk);
         enqueue(q2, poppedOff);
         if(choice == 1)
            maxHeapify(poppedOff);
         else
            minHeapify(poppedOff);
    }
    return;
}

void printSortedOrder(lldatastructure *q2, node *root, char *argv[], int choice) {
    node *poppedOff;
    while(q2->tail != NULL) {
        printf("%d ", root->key);
        poppedOff = dequeue(q2);
        root->key = poppedOff->key;
        disconnectChildFromParent(poppedOff);
        if(choice == 1)
            maxHeapify(root);
        else
            minHeapify(root);
    }
    return;
}
