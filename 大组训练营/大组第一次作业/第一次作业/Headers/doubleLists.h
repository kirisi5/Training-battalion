
typedef struct _Node {
    int data;
    struct _Node* next;
    struct _Node* prev;
} _Node;

_Node* createDuList();
void insertDuList(_Node* head, int position, int value); 
void deleteNodeAtPosition(_Node* head, int position);
void printDuList(_Node* head);
void freeDuList(_Node* head);
int doubleLists();
