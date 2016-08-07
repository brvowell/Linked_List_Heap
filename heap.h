// Assignment 1: Heapsort
// Brandon Vowell
// CS201

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "node.h"
#include "linkedlist.h"
#include "dsnode.h"

#ifndef _HEAP_H
#define _HEAP_H


extern node *buildHeap(lldatastructure *, node *, node *);
extern void minHeapify(node *);
extern void maxHeapify(node *);
extern void disconnectChildFromParent(node *);


#endif
