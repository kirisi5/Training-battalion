typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode();
void insertNode(Node* head, int position, int value);
Node* removeNodde(Node* L, int value);
void printList(Node* head);
void freeList(Node* head);
int singleLists();
void SchangeParity(Node* head);
void swap(int* a, int* b);
void findCentre(Node* head);
int ifRing(Node* head);