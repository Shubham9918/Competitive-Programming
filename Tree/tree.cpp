#include "node.cpp"

class Tree{
	private:
		Node* root;

	public:

		Tree(){
			root = NULL;
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



};

int main(){

	Tree t;
	t.insertNodeInLevelOrder(4);
	t.insertNodeInLevelOrder(2);
	t.insertNodeInLevelOrder(5);
	t.insertNodeInLevelOrder(6);
	t.insertNodeInLevelOrder(7);
	t.insertNodeInLevelOrder(8);
	t.insertNodeInLevelOrder(9);
	t.preOrder(t.getRoot());
	auto res = t.preOrderStack();
	cout<<endl;
	for(auto x: res){
		cout<<x->getKey()<<"->";
	}
	return 0;
}