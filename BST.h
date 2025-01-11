#include"binaryTreeNode.h"
class BST{
    binaryTreeNode<int>* root;
    bool helperHasData(binaryTreeNode<int>* curr, int val){
        if(curr == nullptr)
            return false;
        if(curr->data == val)
            return true;
        if(curr->data > val)
            return helperHasData(curr->left, val);
        return helperHasData(curr->right, val);
    }
    binaryTreeNode<int>* helperInsert(binaryTreeNode<int>* curr, int val){}
    public:
    BST()
        :root(nullptr){}
    ~BST(){
        delete root;
    }
    void insert(int val){}
    void del(int val){}
    bool hasData(int val){
        return helperHasData(root);
    }
};
