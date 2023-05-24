#include <iostream>
#include <vector>

using namespace std;

class Heap {
public:
    int hp[100];
    int size;
    Heap() {
        this->size = 0;
    }

    void insert(int data) {

        hp[++size] = data;

        int indx = size;
        while (indx > 1) {
            int parent = indx / 2;
            if (hp[parent] < hp[indx]) {
                swap(hp[parent], hp[indx]);
                indx = parent;
            }
            else {
                return;
            }
        }

    }

    void deleteNode() {

        //step-1 
        hp[1] = hp[size];
        size--;

        //step-2
        int index = 1;

        while (index < size) {
            int largest = index;
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;
            if (leftIndex < size && hp[largest] < hp[leftIndex]) {
                largest = leftIndex;
            }
            if (rightIndex < size && hp[largest] < hp[rightIndex]) {
                largest = rightIndex;
            }
            if (largest == index) {
                return;
            }

            index = largest;

        }

    }
};
int main()
{

    Heap h;
    // h.hp[0] = -1;
    // h.hp[1] = 10;
    // h.hp[2] = 8;
    // h.hp[3] = 7;
    // h.size = 4;
    h.insert(50);
    h.insert(30);
    h.insert(70);
    h.insert(40);
    h.insert(80);
    h.insert(100);

    cout << "Heap before insertion" << endl;

    for (int it = 1; it < h.size; it++) {
        cout << h.hp[it] << " ";
    }cout << endl;
    h.insert(11);


    cout << "Heap after insertion" << endl;

    for (int it = 1; it < h.size; it++) {
        cout << h.hp[it] << " ";
    }cout << endl;

    h.deleteNode();

    cout << "Heap after deletion" << endl;

    for (int it = 1; it < h.size; it++) {
        cout << h.hp[it] << " ";
    }cout << endl;

    return 0;

}
