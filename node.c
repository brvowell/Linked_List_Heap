// Assignment 1: Heapsort
// Brandon Vowell
// CS201

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "node.h"

static node *newNode(void);
    

node *makeAndFillNode(int i) {
    node *temp = newNode();
    temp->key = i;
    temp->right = NULL;
    temp->left = NULL;
    temp->parent = NULL;;
    return temp;
}

//////////////////////////////////////////////////

static node *newNode() {
    node *p = malloc(sizeof(node));
    if (p == 0) {
        fprintf(stderr, "out of memory");
        exit(1);
    }
    return p;
}
