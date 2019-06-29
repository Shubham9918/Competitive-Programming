#include <bits/stdc++.h>
using namespace std;

class Graph{

	private:
		int n;
		int **adjMatrix;
		bool *visited;

	public:
		Graph(int n){
			this->n = n;
			visited = new bool [n];
			adjMatrix = new int* [n];

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

};

int main()
{
	Graph G(5);
	G.addEdge(0,2,10);
	G.addEdge(1,3,5);
	G.addEdge(4,4,2);
	G.printEdges();
	// G.printVisited();
	return 0;
}


