#include <bits/stdc++.h>
using namespace std;

class node{
	public:
		int key;
		node* left,right;

		node(int key){
			this->key = key; 
			left = NULL;
			right = Null;
		}

		int getKey(){
			return key;
		}

		void setKey(int key){
			this->key = key;
		}

		void setLeft(node* left){
			this->left = left;
		}

		void setRight(node* left){
			this->left = left;
		}

		node* getLeft(){
			return left;
		}

		node* getRight(){
			return right;
		}
}

class tree{
	private:
		node *root;

	public:
		tree(){
			root = NULL;
		}

		node* getRoot(){
			return root;
		}

		void insertNodeInOrderLevel(int data){

			node* newNode = node(data);
			if(root == NULL){
				root = newNode;
				return;
			}else{
				queue<Node* >q;
				q.push(root);
				while(!q.empty()){
					auto top = q.front();
					q.pop();
					if(top->getLeft() != NULL){
						q.push(top->getLeft());
					}else{
						top->addLeft(temp);
						return;
					}
					if(top->getRight()!=NULL){
						q.push(top->getRight());

					}else{
						top->addRight(temp);
						return;
					}
				}
			}
		}

}
