/*
    Even Tree
    https://www.hackerrank.com/challenges/even-tree
*/

#include <iostream>
#include <list>
#include <stack>

using namespace std;

// implementing as tree takes a lot of time for insertion 
// (find the parent in the tree and then add the child)
// if implemented as a graph, then adjacency list is nothing but the children + parent
// Also, DFS in this graph will be DFS traversal of the tree 
class Tree {
	int nVertices;
	list<int> * children;
public:
	Tree(int _nVertices); // contructor
	void addEdge(int node1, int node2);
	void DFS(int startingNode);
};		

Tree::Tree (int _nVertices) {
	nVertices = _nVertices;
	children = new list<int>[nVertices];
}

void Tree::addEdge(int node1, int node2) {
	children[node1].push_back(node2);
	children[node2].push_back(node1);
}

void Tree::DFS(int startingNode) {
	stack<int> stack, stack2;
	int ans = 0;
	bool * visited = new bool[nVertices]();  
	int * size = new int[nVertices]();
	
	stack.push(startingNode);
	stack2.push(startingNode); // stack2 is being maintained for reverse BFS of the tree and calculating the size of subtrees in the process
	visited[startingNode] = true;

	while(!stack.empty()) {
		int s = stack.top();
		stack.pop();

		for(list<int>::reverse_iterator i = children[s].rbegin(); i != children[s].rend(); i++) {
			if(!visited[*i]) {
				stack.push(*i);
				stack2.push(*i);
				visited[*i] = true;
			}
		}
	}

	// tracing back the tree (reverse BFS) and calculating the size of subtrees
	// if the size of the subtree is even then it can be separated
	while(!stack2.empty()) {
		int s = stack2.top();
		
		size[s] = 1; // counting the root itself in the subtree size
		for(list<int>::iterator i = children[s].begin(); i != children[s].end(); i++) {
			if(size[*i] != 0) { // don't count the parent
				size[s] = size[s] + size[*i];
			}
		}
		if(size[s] % 2 == 0 && s != 0) { 
			ans++;
		}
		stack2.pop();
	}
	
	cout << ans;

	delete [] children;
	delete [] size;
}

int main() {
	int N, M;
	int node1, node2;

	cin >> N >> M;
	Tree tree(N);
	while(M--) {
		cin >> node1 >> node2;
		tree.addEdge(node1-1, node2-1);
	}

	tree.DFS(0);

	return 0;
}