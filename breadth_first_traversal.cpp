#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
	private:
		int size;
		vector<int>* arr;
	public:
		Graph(int s);
		void addedge(int x, int y);
		void showGraph();
		void BFS(int s);
};

Graph::Graph(int s){
	size = s;
	arr = new vector<int>[s];
}

void Graph::addedge(int x, int y){
	arr[x].push_back(y);
	arr[y].push_back(x);
}

void Graph::showGraph(){
	for(int i = 0; i < size; i++){
		cout<<i<<" -> ";
		for(int j = 0; j < arr[i].size(); j++){
			cout<<arr[i][j]<<"  ";
		}
		cout<<endl;
	}
}

void Graph::BFS(int s){
	cout<<"BFS: ";
	bool* visited = new bool[size];
	for(int i = 0; i < size; i++){
		visited[i] = false;
	}
	visited[s] = true;
	list<int> q;
	q.push_back(s);
	vector<int>::iterator i;
	
	while(!q.empty()){
		int k = q.front();
		cout<<k<<"  ";
		q.pop_front();
		
		for(i = arr[k].begin(); i != arr[k].end(); i++){
			if(!visited[*i]){
				visited[*i] = true;
				q.push_back(*i);
			}
		}
	}
	
}

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
	g.BFS(2);
	return 0;
}
