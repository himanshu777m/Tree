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
	
	void insert(int value){
		insertH(root, value);
	}		
	
	void insertH(Node* helper, int value){
		if(root == NULL){
			root = new Node(value);
		}
		else if(helper->data > value){
			if(helper->left == NULL){
				helper->left = new Node(value);
				helper->left->parent = helper->left;
			}
			else insertH(helper->left, value);
		}
		else if(helper->data < value){
			if(helper->right == NULL){
				helper->right = new Node(value);
				helper->right->parent = helper->right;
			}
			else insertH(helper->right, value);
		}
	}
	
	void  display(){
		display2(root);
	}
	
	void display2(Node* helper){
		if(helper == NULL){ return;}
		display2(helper->left);
		cout << helper->data <<", ";
		display2(helper->right);
	}
	
	Node* search(int value){
		search2(root, value);
	}
	
	Node* search2(Node* helper, int value){
		if(value < helper->data){
			if(helper->left == NULL){ return NULL;}
			else search2(helper->left, value);
		}
		else if(value > helper->data){
			if(helper->right == NULL){ return NULL;}
			else search2(helper->right, value);
		}
		else return helper;	
	}
	
	void Fdisplay(){
		Fdisplay2(root,0,0);
	}
	
	void Fdisplay2(Node* helper, int i, int j){
		if(helper == NULL){ return;}
		
		Fdisplay2(helper->right, i++, j);
		
		for(int k=0; k<i+1; k++){
			cout << " ";
		}
		cout << helper->data <<endl;
		
		Fdisplay2(helper->left, i, j++);
	}
	
	Node* MinPtr(Node* start){
		Node* temp = start;
		while(temp->left != NULL){
			temp = temp->left;
		}
		return temp;
	}
	
	void replceData(Node* up, Node* down){
		int a = up->data;
		up->data = down->data;
		down->data = a;
	}
	
	void replace_with_parent(Node* curr, Node* rep){
		//check curr is left or right
		if(curr->parent->left == curr){
			curr->parent->left = rep;
		}
		else curr->parent->right = rep;
	}
	
	
	void delet(int a){ 
		Node* del = search(a);
		Node* rep = MinPtr(del->right);
		replceData(del, rep);
		Node* curr = rep->left;
		while(curr->right != NULL){
			curr = curr->right;
		}
		//curr = rep->right;
		//rep->parent->left = rep->left;
		//delete rep;
	}
	
	int count(Node* start){
		count2(root, 0,0,0);	
	}
	
	int count2(Node* temp, int i, int j, int k){
		if(temp == NULL){ return ;}
		count2(temp->left, i++, j);
		count2(temp->right, i, j++);
	}
	
} t1;

int main(){
	t1.insert(5);
	t1.insert(3);
	t1.insert(6);
	t1.insert(2);
	t1.insert(8);
	t1.insert(1);
	t1.insert(7);
	t1.insert(4);
	t1.insert(9);
	t1.display();
	cout <<endl;
	cout <<endl;
	cout << t1.search(4)->data <<endl;
	cout << t1.search(1)->data<<endl;
	t1.Fdisplay();
	cout << t1.MinPtr(t1.root->right)->data <<endl;
	t1.delet(5);
	t1.replceData(t1.root, t1.root->left);
	t1.display();
	cout << t1.count(t1.root);
}
