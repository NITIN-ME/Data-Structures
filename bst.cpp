#include<iostream>
using namespace std;

class Node{
	public:		
		int value;
		Node* left;
		Node* right;
};

class BST{
	private:
		Node* root;
		Node* insert(Node* root, int num);
		void preOrder(Node* root);
		void inOrder(Node* root);
		void postOrder(Node* root);
		bool search(Node* root, int num);
		Node* remove(Node* root, int num);
	public:
		BST();
		void insert(int num);
		void preOrder();
		void inOrder();
		void postOrder();
		void search(int num);
		void remove(int num);
		Node* findMinNode(Node* root);
};

BST::BST(){
	this->root = nullptr;
}

void BST::insert(int num){
	this->root = insert(this->root, num);
}

Node* BST::insert(Node* root, int num){
	if(root == nullptr){
		Node* node = new Node();
		node->value = num;
		node->left = node->right = nullptr;
		root = node;
	}
	else if(root->value < num){
		root->right = insert(root->right, num);
	}
	else{
		root->left = insert(root->left, num);
	}
	return root;
}

void BST::preOrder(){
	cout<<"preOrder: ";
	preOrder(this->root);
	cout<<endl;
}

void BST::inOrder(){
	cout<<"inOrder: ";
	inOrder(this->root);
	cout<<endl;
}

void BST::postOrder(){
	cout<<"postOrder: ";
	postOrder(this->root);
	cout<<endl;
}

void BST::preOrder(Node* root){
	if(root != nullptr){
		cout<<root->value<<"  ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void BST::inOrder(Node* root){
	if(root != nullptr){
		inOrder(root->left);
		cout<<root->value<<"  ";
		inOrder(root->right);
	}
}

void BST::postOrder(Node* root){
	if(root != nullptr){
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->value<<"  ";
	}
}

void BST::search(int num){
	bool flag = search(this->root, num);
	if(flag){
		cout<<num<<" found!"<<endl;
	}
	else{
		cout<<"Not found!"<<endl;
	}
}

bool BST::search(Node* root, int num){
	if(root == nullptr){
		return false;
	}
	else if(root->value == num){
		return true;
	}
	else if(root->value < num){
		return search(root->right, num);
	}
	else{
		return search(root->left, num);
	}
}

void BST::remove(int num){
	root = remove(root, num);
}

Node* BST::remove(Node* root, int num){
	if(root == nullptr){
		return root;
	}
	else if(root->value < num){
		root->right = remove(root->right, num);
	}
	else if(root->value > num){
		root->left = remove(root->left, num);
	}
	else{
		if(root->left == nullptr){
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right == nullptr){
			Node* temp = root->left;
			delete root;
			return temp;
		}
		cout<<"finding min node"<<endl;
		Node* temp = findMinNode(root->right);
		cout<<"temp: "<<temp->value<<endl;
		root->value = temp->value;
		root->right = remove(root->right, temp->value);
	}
	return root;
}

Node* BST::findMinNode(Node* root){
	Node* temp = root;
	while(temp->left != nullptr){
		temp = temp->left;
	}
	return temp;
}

int main(){
	BST t;
	t.insert(40);
	t.insert(30);
	t.insert(60);
	t.insert(20);
	t.insert(35);
	t.insert(50);
	t.insert(80);
	t.insert(10);
	t.insert(25);
	t.insert(34);
	t.insert(37);
	t.insert(45);
	t.insert(55);
	t.insert(70);
	t.insert(90);
	//t.preOrder();
	t.inOrder();
	//t.postOrder();
	cout<<endl<<endl<<"========================================================================"<<endl;
	/*
	while(1){
		cout<<"Enter the number you wanna find: ";
		int num;
		cin>>num;
		t.search(num);
	}
	*/
	while(1){
		cout<<"Enter the number you wanna delete: ";
		int num;
		cin>>num;
		t.remove(num);
		t.inOrder();
		cout<<endl<<endl<<"========================================================================"<<endl;
	}
	cout<<endl<<endl<<"========================================================================"<<endl;
	return 0;
}
