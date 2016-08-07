// Assignment 1: Heapsort
// Brandon Vowell
// CS 201

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "node.h"

#ifndef _DSNODE_N
#define _DSNODE_N

typedef struct dataStructureNode {
    
    node *value;
    struct dataStructureNode *next;
    struct dataStructureNode *previous;

} dsnode;

extern dsnode *assignDSNode(node *);

#endif
