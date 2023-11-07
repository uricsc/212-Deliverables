#pragma once

#include <iostream>
#include <ostream>

// Defines MAX
// When used, MAX(a,b) will be replaced with ((a > b) ? a : b)
#ifndef MAX
#define MAX(a,b) ((a > b) ? a : b)
#endif

// Underlying class which will be used to implement the BSTree class.
// I.E. BSTree is made up of BSTNode
class BSTNode
{
    private:
        int data;
        BSTNode* left;
        BSTNode* right;

    public:
        BSTNode(int data);
        ~BSTNode();

    friend class BSTree;
};

// Public versions: accept a single parameter so the usage of the class is neat.
// Private version: implement the functions recursively
class BSTree
{
    private:
        BSTNode* _root;

        BSTNode* insert(int data, BSTNode* root);
        BSTNode* remove(int data, BSTNode* root);
        BSTNode* find_ios(BSTNode* root, bool& disconnect);
        int height(BSTNode* root);

        void preorder(BSTNode* root, std::ostream& os);
        void inorder(BSTNode* root, std::ostream& os);
        void postorder(BSTNode* root, std::ostream& os);

        void destroy(BSTNode* root);
        bool search(int data, BSTNode* root);

    public:
        BSTree();
        ~BSTree();

        void insert(int data);
        void remove(int data);
        int height();

        void preorder(std::ostream& os = std::cout);
        void inorder(std::ostream& os = std::cout);
        void postorder(std::ostream& os = std::cout);

        bool search(int data);

};
