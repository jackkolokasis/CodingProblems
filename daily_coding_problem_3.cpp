/**
 * Given the root to a binary tree, implement serialize(root), which
 * serializes the tree into a string, and deserialize(s), which
 * deserializes the string back into the tree.
 *
 * For example, given the following Node class
 *
 * class Node:
 *     def __init__(self, val, left=None, right=None):
 *             self.val = val
 *             self.left = left
 *             self.right = right
 *
 * The following test should pass:
 *
 * node = Node('root', Node('left', Node('left.left')), Node('right'))
 * assert deserialize(serialize(node)).left.left.val == 'left.left'
 *
 */

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

#define MARKER ')'

// Binary tree node
typedef struct _Node
{
    int val;                // Value
    struct _Node *left;     // Left child
    struct _Node *right;    // Right child
} Node;

/*
 * @desc Allocate a new node with given key and NULL left and right
 * pointers
 *
 * @param val   Value of the node
 *
 */
Node* newNode(int val)
{
    Node* tmp = new Node;

    tmp->val   = val;
    tmp->left  = NULL;
    tmp->right = NULL;

    return (tmp);
}

/*
 * @desc Serialize tree and store it to a file
 *
 * @param root  Root of the tree
 * @param fp    File pointer
 *
 */
void serialize(Node *root, FILE *fp)
{
    if (root == NULL)
    {
        fprintf(fp, "%c", MARKER);
        return;
    }

    fprintf(fp, "%d", root->val);
    serialize(root->left, fp);
    serialize(root->right, fp);
}

int main()
{
    // Create a dummy tree
    Node *root        = newNode(10);
    root->left        = newNode(8);
    root->right       = newNode(15);
    root->left->left  = newNode(4);
    root->left->right = newNode(9);

    FILE *fp = fopen("tree.txt", "w");
    
    if (fp == NULL)
    {
        cout << "Can not open the file" << endl;
        return 0;
    }

    serialize(root, fp);

    return 1;
}
