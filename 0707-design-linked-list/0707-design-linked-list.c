


typedef struct MyLinkedList {
    int val;
    struct MyLinkedList *next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList *p = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    p->next = NULL;
    return p;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList *ptr = obj->next;
    for (int i = 0; i < index; i++) {
        ptr = ptr->next;
        if (ptr == NULL) {
            return -1;
        }
    }

    if (ptr == NULL) {
        return -1;
    }

    return ptr->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList *p = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    p->val = val;
    p->next = obj->next;
    obj->next = p;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList *p = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    p->val = val;
    p->next = NULL;
    MyLinkedList *ptr = obj;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = p;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList *p = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    p->val = val;
    MyLinkedList *prev = obj;
    for (int i = 0; i < index; i++) {
        if (prev == NULL) {
            return;
        }
        prev = prev->next;
    }
    if (prev == NULL) {
        return;
    }
    p->next = prev->next;
    prev->next = p;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList *prev = obj;
    for (int i = 0; i < index; i++) {
        prev = prev->next;
        if (prev->next == NULL) {
            return;
        }
    }
    
    MyLinkedList *tmp = prev->next;
    prev->next = tmp->next;
    free(tmp);
}

void myLinkedListFree(MyLinkedList* obj) {
    while (obj->next != NULL) {
        MyLinkedList *tmp = obj->next;
        obj->next = tmp->next;
        free(tmp);
    }
    
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/