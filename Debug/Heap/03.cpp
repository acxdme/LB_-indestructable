// merge k sorted array debugging

// For reference
// struct MinHeapNode {
//     // The element to be stored
//     int element;
//     // index of the array from which the element is taken
//     int i;
//     // index of the next element to be picked from the array
//     int j;
// };

int* mergeKArrays(int arr[][N], int K) {
    int* output = new int[N * K];
    MinHeapNode* harr = new MinHeapNode[K];
    for (int i = 0; i < K; i++) {
        harr[i].element = arr[i][0];
        harr[i].i = i;
        harr[i].j = 1;
    }
    MinHeap hp(harr, K);
    for (int count = 0; count < N * K; count++) {
        MinHeapNode root = hp.getMin();
        output[count] = root.element;
        if (root.j < N) {
            root.element = arr[root.i][root.j];
            root.j += 1;
        }
        else
            root.element = INT_MAX;
        hp.replaceMin(root);
    }
    return output;
}
