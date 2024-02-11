#include <iostream>
#include <vector>

using namespace std;

struct BinaryHeap {
    vector<int> nodes;

    void push(int value) {
        nodes.push_back(value);
        siftUp(nodes.size() - 1);
    }

    int pop() {
        int value = nodes[0];
        nodes[0] = nodes.back();
        nodes.pop_back();
        siftDown(0);
        return value;
    }

    void siftUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (nodes[parentIndex] > nodes[index]) {
                swap(nodes[parentIndex], nodes[index]);
                index = parentIndex;
            }
            else {
                break;
            }
        }
    }

    void siftDown(int index) {
        while (2 * index + 1 < nodes.size()) {
            int leftChildIndex = 2 * index + 1;
            int rightChildIndex = 2 * index + 2;
            int minIndex = index;
            if (nodes[minIndex] > nodes[leftChildIndex]) {
                minIndex = leftChildIndex;
            }
            if (rightChildIndex < nodes.size() && nodes[minIndex] > nodes[rightChildIndex]) {
                minIndex = rightChildIndex;
            }
            if (minIndex != index) {
                swap(nodes[minIndex], nodes[index]);
                index = minIndex;
            }
            else {
                break;
            }
        }
    }
};

int main() {
    BinaryHeap heap;
    heap.push(5);
    heap.push(3);
    heap.push(7);
    heap.push(1);
    heap.push(8);
    heap.push(2);
    heap.push(4);

    int minElement = heap.pop();
    cout << "Min element: " << minElement << endl;

    return 0;
}