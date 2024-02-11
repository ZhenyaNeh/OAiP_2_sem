#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

HANDLE hColor = GetStdHandle(STD_OUTPUT_HANDLE);

struct HeapNode
{
    int value;

    HeapNode(int v) : value(v) {}
};

struct BinaryHeap
{
    vector<HeapNode> nodes;

    void push(int value) 
    {
        nodes.emplace_back(value);
        siftUp(nodes.size() - 1);
    }

    HeapNode pop() 
    {
        HeapNode node = nodes[0];
        nodes[0] = nodes.back();
        nodes.pop_back();
        siftDown(0);
        return node;
    }

    HeapNode top() 
    {
        return nodes[0];
    }

    HeapNode dellIndex(int i)
    {
        HeapNode node = nodes[i];
        nodes[i] = -9999;
        siftUp(i);
        pop();
        return node;
    }

    int maxValue()
    {
        int maxValueIndex{0};
        for (int i = 1; i < nodes.size() - 1; i++)
        {
            if (nodes[maxValueIndex].value < nodes[i].value)
                maxValueIndex = i;
        }
        return maxValueIndex;
    }

    /*void printInString()
    {
        cout << "<--------------HEAP-------------->\n";
        for (int i = 0; i < nodes.size(); i++)
        {
            cout << nodes[i].value << "\n";
        }
        cout << "<--------------HEAP-------------->\n\n";
    }*/

    void print(int index, int indent = 0) 
    {
        if (index >= nodes.size()) 
        {
            return;
        }
        print(2 * index + 2, indent + 4);
        cout << "| " << string(indent, ' ') << nodes[index].value << endl;
        print(2 * index + 1, indent + 4);
    }

private:
    void siftUp(int i) 
    {
        while (i > 0) 
        {
            int par = parent(i);
            if (nodes[par].value > nodes[i].value) 
            {
                swap(nodes[par], nodes[i]);
                i = par;
            }
            else 
            {
                break;
            }
        }
    }

    void siftDown(int i) 
    {
        int minIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < nodes.size() && nodes[left].value < nodes[minIndex].value)
        {
            minIndex = left;
        }
        if (right < nodes.size() && nodes[right].value < nodes[minIndex].value)
        {
            minIndex = right;
        }
        if (i != minIndex)
        {
            swap(nodes[i], nodes[minIndex]);
            siftDown(minIndex);
        }
    }

    static int parent(int i)
    {
        return (i - 1) / 2;
    }

    static int leftChild(int i)
    {
        return 2 * i + 1;
    }

    static int rightChild(int i) 
    {
        return 2 * i + 2;
    }
};

BinaryHeap unionH(BinaryHeap& heap1, BinaryHeap& heap2) {
    BinaryHeap unionHeap;

    for (int i = 0; i < heap1.nodes.size(); i++) 
        unionHeap.push(heap1.nodes[i].value);
    

    for (int i = 0; i < heap2.nodes.size(); i++) 
        unionHeap.push(heap2.nodes[i].value);
    

    return unionHeap;
}

int main() {
    BinaryHeap heap1, heap2, unionHeap;

    heap1.push(10);
    heap1.push(30);
    heap1.push(20);
    heap1.push(5);
    heap1.push(8);
    heap2.push(1);
    heap2.push(8);
    heap2.push(2);
    heap2.push(4);

    SetConsoleTextAttribute(hColor, 14);
    cout << "/////////////////////DELETE_MIN_VALUE/////////////////////\n";
    cout << "<--------------HEAP1-------------->\n";
    heap1.print(0);
    cout << "<--------------HEAP-------------->\n\n";
    
    cout << "Min delete value: " << heap1.pop().value << "\n";

    cout << "<--------------HEAP1_AFTER_DEL_MIN-------------->\n";
    heap1.print(0);
    cout << "<--------------HEAP-------------->\n\n\n";

    SetConsoleTextAttribute(hColor, 11);
    cout << "\n/////////////////////DELETE_INDEX_VALUE/////////////////////\n";
    cout << "<--------------HEAP2-------------->\n";
    heap2.print(0);
    cout << "<--------------HEAP-------------->\n\n";

    cout << "Index delete value: " << heap2.dellIndex(2).value << "\n";

    cout << "<--------------HEAP2_AFTER_DEL_INDEX-------------->\n";
    heap2.print(0);
    cout << "<--------------HEAP-------------->\n\n\n";

    SetConsoleTextAttribute(hColor, 12);
    cout << "\n/////////////////////UNION_TWO_HEAP/////////////////////\n";
    unionHeap = unionH(heap1, heap2);

    cout << "<--------------UNION_HEAP-------------->\n";
    unionHeap.print(0);
    cout << "<--------------HEAP-------------->\n\n";

    int maxValInd = unionHeap.maxValue();
    cout << "Index delete MAX value: " << unionHeap.dellIndex(maxValInd).value << "\n";

    cout << "<--------------UNION_HEAP_AFTER_DEL_MAX_VALUE-------------->\n";
    unionHeap.print(0);
    cout << "<--------------HEAP-------------->\n\n";
    SetConsoleTextAttribute(hColor, 7);
}