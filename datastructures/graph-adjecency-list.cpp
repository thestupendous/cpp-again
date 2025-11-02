// Weighted undirected graph
// What is done -
//     - add an edge
//     - remove an edge
//     - BFS traversal
//     - print graph
//		- DFS traversal
// What's left -
//		- DFS traversal - failing! test and correct
//		- TESTING!!  TODO

#include <vector>
#include <iostream>
#include <queue>
#include <stack>
using std::vector, std::cout, std::pair, std::queue;

typedef vector<pair<unsigned,unsigned>> EdgesVector;

class Graph{
private:
	unsigned verticesCount;
	unsigned edgeCount;
	vector < EdgesVector > edgeList;
public:
	Graph(unsigned size): verticesCount{size},
		edgeCount{0}
	{
		for (auto i{0};i<size;i++) {
			EdgesVector v;
			edgeList.push_back(v);
		}
	}

	void addEdge(unsigned vertex1,unsigned vertex2, unsigned weight) {
		edgeList[vertex1].push_back( {vertex2,weight} );
		edgeList[vertex2].push_back( {vertex1,weight} );
		edgeCount += 2;
		cout << "Log: added 2 edges\n";
	}

	void removeEdge(unsigned vertex1,unsigned vertex2){
		for (auto i{0};i<edgeList[vertex1].size();i++) {
			if ( edgeList[vertex1][i].first == vertex2) {
				edgeList[vertex1].erase(edgeList[vertex1].begin() + i);
				break;
			}
		}

		// doing again for mirror edge (bcz it's undirected graph)
		for (auto i{0};i<edgeList[vertex2].size();i++) {
			if ( edgeList[vertex2][i].first == vertex1) {
				edgeList[vertex2].erase(edgeList[vertex2].begin() + i);
				break;
			}
		}
	}

	vector<unsigned> traverseBFS(unsigned startingVertex){
		cout << "Log: In BFS Traversal\n";
		vector<unsigned> traversalResult;
		queue<unsigned> q;
		q.push(startingVertex);
		bool isProcessed[verticesCount] = {}; // initialize with all zeros

		unsigned curr;
		while( !q.empty() ) {
			// take out top from queue
			curr = q.front();
			q.pop();
			
			// process the top
			traversalResult.push_back(curr);
			cout << curr << ",";

			// add all neighbors of it to queue
			for (auto &item: edgeList[curr]) {
				if (!isProcessed[item.first]) {
					q.push(item.first);
				}
			}
			isProcessed[curr] = true;
		}
		return traversalResult;
	}

	vector<unsigned> traverseDFS(unsigned startingVertex){
		cout << "Log: In DFS Traversal\n[";
		std::stack<unsigned> st;
		vector<unsigned> traversalResult;
		bool isProcessed[verticesCount] = {}; // initialize with all zeros

		// push starting vertex to stack
		st.push(startingVertex);

		unsigned curr;
		bool anyNeighbor = false;
		while( !st.empty() ){
			// process current
			curr = st.top();
			cout << curr << ',';
			if ( !isProcessed[curr] ) {
				traversalResult.push_back(curr);
				isProcessed[curr] = true;
			}

			anyNeighbor = false;
			for (auto &neighbor: edgeList[curr]) {
				if ( !isProcessed[neighbor.first]) {
					st.push(neighbor.first);
					anyNeighbor = true;
					break;
				}
			}
			if (!anyNeighbor) {
				st.pop();
			}
		}
		cout << "]\n";

		return traversalResult;
	}

	void print(){
		cout << "Printing Graph---\n";
		cout << "No of Vertices: " << verticesCount << '\n';
		cout << "No of Edges: " << edgeCount << '\n';
		for (unsigned i{0};i<verticesCount;i++) {
			cout << "Node " << i << " : [ ";
			for (auto &item: edgeList[i]) {
				cout << "(" << item.first << "," << item.second << ") ,";
			}
			cout << " ]\n";
		}
		cout << "\n";
	}

};

int main(){
	Graph graph(4);
	graph.addEdge(0,1,10);
	graph.print();

	vector<unsigned> traversalBFS{graph.traverseBFS(0)};
	cout << "***********____________\n[";
	for(auto e: traversalBFS) {
		cout << e << ',';
	}
	cout << "]\n";

	graph.traverseDFS(0);

	graph.removeEdge(0,1);
	graph.print();
}
