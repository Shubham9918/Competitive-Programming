#include "node.cpp"

class Tree{
	private:
		Node* root;
		int max;

	public:

		Tree(){
			root = NULL;
			max = 0;
		}

		Node* getRoot(){
			return root;
		}

		void insertNodeInLevelOrder(int data){

			Node* temp = new Node(data);
			if (root==NULL){
				root = temp;
				return;
			}else{
				queue<Node* > q;
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

		void preOrder(Node* ct){
			if(ct==NULL){	
				return ;
			}
			cout<<ct->getKey()<<"->";
			inOrder(ct->getLeft());
			inOrder(ct->getRight());
		}

		void postOrder(Node* ct){
			if(ct==NULL){	
				return ;
			}
			inOrder(ct->getLeft());
			inOrder(ct->getRight());
			cout<<ct->getKey()<<"->";
			
		}

		void inOrder(Node* ct){
			if(ct==NULL){	
				return ;
			}
			inOrder(ct->getLeft());
			cout<<ct->getKey()<<"->";
			inOrder(ct->getRight());
		}

		vector<Node*> preOrderStack(){
			stack<Node*> s;
			vector<Node*> res;
			s.push(root);

			while(!s.empty()){
				auto top = s.top();
				s.pop();
				res.push_back(top);
				if(top->getRight()!=NULL){
					s.push(top->getRight());
				}
				if(top->getLeft()!=NULL){
					s.push(top->getLeft());
				}
			}
			return res;
		}

		int getMax(Node* root){

			if(root==NULL){
				return max;
			}
				if(root->getKey()>max){
					max = root->getKey();
				}
				findMax(root->getLeft());
				findMax(root->getRight());
			return max;
		}



};

int main(){

	Tree t;
	vector<int> v = {3,4,6,2,8,20,8,5,7,9,0};

	for(auto x:v){
		t.insertNodeInLevelOrder(x);
	}

	int a = t.getMax(t.getRoot());
	cout<<a<<"\n";


	return 0;
}