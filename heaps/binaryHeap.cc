#include<bits/stdc++.h>
using namespace std;


class MinHeap
{
    int *harr; // pointer to array of elements in heap.
    int capacity; // maximum possible size of min heap.
    int heap_size; // current number of elements in min heap.

public:
    // constructor
    MinHeap(int capacity);

    void MinHeapify(int );

    int parent(int i) { return (i-1)/2;}

    // to get the index of left child of node at index i.
    int left(int i) { return (2 * i + 1); }

    // to get index of right child of node at index i.
    int right(int i) { return (2 * i + 2); }

    // to extract the root which is the minimum element.
    int extractMin();

    // decrease key value of key at index i to new_val.
    void decreaseKey(int i, int new_val);

    // returns the minimum key (key at root) from min heap.
    int getMin() { return harr[0]; }

    // deletes a key stored at index i.
    void delelteKey(int i);

    // inserts a new key 'k'
    void insertKey(int k);
};

// Constructor:
MinHeap::MinHeap(int capacity) {
    heap_size = 0;
    capacity = capacity;
    harr = new int[capacity];
}

// inserts a new key 'k'
void MinHeap::insertKey(int k) {
    if(heap_size == capacity) {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
    // first insert the key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    // fix the min heap property if it is violated
    while(i != 0 && harr[parent[i]] > harr[i]) {
        swap(&harr[i], &harr[parent[i]]);
        i = parent[i];
    }
}

// decreases value of key at index 'i' to new_val. It is assumed that
// new_val is smaller than harr[i]
void MinHeap::decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while(i != 0 and harr[parent[i]] > harr[i]) {
        swap(&harr[i], &harr[parent[i]]);
        i = parent[i];
    }
}

// method to remove minimum element (or root) from min heap
int MinHeap::extractMin() {
    if(heap_size <= 0){
        return INT_MAX;
    }
    if(heap_size == 1){
        heap_size--;
        return harr[0];
    }

    // store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);

    return root;
}

// this function deletes key at index i, It first reduced value to infinite,
// then calls extractMin()
void MinHeap::delelteKey(int i) {
    decreaseKey(i, INT_MIN);
    extractMin();
}

// a recursive method to heapify a subtree with the root at given index.
// this method assumes that the subtrees are already hepified.
void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l < heap_size and harr[l] < harr[r]) {
        smallest = l;
    }
    if(r < heap_size and harr[r] < harr[smallest]) {
        smallest = r;
    } 
    if(smallest != i) {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

// a utility function to swap two elements
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.delelteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);

    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}
