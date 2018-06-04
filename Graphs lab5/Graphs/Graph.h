#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream f("graph1k.txt");

class Graph
{
private:
	vector< vector<pair<int, int> > > out;
	vector< vector<pair<int, int> > > in;
	int nodes;
	int edges;

public:
	Graph() {
		this->readGraph();
	}

	//a
	int getNumberOfNodes() { return nodes; }

	//b
	int isEdgeBetween(int nodeA, int nodeB) {
		for (int i = 0; i < this->out[nodeA].size(); i++)
			if (this->out[nodeA][i].first == nodeB)
				return i;
		return -1;
	}

	//c
	int inDegree(int node) { if (isDeleted(node)) return -1; return (int)in[node].size(); }
	int outDegree(int node) { if (isDeleted(node)) return -1; return (int)out[node].size(); }

	//d
	void iterateOutEdgesOfVetex(int node) {
		if (isDeleted(node))
			return;

		for (vector<pair<int, int> >::iterator it = this->out[node].begin(); it != this->out[node].end(); it++)
			cout << it->first << " " << it->second << '\n';
	}

	//e
	void iterateInEdgesOfVetex(int node) {
		if (isDeleted(node))
			return;

		for (vector<pair<int, int> >::iterator it = this->in[node].begin(); it != this->in[node].end(); it++)
			cout << it->first << " " << it->second << '\n';
	}

	//g
	int modifyCost(int nodeA, int nodeB, int newCost) {
		if (isDeleted(nodeA))
			return -1;
		if (isDeleted(nodeB))
			return -1;

		int pos = this->isEdgeBetween(nodeA, nodeB);
		if (pos != -1)
		{
			this->out[nodeA][pos].second = newCost;
			this->in[nodeB][pos].second = newCost;
			return 1;
		}
		return -1;
	}

	//bonus - add/remove vertex
	void addVertex()
	{
		if (this->out.capacity() < this->out.size() + 1)
		{
			this->out.resize(this->out.capacity() * 2);
			this->in.resize(this->out.capacity() * 2);
		}
	}

	int removeVertex(int node)
	{
		if (isDeleted(node))
			return -1;

		for (int i = 0; i < out[node].size(); i++)
			this->removeEdge(out[node][i].first, node);
	
		for (int i = 0; i < in[node].size(); i++)
			this->removeEdge(in[node][i].first, node);

		this->out[node].clear();
		this->in[node].clear();

		this->out[node].push_back(make_pair(-1, 0));
		this->in[node].push_back(make_pair(-1, 0));
	}

	//bonus - add/remove edge
	void addEdge(int nodeA, int nodeB, int cost)
	{
		
		if (isDeleted(nodeA))
			return;

		if (isDeleted(nodeB))
			return;

		int pos = this->isEdgeBetween(nodeA, nodeB);
		if (pos != -1)
			return;
		
		this->out[nodeA].push_back(make_pair(nodeB, cost));
		this->in[nodeB].push_back(make_pair(nodeA, cost));
	}

	void removeEdge(int nodeA, int nodeB)
	{
		if (isDeleted(nodeA))
			return;
		if (isDeleted(nodeB))
			return;

		int pos = this->isEdgeBetween(nodeA, nodeB);
		if (pos == -1)
			return;

		for (int i = 0; i < out[nodeA].size(); i++)
			if (out[nodeA][i].first == nodeB)
				out[nodeA].erase(out[nodeA].begin() + i);

		for (int i = 0; i < in[nodeB].size(); i++)
			if (in[nodeB][i].first == nodeA)
				in[nodeB].erase(in[nodeB].begin() + i);
	}

	//bonus - copy graph
	Graph& operator=(Graph& graph)
	{
		this->out.resize(graph.nodes);
		this->in.resize(graph.nodes);

		for (int i = 0; i < graph.nodes; i++)
		{
			this->out[i] = graph.out[i];
			this->in[i] = graph.in[i];
		}
	}

	vector<pair<int,int>>& returnNeighbours(int node)
	{
		return this->out[node];
	}

	vector<pair<int, int>>& returnInNeighbours(int node)
	{
		return this->in[node];
	}



private:
	void readGraph() {
		f >> this->nodes;
		f >> this->edges;

		this->out.resize(this->nodes + 1);
		this->in.resize(this->nodes + 1);

		for (int i = 1; i <= this->edges; i++)
		{
			int x, y, z;
			f >> x >> y >> z;
			
			//cout << x << " " << y << " " << z << endl;

			this->out[x].push_back(make_pair(y, z));
			this->in[y].push_back(make_pair(x, z));

			//This for undirected
			this->out[y].push_back(make_pair(x, z));
			this->in[x].push_back(make_pair(y, z));

		}
		
	}


	bool isDeleted(int node)
	{
		if (this->out[node].size() == 1 && out[node][0].first == -1)
			return true;
		return false;
	}

};


