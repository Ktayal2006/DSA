#include<iostream>
#include<vector>
#include"binaryTreeNode.h"

using namespace std;

/*template<typename T>
class binaryTree {
    private:
        BinaryTreeNode<T> *root;
    public:
        binaryTree(T data){
            root = new BinaryTreeNode<T>(data);
        }
        ~binaryTree(){
            delete root;
        }
        void print(){
            if(root == nullptr)
                return;
            cout << root->data << ':';
            if(root->left)
                cout << 'L' << root->left->data << ' ';
            if(root->right)
                cout << 'R' << root->right->data << endl;
            root->left.print();
            root->right.print();
        }
};*/
#include<queue>
BinaryTreeNode<int>* input(){
    int data;
    cout << "Enter Root Data" << endl;
    cin >> data;
    if(data == -1)
        return nullptr;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
    /*root->left = input();
    root->right = input();
    return root;*/
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int left;
        cin >> left;
        if(left != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(left);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter right child of " << front->data << endl;
        int right;
        cin >> right;
        if(right != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(right);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void print(BinaryTreeNode<int> * root){
    if(root == nullptr)
        return;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int> *front = pendingNodes.front();
        cout << front->data << ':';
        if(front->left){
            cout << 'L' << front->left->data << ' ';
            pendingNodes.push(front->left);
        }
        if(front->right){
            cout << 'R' << front->right->data;
            pendingNodes.push(front->right);
        }
        cout << endl;
        pendingNodes.pop();
    }
}
void printInorder(BinaryTreeNode<int>* root){
    if(root == nullptr)
        return;
    printInorder(root->left);
    cout << root->data << ' ';
    printInorder(root->right);
}
void printPreorder(BinaryTreeNode<int>* root){
    if(root == nullptr)
        return;
    cout << root->data << ' ';
    printPreorder(root->left);
    printPreorder(root->right);
}
void printPostorder(BinaryTreeNode<int>* root){
    if(root == nullptr)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << ' ';
}

int countNodes(BinaryTreeNode<int> *root){
    if(root == nullptr)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}
bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    if(root == nullptr)
        return false;
    if(root-> data == x)
        return true;
    return (isNodePresent(root->left, x) || isNodePresent(root->right, x));
}
int height(BinaryTreeNode<int>* root) {
    if(root == nullptr)
		return 0;
	int leftH = height(root->left);
	int rightH = height(root->right);
	int h = (leftH>rightH) ? leftH : rightH;
	return 1 + h;
}
int diameter(BinaryTreeNode<int>* root){
    if(root == nullptr)
        return 0;
    int opt1 = height(root->left) + height(root->right);
    int opt2 = diameter(root->left);
    int opt3 = diameter(root->right);
    return max(opt1, max(opt2,opt3));
}
BinaryTreeNode<int>* constructTree(int* pre, int* in, int preS, int preE, int inS, int inE){
    
    if(preS > preE|| inS > inE)
        return nullptr;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(*(pre+preS));
    
    int rootIndex;
    for(int i = inS; i<=inE; ++i ){
        if(*(in+i)== *(pre+preS)){
            rootIndex = i;
            break;
        } 
    }

    BinaryTreeNode<int>* left = constructTree(pre, in, preS+1, preS + rootIndex-inS, inS, rootIndex-1);
    BinaryTreeNode<int>* right = constructTree(pre, in, preS+rootIndex-inS+1, preE, rootIndex+1, inE);
    
    root->left = left;
    root->right = right;
    
    return root;
}

vector<int>* path(BinaryTreeNode<int>* root, int x){
    if(root == nullptr)
        return nullptr;
    if(root->data == x){
        vector<int>* ans = new vector<int>;
        ans->push_back(root->data);
        return ans;    
    }
    vector<int>* left = path(root->left, x);
    if(left != nullptr){
        left->push_back(root->data);
        return left;
    }
    vector<int>* right = path(root->right, x);
    if(right != nullptr){
        right->push_back(root->data);
        return right;
    }
    return nullptr;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){
    /*BinaryTreeNode<int> * root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> * n1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> * n2 = new BinaryTreeNode<int>(3);
    root->left = n1;
    root->right = n2;
    int pre[]={5,6,2,3,9,10};
    int in[]={2,6,3,9,5,10};*/
    BinaryTreeNode<int> * root = input();
    print(root);
    vector<int>* ans = path(root,9);
    for (int i = 0; i < ans->size(); i++) {
        cout << ans->at(i) << " ";
    }
    cout << endl;
    //cout << "Count = " << countNodes(root) << endl;
    delete root;
    delete ans;
    return 0;
}
