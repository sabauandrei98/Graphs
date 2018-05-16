#pragma once

#include "Graph.h"
#include <vector>
#include <queue>
#include <stack>
#include <Windows.h>
#define inf (1<<20)

class Algorithm
{
private:
	void dfs_printComponent(int node, vector<bool>& seen, Graph& g)
	{
		vector<pair<int, int>>& neighbours = g.returnNeighbours(node);
		for (int i = 0; i < neighbours.size(); i++)
		{
			int n = neighbours[i].first;
			if (!seen[n])
			{
				cout << n << " ";
				seen[n] = true;
				dfs_printComponent(i, seen, g);
			}
		}
	}

public:

	void bellmanFord_negativeCycle(int startNode, int endNode, Graph& g)
	{
		int gSize = g.getNumberOfNodes();
		vector<int> dist, neg;
		queue<int> q;

		dist.resize(gSize + 5);
		neg.resize(gSize + 5);

		for (int i = 0; i <= gSize; i++)
		{
			if (i != startNode)
			{
				dist[i] = inf;
				neg[i] = 0;
			}
			else
			{
				dist[i] = 0;
				neg[i] = 0;
			}
		}

		q.push(startNode);
		while (!q.empty())
		{
			int node = q.front();
			q.pop();

			if (neg[node] >= gSize)
			{
				cout << "Negative cycle !";
				return;
			}

			vector<pair<int, int>>& neighbours = g.returnNeighbours(node);
			for (int i = 0; i < neighbours.size(); i++)
				if (neighbours[i].second + dist[node] < dist[neighbours[i].first])
				{

					dist[neighbours[i].first] = neighbours[i].second + dist[node];
					q.push(neighbours[i].first);
					neg[neighbours[i].first]++;
				}
		}
		
		int node = endNode;
		stack<int> path;
		path.push(node);

		while (node != startNode)
		{
			
			int best = inf;
			int bNode;
			vector<pair<int, int>>& neighbours = g.returnInNeighbours(node);
			for (int i = 0; i < neighbours.size(); i++)
				if (dist[neighbours[i].first] < best)
				{
					best = dist[neighbours[i].first];
					bNode = neighbours[i].first;
				}
			node = bNode;
			path.push(node);
		}

		cout << "Path " << startNode << " -> " << endNode << endl;
		while (!path.empty())
		{
			cout << path.top() << " ";
			path.pop();
		}
	}


	void conexComponents(Graph& g)
	{
		int gSize = g.getNumberOfNodes() + 5;

		vector<bool> seen;
		seen.resize(gSize);

		int components = 0;
		
		for (int i = 0; i < g.getNumberOfNodes(); i++)
		{
			if (!seen[i])
			{
				cout << "Component no: " << components << "\n";
				seen[i] = true;

				this->dfs_printComponent(i, seen, g);
				cout << i << "\n";
				components++;
			}
			
		}
	}
};

