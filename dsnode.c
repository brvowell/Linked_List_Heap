// Assignment 1: Heapnode
// Brandon Vowell
// CS 201

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "node.h"
#include "dsnode.h"

static dsnode *createDSNode(void);

dsnode *assignDSNode(node *ndptr) {
    dsnode *temp = createDSNode();
    temp->value = ndptr;
    temp->next = NULL;
    temp->previous = NULL;
    return temp;
}


dsnode *createDSNode() {
    dsnode *temp = malloc(sizeof(dsnode));
    if(temp == 0) {
        fprintf(stderr, "out of memory");
        exit(-1);
    }
    return temp;
}
