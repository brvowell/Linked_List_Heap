// Assignment 1: Heapsort
// Brandon Vowell
// CS 201

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "node.h"
#include "dsnode.h"

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

// This type of structure will be used to create both the stack and queue
// used in the assignment. Certain functions will be associated with the queue
// and vice versa

typedef struct linkedListStructure {
    
    dsnode *head;
    dsnode *tail;

} lldatastructure;

extern lldatastructure *newStructure(void);
extern void enqueue(lldatastructure *, node *); // For Queue
extern node *dequeue(lldatastructure *); // For Queue
extern void push(lldatastructure *, node *); // For Stack
extern node *pop(lldatastructure *); // For Stack

#endif
