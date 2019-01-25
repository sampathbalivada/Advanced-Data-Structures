/*
* Breadth First Search Algorithm - C iterative Implementation using Arrays
* Author - github.com/sampathbalivada
*/

#include<stdio.h>
#include<stdlib.h>
#define n 4

int a[n][n], visited[n], queue[n*n], iterator = -1;

void bfs(int i) {
    int j;
	printf("%d\t", i);
	visited[i] = 1;
	//enqueue the value in i
    iterator++;
    queue[iterator] = i;

    while(iterator != -1) {
        //dequeue and store value in i
        i = queue[iterator];
        iterator--;

        for(j=0; j<n; ++j){
            if(visited[j]==0 && a[i][j]!=0) {
                printf("%d\t", j);
                visited[j] = 1;
                iterator++;
                queue[iterator] = j;
            }
        }
    }
}

int main() {
	int i, j, start;
	printf("Enter the adjacency matrix: \n");
	for(i=0; i<n; ++i) {
		for(j=0; j<n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	printf("Enter the starting vertex: ");
	scanf("%d", &start);
	for(i=0; i<n; ++i) {
		visited[i] = 0;
	}
	printf("Starting vertex: %d\n", start);
	printf("Visited vertices: ");
	bfs(start);
	return 0;
}
