//
// Created by yx C on 2023/1/23.
//
#ifndef PJ1_MY_MALLOC_H
#define PJ1_MY_MALLOC_H
#include <stdio.h>
#include <stdbool.h>

struct node {
    size_t size;
    //bool isFree;
    struct node* next;
    struct node* prev;
};
typedef struct node node;
//Thread Safe malloc/free: locking version 
void *ts_malloc_lock(size_t size);
void ts_free_lock(void *ptr);

//Thread Safe malloc/free: non-locking version 
void *ts_malloc_nolock(size_t size);
void ts_free_nolock(void *ptr);


//Best Fit malloc/free
void *bf_malloc(size_t size, node** headNode, node** tailNode, int mode);
void bf_free(void *ptr, node** headNode, node** tailNode);

//Find bf node
node* findNode_bf(size_t size, node** headNode, node** tailNode);
//Make a new node
node* newNode(size_t size);
//newNode with lock
node* newNode_lock(size_t size);
//remove a node from free list
void removeNode(node* n1, node** headNode, node** tailNode);
//add node to free list
void addNode(node* n1, node** headNode, node** tailNode);
//merge node together
void mergeNode(node* n1, node** headNode, node** tailNode);
//split node if necessary
node* splitNode(node* curr, size_t size, node** headNode, node** tailNode);

//get the total data segmentation size
unsigned long get_data_segment_size(); //in bytes
//get the free data size
unsigned long get_data_segment_free_space_size(); //in byte

node* headNode = NULL;//head node of list
node* tailNode = NULL;//tail node of list
unsigned long len_node = 0;//total size of heap;

#endif //PJ1_MY_MALLOC_H
