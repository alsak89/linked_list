#include "Functions.h"

void InitLinkedList(LinkedList* list){
    list->head = NULL;
    list->size = 0;
}

void AddFirst(LinkedList* list, void* data, size_t size){
    if(list == NULL){
        return;
    }
    // allocate memory for node
    Node* new_node = (Node*)malloc(sizeof(Node));
    // allocate memory for new data
    new_node->data = malloc(size);
    // copy new data into allocated memory
    memcpy(new_node->data, data, size);    
    new_node->next = NULL;
    // place new node at list's beginning
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void ClearList(LinkedList* list){
    Node* head = list->head;
    Node* temp = head;
    while(head != NULL){
        head = head->next;
        free(temp->data);
        free(temp);        
        temp = head;
        list->size--;
    }
    list->head = NULL;
}

void PrintList(LinkedList* list, PrinterFunction printer){
    if(list == NULL){
        return;
    }
    Node* temp = list->head;
    while(temp != NULL){
        printf("[ ");
        printer(temp);
        printf(" ]");        
        temp = temp->next;
        if(temp != NULL){
            printf("->");
        }
    }
    printf("\n");
}

void AddLast(LinkedList* list, void* data, size_t size){
    if(list == NULL){
        return;
    }
    // create new node
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = malloc(size);
    memcpy(new_node->data, data, size);  
    new_node->next = NULL; 
    // empty list
    if(list->head == NULL){
        list->head = new_node;
    // non-empty list    
    }else{
        Node* temp = list->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }    
    list->size++;
}

int GetIndex(LinkedList* list, void* data, CompareFunction compare){
    if(list == NULL){
        return -1;
    }
    Node* temp = list->head;
    int index = 0;
    while(temp != NULL){
        if(compare(data, temp->data) == 0){
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

void RemoveNode(LinkedList* list, int index){
    if((list == NULL) || (index < 0) || (index > (list->size - 1))){
        return;
    }
    Node* temp = list->head;
    // if head needs to be removed
    if(index == 0){
        list->head = list->head->next;
        free(temp->data);
        free(temp);
        return;
    }
    // find previous node of the node to be deleted
    int i;
    for(i = 0; temp != NULL && i < index - 1; i++){
        temp = temp->next;
    }
    // store pointer of the node after the node to be deleted
    Node* next = temp->next->next;
    // delete node and reconnect the list
    free(temp->next->data);
    free(temp->next);
    temp->next = next;
    list->size--;
}
