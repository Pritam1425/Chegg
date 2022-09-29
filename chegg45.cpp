#include<iostream>
#include<vector>
using namespace std;
class BinarySearchTree{
	int data;
	BinarySearchTree* left,*right;
	public:
		BinarySearchTree(int data=0){
			this->data = data;
			this->left = NULL;
			this->right = NULL;
		}
		BinarySearchTree* insert(BinarySearchTree* root,int value){
			if(!root){
				return new BinarySearchTree(value);
			}
			if(value>root->data){
				root->right = insert(root->right,value);
			}
			else{
				root->left = insert(root->left,value);
			}
			return root;
		}
		
		void help(BinarySearchTree* node,int n){//helper function
			if(!node){
				return;
			}
			help(node->left,n);
			if(node->data>n){
				cout<<node->data<<endl;
			}
			help(node->right,n);
		}
		void displayGreaterThan(int n){
			help(this->left,n);//first find the data fields in the left subtree
			if(this->data>n)//if the current node has greater value than n, print
				cout<<this->data<<endl;
			help(this->right,n);//find the data fields in the right subtree
		}
};
int main()
{
	BinarySearchTree node,*root=NULL;//root is the root of the tree
	
	root = node.insert(root,50);//Inserting the data into node object and pointing it to the root
	node.insert(root,30);
	node.insert(root,20);
	node.insert(root,40);
	node.insert(root,70);
	node.insert(root,60);
	node.insert(root,80);
	
	root->displayGreaterThan(40);//Here is the desired function
	return 0;
}
