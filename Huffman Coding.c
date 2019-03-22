/* WIP */
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

void insert_value(int value) {
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

int delete_min() {
    int temp_size;
    int min_value = heap[0];
    heap[0] = heap[heap_size - 1];
    heap_size--;
    temp_size = heap_size - 1;
    while(temp_size > 0) {
        min_heapify(temp_size);
        temp_size--;
    }
    return min_value;
}

int main() {
    int add_value = 1;
    int sum;
    int value;
    int v1, v2;
    printf("Add values into Heap: ");
    while(add_value) {
        printf("\nEnter a value: ");
        scanf("%d", &value);
        insert_value(value);
        printf("\nDo you want to add another value? 1/0: ");
        scanf("%d", &add_value);
    }
    display_heap();
    printf("\n\nHuffman Coding: ");
    while(heap_size != 1) {
        v1 = delete_min();
        v2 = delete_min();
        sum =  v1 + v2;
        insert_value(sum);
        display_heap();
    }
    printf("\n\nThe optimal cost is %d\n", heap[0]);
    return 0;
}
