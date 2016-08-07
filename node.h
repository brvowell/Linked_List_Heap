// Assignment 1: Heapsort
// Brandon Vowell
// CS201

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#ifndef _NODE_H
#define _NODE_H

typedef struct nodeobject{
    
    int key;
    struct nodeobject *right;
    struct nodeobject *left;
    struct nodeobject *parent;
} node;

extern node *makeAndFillNode(int);

#endif
