#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    struct node * next;
} ListNode_t;

ListNode_t * init() {
    ListNode_t *node = (ListNode_t *)malloc(sizeof(ListNode_t));
    node->val = 0;
    node->next = NULL;
    return node;
}

void add_space(ListNode_t *list, unsigned int amount) {
    ListNode_t *lp;
    for(lp = list; lp != NULL; lp = lp->next);
    
    unsigned int i;
    for(i = 0; i < amount, i++) {
        lp->next = (ListNode_t *)malloc(sizeof(ListNode_t));
        lp = lp->next;
        lp->val = 0;
        lp->next = NULL;
    }
}

ListNode_t * find_predecessor(ListNode_t *element, ListNode_t *list) {
    ListNode_t *lp;
    for(lp = list; lp != NULL; lp = lp->next) {
        if(lp->next == element)
            return lp;
    }
    return NULL;
}

ListNode_t * find_successor(ListNode_t *element, ListNode_t *list) {
    ListNode_t *lp;
    for(lp = list; lp != NULL; lp = lp->next) {
        if(element == lp->next)
            return lp->next;
    }
    return NULL;
}

void insert_after(ListNode_t *predecessor, ListNode_t *element, ListNode_t *list) {
    ListNode_t *lp, *lpp = NULL;
    for(lp = list; lp != NULL; lp = lp->next) {
        if(lp == predecessor && lp->next != NULL) {
            element->next = lp->next;
            lp->next = element;
        }
    }
}

void insert_before(ListNode_t *successor, ListNode_t *element, ListNode_t *list) {
    if(successor == list)
        element->next = successor;
    else {
        ListNode_t *lp;
        for(lp = list; lp != NULL; lp = lp->next) {
            if(lp->next == successor) {
                element->next = successor;
                lp->next = element;
                return;
            }
        }
        // shouldn't reach here, really.
    }
}
// TODO
void reverse(){

}

void for_loop_traverse(ListNode_t *list, void callbackFunc(), void *userData) {
    ListNode_t *lp;
    for(lp = list; lp != NULL; lp = lp->next) {
        callbackFunc(lp, userData);
    }
}

void while_loop_traverse(ListNode_t *list, void callbackFunc(), void *userData) {
    while(list != NULL) {
        callbackFunc(list, userData);
        list = list->next;
    }
}
