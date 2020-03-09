#include <iostream>

using namespace std;

struct NormalNode {
    int value;
    struct NormalNode *left;
    struct NormalNode *right;
};

struct ReverseNode {
    int value;
    struct ReverseNode *right;
    struct ReverseNode *left;
};

struct ReverseNode *reverseTree(struct NormalNode *root) {
    return (struct ReverseNode *)root;
}