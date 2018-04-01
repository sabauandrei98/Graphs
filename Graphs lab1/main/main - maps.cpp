#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

ifstream f("graph1m.txt");

#define MAX_NODES 1000005

struct Node {
	vector<int> neighbours;
	vector<int> costs;
};





class Graph
{
private:
	map<int, Node> out;
	map<int, Node> in;
	int nodes;
	int edges;

public:
	Graph(){
        this->readGraph();
	}

	//a
	int getNumberOfNodes() { return nodes; }

	//b
	int isEdgeBetween(int nodeA, int nodeB){
        for (int i = 0; i < this->out[nodeA].neighbours.size(); i++)
            if (this->out[nodeA].neighbours[i] == nodeB)
                return i;
        return -1;
	}

	//c
	int inDegree(int node) { return in[node].neighbours.size(); }
	int outDegree(int node) { return out[node].neighbours.size(); }

	//d
	void iterateOutEdgesOfVetex(int node){
        for (vector<int>::iterator it = this->out[node].neighbours.begin() ; it != this->out[node].neighbours.end(); it++)
            cout << *it << " ";
	}

	//e
	void iterateInEdgesOfVetex(int node){
        for (vector<int>::iterator it = this->in[node].neighbours.begin(); it != this->in[node].neighbours.end(); it++)
            cout << *it << " ";
	}

	//g
	int modifyCost(int nodeA, int nodeB, int newCost){
        int pos = this->isEdgeBetween(nodeA, nodeB);
        if (pos != -1)
        {
            this->out[nodeA].costs[pos] = newCost;
            this->in[nodeB].costs[pos] = newCost;
            return 1;
        }
        return -1;
	}

private:
	void readGraph(){
        f >> this->nodes;
        f >> this->edges;

        for (int i = 1; i <= this->edges; i++)
        {
            int x, y, z;
            f >> x >> y >> z;

            this->out[x].neighbours.push_back(y);
            this->out[x].costs.push_back(z);

            this->in[y].neighbours.push_back(x);
            this->in[y].costs.push_back(z);

        }
	}
};



int main()
{
    Graph graph;
    return 0;
}
