#include<climits>
#include<iostream>
#include"binaryTreeNode.h"

BinaryTreeNode<int>* input();
void print(BinaryTreeNode<int>* root);

using namespace std;

/*pair<bool,pair<int,int> > checkBST(BinaryTreeNode<int> *root){
	
	pair<bool,pair<int,int> > ans = make_pair(true,make_pair(INT_MIN, INT_MAX));
	if(root == nullptr)
		return ans;
	
	ans.first = false;
    ans.second.first = ans.second.second = root->data;
	if((root->left != nullptr && root->left->data > root->data) || (root->right != nullptr && root->right->data < root->data))
		return ans;
	
	pair<bool,pair<int,int> > leftAns = checkBST(root->left);
	if(leftAns.first == false || leftAns.second.second > root->data)
		return ans;
	
	pair<bool,pair<int,int> > rightAns = checkBST(root->right);
	if(rightAns.first == false || rightAns.second.first < root->data)
		return ans;
	
	ans.first = true;
	if(leftAns.second.first != INT_MAX)
		ans.second.first = leftAns.second.first;
	if(rightAns.second.second != INT_MIN)
		ans.second.second = rightAns.second.second;
	return ans;
}*/
bool checkBST(BinaryTreeNode<int>*root , int min , int max){
    if(root == nullptr)
        return true;
    if(root->data > max || root->data < min)
        return false;
    return checkBST(root->left, min, root->data) && checkBST(root->right, root->data, max);
}

BinaryTreeNode<int>* constructBSTfromArr(int arr[], int start, int end){
    if(start>end)
        return nullptr;
    int mid = (start+end)/2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[mid]);
    BinaryTreeNode<int> *left = constructBSTfromArr(arr, start, mid-1);
    BinaryTreeNode<int> *right = constructBSTfromArr(arr, mid+1, end);
    root->left = left;
    root->right = right;
    return root;
}
#include"linkedList.h"
pair<node*,node*> LLfromBST(BinaryTreeNode<int> *root){
    pair<node*,node*> ans = make_pair(nullptr,nullptr);
    if(root == nullptr)
        return ans;
    pair<node*,node*> left = LLfromBST(root->left);
    pair<node*,node*> right = LLfromBST(root->right);
    node* curr = new node(root->data);
    if(left.second != nullptr){
        left.second->next = curr;
        ans.first = left.first;
    }
    else
        ans.first = curr;
    if(right.first != nullptr){
        curr->next = right.first;
        ans.second = right.second;
    }
    else
        ans.second = curr;
    return ans;
}
void delLL(node* head){
    if(head == nullptr)
        return;
    delLL(head->next);
    delete head;
}
void printLL(node* head){
    while(head != nullptr){
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
}

int main(){
    BinaryTreeNode<int> *root = input();
    //int arr[]= {1,2,3,4,5,6};
    //BinaryTreeNode<int>*root = constructBSTfromArr(arr,0,5);
    print(root);
    pair<node*,node*> LL = LLfromBST(root);
    printLL(LL.first);
    //cout << checkBST(root, INT_MIN, INT_MAX) << endl;
    delete root;
    delLL(LL.first);
    return 0;
}
