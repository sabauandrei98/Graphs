// Graphs.cpp : Defines the entry point for the console application.
//

#include "Graph.h"
#include "Algorithm.h"

void Run()
{
	Graph graph;

	
	cout << "Number of nodes: " << graph.getNumberOfNodes() << '\n';
	cout << "Is edge between 0-154 ? " << graph.isEdgeBetween(0, 154) << '\n';
	cout << "In degree of 0: " << graph.inDegree(0) << '\n';
	cout << "Out degree of 0: " << graph.outDegree(0) << '\n';
	cout << "Iterate in edges of 0: \n"; graph.iterateInEdgesOfVetex(0);
	cout << "Iterate out edges of 0: \n"; graph.iterateOutEdgesOfVetex(0);
	cout << "Modify cost (0->154) to 999"; graph.modifyCost(0, 154, 999); cout << '\n'; graph.iterateOutEdgesOfVetex(0);

	

	cout << '\n';
	cout << "Add vertex 1001\n"; graph.addVertex(); 
	
	cout << "Add edge 0 -> 1001 with cost 99 \n"; graph.addEdge(0, 1001, 99); graph.iterateOutEdgesOfVetex(0);
	cout << "Delete vertex 1001 \n";  graph.removeVertex(1001);
	graph.iterateOutEdgesOfVetex(0);
	cout << '\n';
	graph.iterateInEdgesOfVetex(1001);

	cout << '\n';
	graph.iterateOutEdgesOfVetex(1001);
	
	cout << "Remove edge 0 -> 154 \n"; graph.removeEdge(0, 154);
	graph.iterateOutEdgesOfVetex(0);

	
	Graph newGraph = graph;
	cout << "\nnewGraph out edges for 0: \n";
	newGraph.iterateOutEdgesOfVetex(0);
	

}

void RunAlgo()
{
	Graph myGraph;
	Algorithm myAlgo;
	myAlgo.conexComponents(myGraph);
}

int main()
{
	//Run();
	RunAlgo();
	system("pause");
    return 0;
}

