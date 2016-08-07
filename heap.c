// Assignment 1: Heapsort
// Brandon Vowell
// CS 201

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "node.h"
#include "dsnode.h"
#include "linkedlist.h"

node *buildHeap(lldatastructure *q, node *treeNode, node *root) {
    if(q->tail == NULL) {
        enqueue(q, treeNode);
        root = treeNode;
        return root;
    }
    if(q->tail->value->left == NULL) {
        q->tail->value->left = treeNode;
        treeNode->parent = q->tail->value;
        enqueue(q, treeNode);
    }
    else if(q->tail->value->right == NULL) {
        q->tail->value->right = treeNode;
        treeNode->parent = q->tail->value;
        enqueue(q, treeNode);
    }
    else {
        dequeue(q);
        buildHeap(q, treeNode, root);
    }
    return root;
}

void minHeapify(node *removedNode) {
    if(removedNode->left == NULL) 
        return;
    else if(removedNode->right == NULL && removedNode->left != NULL) {
        if(removedNode->left->key < removedNode->key) {
            int temp = removedNode->left->key;
            removedNode->left->key = removedNode->key;
            removedNode->key = temp;
            return minHeapify(removedNode->left);
        }
    }
    else {
        int left = removedNode->left->key;
        int right = removedNode->right->key;
        int min = (right <= left) ? right : left;
        node *nodeLeastValue = (right <= left) ? removedNode->right : removedNode->left;
        if(min < removedNode->key) {
            int temp = min;
            if(min == right)
                removedNode->right->key = removedNode->key;
            else
                removedNode->left->key = removedNode->key;
            removedNode->key = temp;
            return minHeapify(nodeLeastValue); 
        }
    }
    return;
}

void maxHeapify(node *removedNode) {
    if(removedNode->left == NULL)
        return;
    else if(removedNode->right == NULL && removedNode->left != NULL) {
        if(removedNode->left->key > removedNode->key) {
            int temp = removedNode->left->key;
            removedNode->left->key = removedNode->key;
            removedNode->key = temp;
            return maxHeapify(removedNode->left);
        }
    }
    else {
        int left = removedNode->left->key;
        int right = removedNode->right->key;
        int max = (left > right) ? left : right;
        node *nodeMostValue = (left > right) ? removedNode->left : removedNode->right;
        if(max > removedNode->key) {
            int temp = max;
            if(max == right)
                removedNode->right->key = removedNode->key;
            else
                removedNode->left->key = removedNode->key;
            removedNode->key = temp;
            return maxHeapify(nodeMostValue); 
        }
    }
    return;
}

void disconnectChildFromParent(node *child) {
    if(child->parent == NULL) 
        return;
    if(child->parent->right == NULL) {
        child->parent->left = NULL;
        return;
    }
    else
        child->parent->right = NULL;
    return;
}
