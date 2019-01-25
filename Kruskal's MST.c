/*
* Kruskal's MST Algorithm - C Implementation using Arrays
* Author - github.com/sampathbalivada
* Donot write comments in Observation.
* Uncomment code in functions for debugging
*/

#include <stdio.h>
#include <stdlib.h>

int n;

typedef struct edge {
    int v1, v2, cost;
} Edge;

//Currently using static values for array size. Change to dynamic to optimize
int a[100][100], visitedVertices[100], visitedIterator = -1;

int isVertexVisited(int vertex) {
    int a, i;
    /*if(visitedIterator == -1) {
     printf("-1\n");
    } else {
        for(i=0; i<=visitedIterator; ++i) {
        printf("%d ", visitedVertices[i]);
        }
        printf("\n");
    }*/
    if(visitedIterator == -1) {
        return 0;
    }
    for(a=0; a<=visitedIterator; ++a) {
        if(visitedVertices[a] == vertex) {
            return 1;
        }
    }
    return 0;
}

void addVisitedVertex(int vertex) {
    if(isVertexVisited(vertex)) {
        return;
    } else {
        visitedIterator += 1;
        //printf("visited Iterator = %d\n", visitedIterator);
        visitedVertices[visitedIterator] = vertex;
        return;
    }
}

Edge findNextGreaterEdge(Edge current) {
    int i,j;
    Edge newEdge;
    //printf("current cost = %d\n", current.cost);
    for(i=0; i<n; ++i) {
        for(j=0; j<n; ++j) {
            if(a[i][j] > current.cost && (!isVertexVisited(i) || !isVertexVisited(j))) {
                newEdge.v1 = i;
                newEdge.v2 = j;
                newEdge.cost = a[i][j];
                //printf("\n%d\n",isVertexVisited(i));
                //printf("\n%d\n",isVertexVisited(j));
                //printf("\ncost = %d\n", newEdge.cost);
                return newEdge;
            }
        }
    }
    return current;
}

void kruskals() {
    Edge current;
    int totalCost = 0;
    current.v1 = 0;
    current.v2 = 0;
    current.cost = a[0][0];
    printf("\nKruskal's MST:\nV1\tV2\tCost\n");
    while(visitedIterator != n-1) {
    current = findNextGreaterEdge(current);
    addVisitedVertex(current.v1);
    addVisitedVertex(current.v2);
    printf("%d\t%d\t%d\n", current.v1, current.v2, current.cost);
    totalCost += current.cost;
    }
    printf("\nTotal cost = %d\n", totalCost);
}

int main()
{
    /*
    Test Matrix:
        0 1 2 0
        1 0 3 4
        2 3 0 5
        0 4 5 0
    */
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix: \n");
    for(i=0; i<n; ++i) {
        for(j=0; j<n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    kruskals();

    return 0;
}
