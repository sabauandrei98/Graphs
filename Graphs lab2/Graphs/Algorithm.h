#pragma once

#include "Graph.h"
#include <vector>

class Algorithm
{
private:
	void dfs_showVertexes(int node, vector<bool>& seen, Graph& g)
	{
		vector<pair<int, int>>& neighbours = g.returnNeighbours(node);
		for (int i = 0; i < neighbours.size(); i++)
		{
			int n = neighbours[i].first;
			if (!seen[n])
			{
				cout << n << " ";
				seen[n] = true;
				dfs_showVertexes(i, seen, g);
			}
		}
	}

public:
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

				this->dfs_showVertexes(i, seen, g);
				cout << i << "\n";
				components++;
			}
			
		}
	}
};

