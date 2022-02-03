typedef struct Node Node;
typedef struct LinkedList LinkedList;

struct Node{
    struct Node* next;
    void* data;
};

struct LinkedList{
    struct Node* head;
    int size;
};

