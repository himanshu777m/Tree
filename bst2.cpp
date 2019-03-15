#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;
	Node* parent;
	
	Node(int value){
		data = value;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};

class BST{
	public:
	
	Node* root;
	
	BST(){
		root = NULL;
	}
	
	void ptrLast(Node* temp, int value){
		if(root == NULL){ root = new Node(value); }
		else if(temp->data > value){
			if(temp->left == NULL){
				 temp->left = new Node(value);
				 temp->left->parent =temp;
			}
			else{ return ptrLast( temp->left, value); }
		}
		else if(temp->data < value){ 
			if(temp->right == NULL){ 
				temp->right = new Node(value);
				temp->right->parent = temp;
			}
			else { return ptrLast( temp->right, value); }
		}
	}
	
	void insert(int value){
		ptrLast(root, value);
	}
	
	void display(){
		display2(root);
	}
	
	void display2(Node* curr){	
		if(curr == NULL) return;
		display2(curr->left);
		cout << curr->data << ",";
		display2(curr -> right);
	}
	
	int search(int value){
		Node* ptr = root;
		while(ptr != 0){
			if(value == ptr->data){
				return value;
			}
			else if(value < ptr->data){
				ptr = ptr->left;
			}
			else if(value > ptr->data){
				ptr = ptr->right;
			}
			else return 0;	
		}
	}
	
}t1;

int main(){
	t1.insert(9);
	t1.insert(3);
	t1.insert(6);
	t1.insert(8);
	t1.insert(1);
	t1.insert(4);
	t1.display();
	cout <<endl;
	cout << t1.search(3) <<endl;
	cout << t1.search(1)<<endl;
}