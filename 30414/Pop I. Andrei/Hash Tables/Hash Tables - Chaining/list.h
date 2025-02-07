#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct node
{
    char * content;
    struct node *next;
} nodeT;

typedef struct list
{
    nodeT * head;
    nodeT * tail;
    int size;
} listT;

void addToList(listT *l, char * content);

#endif
