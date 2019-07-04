#include <bits/stdc++.h>

using namespace std;

class Node{
	private:
		int key;
		Node *left,*right;

	public:
		Node(int key){
			this->key = key;
			left = NULL;
			right = NULL;
		}

		void updateKey(int key){
			this->key = key;
		}

		int getKey(){
			return this->key;
		}

		void addLeft(Node* left){
			this->left = left;
		}

		void addRight(Node* right){
			this->right = right;
		}

		Node* getRight(){
			return this->right ;
		}

		Node* getLeft(){
			return this->left;
		}

};

