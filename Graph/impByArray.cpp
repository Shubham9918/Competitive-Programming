#include <bits/stdc++.h>
using namespace std;

class Graph{

	private:

		void bfsUtil(int i){
			queue <int> q;
			// color[i] = 1;
			distance[i] = 0;
			q.push(i);

			while(!q.empty()){
				auto current = q.front();
				q.pop();
				cout<<current<<"-->";

				for(auto x: getNeibour(current)){
					if(color[x]==0){
						color[x] = 1;
						previous[x] = current;
						distance[x] = distance[current]+1;
						q.push(x);
						

					}
					color[current] = 2;
				}
			}

		}

		void dfsUtil(int i){
			visited[i] = 1;
			cout<<i<<"-->";
			for (auto x: getNeibour(i)){
				if (visited[x]==0){
					dfsUtil(x);
				}
			}


		}

	public:
		int n;
		int **adjMatrix;
		bool *visited;
		int *color;
		int *distance;
		int *previous;
		Graph(int n){
			this->n = n;
			visited = new bool [n];
			adjMatrix = new int* [n];
			distance = new int [n];
			color = new int [n];
			previous = new int [n];
			previous[0] = -1;

			for (int i=0;i<n;i++){
				adjMatrix[i] = new int [n];
				for (int j=0;j<n;j++){
					adjMatrix[i][j] = 0;
				}
			}

		}

		void addEdge(int frm, int to, int cost){
			if (frm>=0 && frm<n && to>=0 && to<n){
				adjMatrix[frm][to] = cost;
			}
		}

		void printEdges(){
			for(int i=0;i<n;i++){
				for (int j=0;j<n;j++){
					if(adjMatrix[i][j]!=0){
						cout<<i<<"-->"<<j<<" = "<<adjMatrix[i][j]<<"\n";
					}
				}
			}
		}

		vector<int> getNeibour(int id){
			vector<int> neibour;
			if (id>=0 && id<n ){
				auto temp = adjMatrix[id];
				for (int i = 0; i < n; ++i){
					if(temp[i]!=0){
						neibour.push_back(i);
					}
				}
			}

			return neibour;

			
		}

		

		void dfsRun(){
			for (int i = 0; i < n; ++i)
			{
				if (visited[i]==0){
					dfsUtil(i);
				}
			}

		}

		

		void bfsRun(){
			for (int i = 0; i < n; ++i){
				if(color[i]==0){
					bfsUtil(i);
				}			

			}

		}
};

