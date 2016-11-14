/*
    Breadth First Search: Shortest Reach
    https://www.hackerrank.com/challenges/bfsshortreach
*/

#include <stdio.h>

int queue[1000], tail = -1, head = 0;

int isQueueEmpty() {
    if(tail<head) {
        return 1;
    }
    return 0;
}

void pushQueue(int s) {
    queue[++tail] = s; 
}

int popQueue() {
   if(isQueueEmpty()) {
       return -1;
   } 
   return queue[head++];
}
    
int main() {
    int q, n, m, s;
    int i, j, node1, node2; 
    int a[1000][1000], visited[1000], distance[1000];
    
    scanf("%d", &q);
    while(q--) {
        scanf("%d %d", &n, &m);
        for(i=0; i<n; i++) {
            for(j=0; j<=i; j++) {
                a[i][j] = 0;
                a[j][i] = 0;
            }
        }
        for(i=0; i<m; i++) {
            scanf("%d %d", &node1, &node2);
            // since the indices are starting from 0
            node1--; 
            node2--;
            a[node1][node2] = 6;
            a[node2][node1] = 6;
        }
        scanf("%d", &s);
        // since the indices are starting from 0
        s--;
        head = 0;
        tail = -1;
        pushQueue(s);
        
        for(i=0; i<n; i++) {
            visited[i] = 0;
            distance[i] = -1;
        }
        distance[s] = 0;
        
        // since all the edges are of equal length = 6
        // we can just find the number of edges from the origin and multiply by 6
        while(!isQueueEmpty()) {
            s = popQueue();
            visited[s] = 1;
            for(i=0; i<n; i++) {
                if(a[s][i] == 6 && visited[i] == 0) {
                    distance[i] = distance[s] + 1;
                    visited[i] = 1;
                    pushQueue(i);
                }
            }
        }
      
        for(i=0; i<n; i++) {
            if(distance[i] != 0) {
                if(distance[i] != -1) {
                    printf("%d ", 6 * distance[i]);
                } else {
                    printf("%d ", distance[i]);                 
                }
            }
        }
        printf("\n");
    }
    
    return 0;
}