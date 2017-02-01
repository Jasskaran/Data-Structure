#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
	vector<vector<int> >adj;
	int v,*visited,*d;
public:
	Graph(int);
	void addEdge(int,int);
	void display();
	void BFS(int);
	void displayBFS();
};

Graph::Graph(int v)
{
	this->v=v;
	adj.resize(v);
	visited = new int[v];
	d = new int[v];
}

void Graph::addEdge(int x,int y)
{
	adj[x].push_back(y);
}

void Graph::display()
{
	vector<int>:: iterator it;
	for(int i=0;i<v;i++)
	{
		cout<<i<<"->";
		for(it=adj[i].begin(); it!=adj[i].end(); it++)
			cout<< *it<<" ";
		cout<<endl;
	}
}

void Graph::BFS(int s)
{
	for(int i=0;i<v;i++)
	{
		visited[i]=0;
		d[i]=0;
	}
	visited[s]=1;
	queue<int> Q;
	Q.push(s);
	while(!(Q.empty()))
	{
		int u;
		u=Q.front();
		Q.pop();
		vector<int>::iterator it;
		for(it=adj[s].begin();it!=adj[s].end();it++)
		{
			if(visited[*it]==0)
			{
				visited[*it]=1;
				d[*it]=d[u]+1;
				Q.push(*it);
			}
		}
	}
}

void Graph::displayBFS()
{
	//vector<int>:: iterator it;
	for (int i = 0; i < v; ++i)
	{
		cout<<i<<"->"<<d[i]<<" ";
	}
}

int main()
{
	Graph g(5);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(3,1);
	g.addEdge(4,3);
	g.addEdge(0,1);
	g.display();
	g.BFS(2);
	g.displayBFS();
}

