#include "bst.h"

/*
 * Node Class Functions
*/

BSTNode::BSTNode(int data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

BSTNode::~BSTNode(){

}

/*
 * Tree Class Functions
*/

/*
 * Private Functions
*/

BSTNode* BSTree::insert(int data, BSTNode* root){
    if(!root){
        return new BSTNode(data);
    }

    // Go left if data < data at this Node
    if(data < root->data){
        root->left = insert(data, root->left);
    // Go right otherwise
    }else{
        root->right = insert(data, root->right);
    }

    return root;
}

BSTNode* BSTree::remove(int data, BSTNode* root){
    if(!root){
        return nullptr;
    }

    // We found what we're looking for, delete it.
    if(data == root->data){
        BSTNode* temp;
        // This is a leaf node
        if(root->left == root->right){
            delete root;
            return nullptr;
        }

        // This node has 1 child
        if(!root->left != !root->right){
            // Set temp to whichever child exists
            root->left ? temp = root->left : temp = root->right;

            delete root;
            return temp;
        }

        // This node has 2 children
        // Find the in-order successor
        temp = root->right;

        while(temp->left){
            temp = temp->left;
        }

        // Copy the data to this node and delete the original
        root->data = temp->data;
        root->right = remove(temp->data, root->right);
        return root;
    }

    // This is not the Node we're looking for, recursively find the data we want to delete
    if(data < root->data){
        root->left = remove(data, root->left);
    }else{
        root->right = remove(data, root->right);
    }

    return root;
}

BSTNode* BSTree::find_ios(BSTNode* root, bool& disconnect){
    if(!root->left){
        disconnect = true;
        return root;
    }
    BSTNode* temp = find_ios(root->left, disconnect);

    if(disconnect){
        root->left = nullptr;
        disconnect = false;
    }

    return temp;
}

int BSTree::height(BSTNode* root){
    if(!root){
        return -1;
    }
    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left + 1 : right + 1);
}

void BSTree::preorder(BSTNode* root, std::ostream& os){
    if(!root){
        return;
    }

    os << root->data << " ";
    this->preorder(root->left, os);
    this->preorder(root->right, os);

    return;
}

void BSTree::inorder(BSTNode* root, std::ostream& os){
    if(!root){
        return;
    }

    this->inorder(root->left, os);
    os << root->data << " ";
    this->inorder(root->right, os);

    return;
}

void BSTree::postorder(BSTNode* root, std::ostream& os){
    if(!root){
        return;
    }

    this->postorder(root->left, os);
    this->postorder(root->right, os);
    os << root->data << " ";

    return;
}

void BSTree::destroy(BSTNode* root){
    if(!root){
        return;
    }

    this->destroy(root->left);
    this->destroy(root->right);
    delete root->left;
    delete root->right;
}

bool BSTree::search(int data, BSTNode* root){
    if(!root){
        return false;
    }

    if(data == root->data){
        return true;
    }

    if(data < root->data){
        return this->search(data, root->left);
    }else{
        return this->search(data, root->right);
    }
}

/*
 * Public Functions
*/

BSTree::BSTree(){
    this->_root = nullptr;
}

BSTree::~BSTree(){
    delete this->_root;
}

void BSTree::insert(int data){
    this->_root = this->insert(data, this->_root);
}

void BSTree::remove(int data){
    this->_root = this->remove(data, this->_root);
}

int BSTree::height(){
    return this->height(this->_root);
}

void BSTree::preorder(std::ostream& os){
    this->preorder(this->_root, os);
    os << "\n";
}

void BSTree::inorder(std::ostream& os){
    this->inorder(this->_root, os);
    os << "\n";
}

void BSTree::postorder(std::ostream& os){
    this->postorder(this->_root, os);
    os << "\n";
}

bool BSTree::search(int data){
    return this->search(data, this->_root);
}