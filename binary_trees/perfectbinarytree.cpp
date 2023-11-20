#include <iostream>
using namespace std;


class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data){
        this -> data = data;
        left = nullptr;
        right = nullptr;
    }
};

int depth(Node* node){
    // initially for empty tree depth is -1
    int d = -1;
    while(node!=nullptr){
        // for node root depth is 0
        d++;
        node=node->left;
    }
    return d;
}

bool isPerfectRecc(Node* node , int d, int level = 0){

    if(node == nullptr){
        return true;
    }
    if(node->left == nullptr && node->right == nullptr){
        return true;
    }
    if(node->left == nullptr || node->right == nullptr){
        return false;
    }

    return isPerfectRecc(node->left, d, level+1) && isPerfectRecc(node->right, d, level+1);
}

bool isPerfect(Node* root){
    int d  = depth(root);
    return isPerfectRecc(root,d);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    if(isPerfect(root))
        cout << "the tree is perfect binary tree\n";
    else   
        cout << "the tree is not perfect binary tree\n";
}