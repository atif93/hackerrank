/*
    Breadth First Search: Shortest Reach
    https://www.hackerrank.com/challenges/bfsshortreach
*/

#include <iostream>
#include <queue>
#include <list>

using namespace std;

class Graph {
    int nVertices; // number of vertices in the graph
    list<int> * adj; // adjacency list
public:
    Graph(int _nVertices); // constructor
    void add_edge(int node1, int node2); // adding edge to the adjacency list
    void breadth_first_search(int startingNode); // main logic for bfs 
    void print_result(int * distance); // prints the bfs shortest reach results
};

Graph::Graph(int _nVertices) {
    nVertices = _nVertices;
    adj = new list<int>[nVertices];
}

void Graph::add_edge(int node1, int node2) {
    adj[node1].push_back(node2);
    adj[node2].push_back(node1);
}

void Graph::breadth_first_search(int startingNode) {
    bool * visited = new bool[nVertices](); // intialized to 0 with brackets at the end
    //int * distance = new int[nVertices]{-1}; // intialized to -1 // can be used with --std=c++0x flag (C++11)
    int * distance = new int[nVertices]; 
    std::fill_n(distance, nVertices, -1); // intialized to -1
    queue<int> mQueue;

    mQueue.push(startingNode);
    distance[startingNode] = 0;
 
    // since all the edges are of equal length = 6
    // we can just find the number of edges from the origin and multiply by 6
    while(!mQueue.empty()) {
        int s = mQueue.front();
        mQueue.pop();
        visited[s] = 1;
        for(list<int>::iterator i = adj[s].begin(); i != adj[s].end(); i++) {
            if(!visited[*i]) {
                distance[*i] = distance[s] + 1;
                visited[*i] = 1;
                mQueue.push(*i);
            }
        }
    }   

    print_result(distance);

    delete [] visited;
    delete [] distance;
}

void Graph::print_result(int * distance) {
    for(int i=0; i<nVertices; i++) {
        if(distance[i] != 0) {
            if(distance[i] != -1) {
                cout << 6 * distance[i];
            } else {
                cout << distance[i];                 
            }
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    int q, n, m, s;
    int node1, node2; 
    
    cin >> q;
    while(q--) {
        cin >> n >> m;
        
        Graph graph(n);

        for(int i=0; i<m; i++) {
            cin >> node1 >> node2;
            // since the indices are starting from 0
            node1--; 
            node2--;
            graph.add_edge(node1, node2);
            graph.add_edge(node2, node1);
        }
        cin >> s;
        // since the indices are starting from 0
        s--;
        
        graph.breadth_first_search(s);
    }
    
    return 0;
}