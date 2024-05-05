
# ifndef STRUCT_DEC_H
# define STRUCT_DEC_H
# include <string>

using namespace std;

struct Node {
    int value;
    Node *right;
    Node *left;
};


struct Address {
    string name;
    string email;
    Address *left;
    Address *right;
};
# endif
