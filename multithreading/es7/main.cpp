# include <thread>
# include <iostream>
# include <mutex>
# include <vector>
# include "node.h"

// TO FINISH!

using namespace std;

mutex m;

double sumOfValues (Node *root) {
    double sum = 0;
    vector<thread> threads;
    int nrOfNodes = root->nrOfNodes(root);
    if (nrOfNodes < 8) {
        for (int i = 0; i < nrOfNodes; i++) {
            threads.push_back(thread([&] {
                // variable local to the thread
                double temp = root -> getSum(root);
                {
                    lock_guard<mutex> lck(m);
                    sum += temp;
                }
            }));
        }
    }
    else {
        for (int i = 0; i < 8; i++) {
            threads.push_back(thread([&] {
                // variable local to the thread
                double temp = root -> getSum(root);
                {
                    lock_guard<mutex> lck(m);
                    sum += temp;
                }
            }));
        }
    }

    for (int i = 0; i < threads.size(); i++) {
        threads[i].join();
    }
    return sum;
}


int main () {
    int addNodes = 1;
    Node *root = NULL;
    cout << "First the tree is built" << "\n";
    while (addNodes) {
        double value;
        cout << "Set a value for the node: ";
        cin >> value;
        root = root -> addNode(root, value);
        cout << "1 to continue, 0 to exit: ";
        cin >> addNodes;
    }

    cout << "The tree is the following: " << "\n";
    root -> displayNodes(root, 0);
    cout << "\n";

    cout << "The sum of all the values of the nodes is: " << sumOfValues(root) << "\n";
}