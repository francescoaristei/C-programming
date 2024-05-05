/*

A tree data structure is implemented in C++ using the class Node
Write a C++ function double sumOfValues(Node *root) that computes the sum of all the double
values in the tree concurrently, using 8 threads to speed up the computation. Assume that all trees
passed to the function are balanced. If the tree does not have enough nodes, then it is allowable to
spawn less threads, or no threads at all, but for large trees the computation must be split across 8
concurrently operating threads to parallelize the computation. No more than 8 threads must be
spawned regardless of the tree structure.

*/

# ifndef NODE
# define NODE

# include <iostream>

using namespace std;

class Node
{
    public:
        Node(double v, bool passed = false, Node *l = nullptr, Node *r = nullptr) : v(v), l(l), r(r) {}
        double getValue() const { return v; }
        Node *left()  { return l; }
        Node *right()  { return r; }
        int nrOfNodes (Node *node);
        bool getPassed () { return passed; }
        void setPassed (Node *node) { node -> passed = true; }
        void displayNodes (Node *node, int counter);
        double getSum (Node *node);
        Node* addNode (Node *node, double v);
    private:
        double v;
        Node *l, *r;
        bool passed;
};

double Node::getSum (Node *node) {
    if (!node) {
        return 0;
    }
    if (node -> passed){
        return 0 + getSum(node -> l) + getSum(node -> r);
    }
    else {
        setPassed(node);
        return node -> v + getSum(node -> l) + getSum(node -> r);
    }
}


void Node::displayNodes (Node *node, int counter) {
    if (!node) {
        return;
    }
    displayNodes(node -> l, counter + 1);
    cout << "\n";
    for (int i = 0; i < counter; i++) {
        cout << "     ";
    }
    cout << node -> v;
    displayNodes(node -> r, counter + 1);
}

Node* Node::addNode (Node *node, double v) {
    if (!node) {
        Node *newNode = new Node(v);
        return newNode;
    }
    else if (node -> v > v) {
        node -> r = addNode(node -> right(), v);
    }
    else {
        node -> l = addNode(node -> left(), v);
    }
    return node;
}

int Node::nrOfNodes (Node *node) {
    if (!node) {
        return 0;
    }

    return 1 + nrOfNodes(node -> r) + nrOfNodes(node -> l);
}

# endif