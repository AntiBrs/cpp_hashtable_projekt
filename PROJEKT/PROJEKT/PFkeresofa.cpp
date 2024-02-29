#include<iostream>
#include "lista.h"
#include <string>
using namespace std;

// Defining the Node structure
struct Node 
{
    int data;
    bool color;
    Node* left, * right, * parent;

    // Constructor
    Node(int data) {
        this->data = data;
        left = right = parent = NULL;
        // Color of new node is always red
        color = true;
    }
};

class RedBlackTree 
{
private:
    Node* root;

    // Rotate left function
    void rotateLeft(Node* node) {
        Node* rightChild = node->right;
        node->right = rightChild->left;
        if (node->right != NULL)
            node->right->parent = node;
        rightChild->parent = node->parent;
        if (node->parent == NULL)
            root = rightChild;
        else if (node == node->parent->left)
            node->parent->left = rightChild;
        else
            node->parent->right = rightChild;
        rightChild->left = node;
        node->parent = rightChild;
    }

    // Rotate right function
    void rotateRight(Node* node) {
        Node* leftChild = node->left;
        node->left = leftChild->right;
        if (node->left != NULL)
            node->left->parent = node;
        leftChild->parent = node->parent;
        if (node->parent == NULL)
            root = leftChild;
        else if (node == node->parent->left)
            node->parent->left = leftChild;
        else
            node->parent->right = leftChild;
        leftChild->right = node;
        node->parent = leftChild;
    }

    // Fix the Red-Black Tree property violations
    void fixViolation(Node* node) {
        Node* parent = NULL;
        Node* grandParent = NULL;
        while (node != root && node->color == true && node->parent->color == true) {
            parent = node->parent;
            grandParent = node->parent->parent;
            if (parent == grandParent->left) {
                Node* uncle = grandParent->right;
                if (uncle != NULL && uncle->color == true) {
                    grandParent->color = true;
                    parent->color = false;
                    uncle->color = false;
                    node = grandParent;
                }
                else {
                    if (node == parent->right) {
                        rotateLeft(parent);
                        node = parent;
                        parent = node->parent;
                    }
                    rotateRight(grandParent);
                    std::swap(parent->color, grandParent->color);
                    node = parent;
                }
            }
            else {
                Node* uncle = grandParent->left;
                if (uncle != NULL && uncle->color == true) {
                    grandParent->color = true;
                    parent->color = false;
                    uncle->color = false;
                    node = grandParent;
                }
                else {
                    if (node == parent->left) {
                        rotateRight(parent);
                        node = parent;
                        parent = node->parent;
                    }
                    rotateLeft(grandParent);
                    std::swap(parent->color, grandParent->color);
                    node = parent;
                }
            }
        }
        root->color = false;
    }
public:
    // Constructor
    RedBlackTree() {
        root = NULL;
    }

    // Insert function
    void insert(int data) {
        Node* node = new Node(data);
        Node* parent = NULL;
        Node* current = root;
        while (current != NULL) {
            parent = current;
            if (node->data < current->data)
                current = current->left;
            else
                current = current->right;
        }
        node->parent = parent;
        if (parent == NULL)
            root = node;
        else if (node->data < parent->data)
            parent->left = node;
        else
            parent->right = node;
        fixViolation(node);
    }

    // Search function
    bool search(int data) {
        Node* current = root;
        while (current != NULL) {
            if (data == current->data)
                return true;
            else if (data < current->data)
                current = current->left;
            else
                current = current->right;
        }
        return false;
    }
};

