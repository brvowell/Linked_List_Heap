// Assignment 1: Heapsort
// Brandon Vowell
// CS 201

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "node.h"
#include "dsnode.h"
#include "linkedlist.h"

static lldatastructure *createStructure(void);

lldatastructure *newStructure(void) {
    lldatastructure *q = createStructure();
    q->head = malloc(sizeof(dsnode *));
    q->tail = malloc(sizeof(dsnode *));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void enqueue(lldatastructure *q, node *nd) {
    dsnode *val = assignDSNode(nd);
    if(q->head == NULL) {
        q->head = val;
        q->tail = val;
    }
    else {
        val->next = q->head;
        q->head->previous = val;
        q->head = val;
    }
}

node *dequeue(lldatastructure *q) {
    dsnode *valueToReturn = q->tail;
    q->tail = q->tail->previous;
    if(q->tail != NULL)
        q->tail->next = NULL;
    return valueToReturn->value;
}


void push(lldatastructure *stk, node *nd) {
    dsnode *val = assignDSNode(nd);
    if(stk->head == NULL) {
        stk->head = val;
        stk->tail = val;
    }
    else {
        val->next= stk->head;
        stk->head->previous = val;
        stk->head = val;
    }
    return;
}

node *pop(lldatastructure *stk) {
    dsnode *valueToReturn = stk->head;
    stk->head = stk->head->next;
    if(stk->head != NULL) 
        stk->head->previous = NULL;
    return valueToReturn->value;
}

////////////////////////////////////////////////

lldatastructure *createStructure() {
    lldatastructure *p = malloc(sizeof(lldatastructure));
    if(p == 0) {
        fprintf(stderr, "out of memory\n");
        exit(-1);
    }
    return p;
}
