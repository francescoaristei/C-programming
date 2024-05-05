# ifndef FUNCTION_DEC_H
# define FUNCTION_DEC_H
# include "struct_dec.h"

void sortedOrder (Node *node);

void reversedSortedOrder (Node *node);

void displayTree (Node *node, int counter);

void freeMemory (Node *node);

Node* addNode (Node *node, int value);

int countNodes (Node *node);

void displayNodes (Node *node, int counter);

int ifBalanced (Node *node, int height, bool *balanced);

int maxOfMin (Node *node);

int minOfMax (Node *node);

bool checkSorted (Node *node);

Address *addNode (Address *node, string name, string email);

Address *search (Address *node, string name);

void updateEmail (Address *node, string name, string email);

Address* findMax (Address *node);

Address* removeMax (Address *node, Address *maxNode);

Address* removeNode (Address *node, string name);

void freeMemory (Address *node);

void displayAddresses (Address *node, int counter);

# endif
