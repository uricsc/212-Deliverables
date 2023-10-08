#include "bst.h"
#include <fstream>
#include <sstream>

void print_tree(BSTree* tree, int mode);

// <file_name> <traversal_method>
int main(int argc, char*argv[]){
    std::ifstream ifs(argv[1]);
    int mode = std::stoi(argv[2]);

    BSTree tree;

    std::string line;

    // Get the numbers to be inserted
    std::getline(ifs, line);
    std::stringstream ss(line);

    int num;
    // Insert the numbers
    while(ss >> num){
        tree.insert(num);
        print_tree(&tree, mode);
    }

    // Get the numbers to be removed
    std::getline(ifs, line);
    ss.clear();
    ss.str(line);

    // Remove the numbers
    while(ss >> num){
        tree.remove(num);
        print_tree(&tree, mode);
    }
}

/*
 * pre = 1
 * in = 2
 * post = 4
 * pre+in = 3
 * pre+post = 5
 * in+post = 6
 * pre+in+post = 7
 */
void print_tree(BSTree* tree, int mode){
    if(mode == 1 || mode == 3 || mode == 5 || mode == 7){
        tree->preorder();
    }
    if(mode == 2 || mode == 3 || mode == 6 || mode == 7){
        tree->inorder();
    }
    if(mode == 4 || mode == 5 || mode == 6 || mode == 7){
        tree->postorder();
    }
}
