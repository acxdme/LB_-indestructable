
// Constructor to initialize data
// members and creating mean heap
// MinHeap::MinHeap(int size, int input[])
// Assume this working fine working fine

void firstKthElement(int arr[], int size, int k) {
    MinHeap* m = new MinHeap(k, arr);
    for (int i = k; i < size; i++) {
        if (arr[0] > arr[i])
            continue;
        else {
            arr[0] = arr[i];
            m->heapify(0);
        }
    }
}
