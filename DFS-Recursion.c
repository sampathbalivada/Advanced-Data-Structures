/*
* Depth First Search Algorithm - C recursive Implementation using Arrays
* Author - github.com/sampathbalivada
*/

#include<stdio.h>
#include<stdlib.h>
#define n 4

int a[n][n], visited[n];

//Recusive function
void dfs(int i) {
	int j;
	printf(" %d", i);
	visited[i] = 1;

	for(j=0; j<n; ++j) {
		if(visited[j]==0 && a[i][j]!=0) {
			dfs(j);
		}
	}
}

int main() {
	int i, j, start;
	printf("Enter the adjacency matrix: ");
	for(i=0; i<n; ++i) {
		for(j=0; j<n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	printf("Enter the starting vertex: ");
	scanf("%d", &start);
	printf("Starting vertex: %d\n", start);
	printf("Visited vertices:");
	dfs(start);
  printf(".");
	return 0;
}
