#include "node.cpp"

class Tree{
	private:
		Node* root;
		int max;
		int height;

	public:

		Tree(){
			root = NULL;
			max = 0;
			height = 0;
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
				getMax(root->getLeft());
				getMax(root->getRight());
			return max;
		}

		bool findKey(Node* root,int key){
			if(root==NULL){
				return 0;
			}
			if(root->getKey()==key){
				return 1;
			}
			else{
				int temp = findKey(root->getLeft(),key);
				
				if(temp==1){
					return temp;
				}else{
					findKey(root->getRight(),key);
				}
			}
			
		}

		int getSize(Node* root){
			if(root==NULL){
				return 0;
			}
			int left = getSize(root->getLeft());
			int right = getSize(root->getRight());
			return left+right+1;
		}

		void deleteTree(Node* root){
			if (root == NULL){
				return;
			}
			deleteTree(root->getLeft());
			deleteTree(root->getRight());
			delete root;
		}

		int getHeight(Node* root,int height){
			if(root == NULL){
				return height;
			}else{
				
				int left = getHeight(root->getLeft(),height++);
				int right = getHeight(root->getRight(),height++);

				if(left>right){
					height = left;
				}else{
					height = right;
				}

			}
			return height;
		}





		int getMaxByStack(){
			int max = 0;
			stack<Node*> s;
			if(root == NULL)
				return 0;
			else{
				s.push(root);
				while(!s.empty()){
					auto top = s.top();
					s.pop();
					if(top->getKey() > max)
						max = top->getKey();
					if(top->getRight() != NULL)
						s.push(top->getRight());
					if(top->getLeft() != NULL)
						s.push(top->getLeft());
				}
			}
			return max;
		}
		bool findKeyByStack(int key){
			int max = 0;
			stack<Node*> s;
			if(root == NULL)
				return false;
			else{
				s.push(root);
				while(!s.empty()){
					auto top = s.top();
					s.pop();
					if(top->getKey() == key)
						return true;
					if(top->getRight() != NULL)
						s.push(top->getRight());
					if(top->getLeft() != NULL)
						s.push(top->getLeft());
				}
			}
		}
		int getSizeByStack(){
			int size = 0;
			stack<Node*> s;
			if(root == NULL)
				return size;
			else{
				s.push(root);
				while(!s.empty()){
					auto top = s.top();
					s.pop();
					size++;
					if(top->getRight() != NULL)
						s.push(top->getRight());
					if(top->getLeft() != NULL)
						s.push(top->getLeft());
				}
			}
			return size;
		}
		void getLevelOder(){
			queue<Node*> q;
			if(root == NULL)
				return;
			else{
				q.push(root);
				while(!q.empty()){
					auto front = q.front();
					q.pop();
					cout<<front->getKey()<<" ";
					if(front->getLeft() != NULL)
						q.push(front->getLeft());
					if(front->getRight() != NULL)
						q.push(front->getRight());
				}
			}
		}
};

int main(){

	Tree t;
	vector<int> v = {3,4,6,2,8,20};

	for(auto x:v){
		t.insertNodeInLevelOrder(x);
	}

	int a = t.getHeight(t.getRoot(),0);
	cout<<a<<"\n";
	a = t.findKeyByStack(11);
	cout<<a<<"\n";
	a = t.getSizeByStack();
	cout<<a<<"\n";
	t.getLevelOder();
	cout<<endl;
	return 0;
}