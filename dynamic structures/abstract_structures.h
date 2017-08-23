

/* LINKED LIST */
typedef struct ElementList {
    int data; // ElementoLista->dato
    struct ElementList *link; // pointer to the next node structure
} Node;

/* DOUBLE LINKED LIST */
typedef struct DoubleNode {
    int data;
    struct DoubleNode *next;
    struct DoubleNode *prev;
} BiNode;

/* FUNCTIONS FOR LINKED LISTS */
Node *initList();
void insertFront(int value); // insert at first position
void insertInPosition(int value, int position); // insert at a specific position
void insertLast(int value); // insert at last position (append)
int deleteFront(); // Delete first element
int deletePosition(int n); // delete a Node at certain position
int deleteLast(); // Delete last element (pop)
void printList(); // print current elements

/* FUNCTIONS FOR DOUBLE LINKED LIST */
BiNode getBiNode(int value);
void InsertAtHead(int value);

// Global variable
Node *head;
BiNode *head2;