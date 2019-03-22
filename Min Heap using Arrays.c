/*
* Min Heap Implementation using Arrays
* author - github.com/sampathbalivada
* Note: currently demonstrates insertion only
*/
#include<stdio.h>
#include<stdlib.h>

int heap[100], heap_size = 0;

void min_heapify(int location) {
    int parent = (location-1)/2;
    int temp;
    if(parent >= 0) {
        if(heap[location] < heap[parent]) {
            temp = heap[location];
            heap[location] = heap[parent];
            heap[parent] = temp;
            min_heapify(parent);
        }
    }
}

void insert_value() {
    int value;
    printf("\nEnter a value: ");
    scanf("%d", &value);
    heap[heap_size] = value;
    min_heapify(heap_size);
    heap_size++;
}

void display_heap() {
    printf("\nThe Min Heap is");
    for(int i=0; i < heap_size; ++i) {
        printf(" %d", heap[i]);
    }
    printf(".");
}

int main() {
    int add_value = 1;
    int input;
    printf("Add values into Heap: ");
    while(add_value) {
        insert_value();
        printf("\nDo you want to add another value? 1/0: ");
        scanf("%d", &add_value);
    }
    display_heap();
    return 0;
}
