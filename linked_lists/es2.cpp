// tic tac toe linked list (only initialization, to complete is conceptually easy but boring)

# include <cstdlib>
# include <iostream>

using namespace std;

struct Node {
    int col;
    string value;
    Node *nextNode;
};

Node* initializeList (int cols) {
    Node *head = new Node;
    head -> value = "*";
    head -> col = 0;
    head -> nextNode = NULL;
    Node *current = head;
    for (int i = 1; i < cols; i++) {
        Node *node = new Node;
        node -> value = "*";
        node -> col = i;
        node -> nextNode = NULL;
        current -> nextNode = node;
        current = node;
    }
    return head;
}

void iterateList (Node *head) {
    Node *current = head;
    while (current) {
        cout << current -> value;
        current = current -> nextNode;
    }
}

void displayBoard (Node **heads, int rows) {
    for (int i = 0; i < rows; i++) {
        iterateList(heads[i]);
        cout << "\n";
    }
}

int main () {
    int rows;
    int cols;
    cout << "Set n. rows: ";
    cin >> rows;
    cout << "Set n. cols: ";
    cin >> cols;
    // pointer to an array of heads (pointers) of linked lists
    Node **heads = new Node* [rows];
    for (int i = 0; i < rows; i++) {
        heads[i] = initializeList(cols);
    }
    displayBoard(heads, rows);
}