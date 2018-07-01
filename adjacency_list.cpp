#include<iostream>
#include<vector>
using namespace std;

class Graph{
	private:
		int size;
		vector<int>* arr;
	public:
		Graph(int s){
			size = s;
			arr = new vector<int>[s];
		}
		
		void addedge(int x, int y){
			arr[x].push_back(y);
			arr[y].push_back(x);
		}
		
		void showGraph(){
			for(int i = 0; i < size; i++){
				cout<<i<<" -> ";
				for(int j = 0; j < arr[i].size(); j++){
					cout<<arr[i][j]<<"  ";
				}
				cout<<endl;
			}
		}
};

int main(){
	Graph g(5);
	g.addedge(0, 1);
	g.addedge(0, 4);
	g.addedge(1, 2);
	g.addedge(1, 3);
	g.addedge(1, 4);
	g.addedge(2, 3);
	g.addedge(3, 4);
	g.showGraph();
	return 0;
}
