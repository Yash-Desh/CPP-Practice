// DLL Practice - Implement all functions below
// Compile: g++ -o dll_practice dll_practice.cpp

#include <bits/stdc++.h>
using namespace std;

class Node {
    
};

// ========== Implement these functions ==========

void printForward(Node* head)
{
    // TODO: Print all node values from head to tail
}

void printBackward(Node* tail)
{
    // TODO: Print all node values from tail to head
}

int getLength(Node* head)
{
    // TODO: Return count of nodes in the list
    return -1;
}

void insertAtHead(Node*& head, Node*& tail, int x)
{
    // TODO: Insert node with value x at the beginning
    // Handle: empty list, non-empty list
}

void insertAtTail(Node*& head, Node*& tail, int x)
{
    // TODO: Insert node with value x at the end
    // Handle: empty list, non-empty list
}

void insertAtPostion(Node*& head, Node*& tail, int index, int x)
{
    // TODO: Insert node with value x at 0-based index
    // Handle: beginning (index 0), middle, end
}

void deleteNode(Node*& head, Node*& tail, int index)
{
    // TODO: Delete node at 0-based index
    // Handle: head (index 0), middle, tail
}

// ========== Testing Harness (do not modify) ==========

int main()
{
    int passed = 0, failed = 0;
    auto ASSERT = [&](bool cond, const string& name) {
        if(cond) { passed++; cout << "  PASS: " << name << endl; }
        else     { failed++; cout << "  FAIL: " << name << endl; }
    };

    auto toVec = [](Node* h) {
        vector<int> v;
        while(h) { v.push_back(h->data); h = h->next; }
        return v;
    };

    auto isConsistent = [&](Node* h, Node* t) {
        vector<int> fwd = toVec(h);
        vector<int> bwd;
        while(t) { bwd.push_back(t->data); t = t->prev; }
        reverse(bwd.begin(), bwd.end());
        return fwd == bwd;
    };

    // --- Test 1: Insert at head into empty list ---
    {
        Node *h = NULL, *t = NULL;
        insertAtHead(h, t, 10);
        ASSERT(toVec(h) == vector<int>{10}, "insertAtHead empty list");
        ASSERT(h == t, "single node: head == tail");
        delete h;
    }

    // --- Test 2: Insert at head multiple ---
    {
        Node *h = NULL, *t = NULL;
        insertAtHead(h, t, 3);
        insertAtHead(h, t, 2);
        insertAtHead(h, t, 1);
        ASSERT(toVec(h) == (vector<int>{1,2,3}), "insertAtHead x3");
        ASSERT(isConsistent(h, t), "head inserts consistent");
        delete h;
    }

    // --- Test 3: Insert at tail ---
    {
        Node *h = NULL, *t = NULL;
        insertAtTail(h, t, 1);
        insertAtTail(h, t, 2);
        insertAtTail(h, t, 3);
        ASSERT(toVec(h) == (vector<int>{1,2,3}), "insertAtTail x3");
        ASSERT(t->data == 3, "tail points to last");
        ASSERT(isConsistent(h, t), "tail inserts consistent");
        delete h;
    }

    // --- Test 4: Insert at position (beginning, middle, end) ---
    {
        Node *h = NULL, *t = NULL;
        insertAtPostion(h, t, 0, 10);
        insertAtPostion(h, t, 0, 5);
        insertAtPostion(h, t, 2, 20);
        insertAtPostion(h, t, 1, 7);
        ASSERT(toVec(h) == (vector<int>{5,7,10,20}), "insertAtPosition mixed");
        ASSERT(h->data == 5, "head correct after pos inserts");
        ASSERT(t->data == 20, "tail correct after pos inserts");
        ASSERT(isConsistent(h, t), "position inserts consistent");
        delete h;
    }

    // --- Test 5: Delete head ---
    {
        Node *h = NULL, *t = NULL;
        insertAtTail(h, t, 1);
        insertAtTail(h, t, 2);
        insertAtTail(h, t, 3);
        deleteNode(h, t, 0);
        ASSERT(toVec(h) == (vector<int>{2,3}), "delete head");
        ASSERT(h->prev == NULL, "new head prev is NULL");
        ASSERT(isConsistent(h, t), "consistent after head delete");
        delete h;
    }

    // --- Test 6: Delete tail ---
    {
        Node *h = NULL, *t = NULL;
        insertAtTail(h, t, 1);
        insertAtTail(h, t, 2);
        insertAtTail(h, t, 3);
        deleteNode(h, t, 2);
        ASSERT(toVec(h) == (vector<int>{1,2}), "delete tail");
        ASSERT(t->data == 2, "tail updated after tail delete");
        ASSERT(isConsistent(h, t), "consistent after tail delete");
        delete h;
    }

    // --- Test 7: Delete middle ---
    {
        Node *h = NULL, *t = NULL;
        insertAtTail(h, t, 1);
        insertAtTail(h, t, 2);
        insertAtTail(h, t, 3);
        insertAtTail(h, t, 4);
        deleteNode(h, t, 2);
        ASSERT(toVec(h) == (vector<int>{1,2,4}), "delete middle");
        ASSERT(isConsistent(h, t), "consistent after middle delete");
        delete h;
    }

    // --- Test 8: getLength ---
    {
        Node *h = NULL, *t = NULL;
        ASSERT(getLength(h) == 0, "length of empty list");
        insertAtTail(h, t, 1);
        insertAtTail(h, t, 2);
        insertAtTail(h, t, 3);
        ASSERT(getLength(h) == 3, "length of 3-node list");
        delete h;
    }

    // --- Test 9: Full scenario ---
    {
        Node *h = NULL, *t = NULL;
        insertAtTail(h, t, 10);
        insertAtHead(h, t, 55);
        insertAtHead(h, t, 12);
        insertAtHead(h, t, 78);
        ASSERT(toVec(h) == (vector<int>{78,12,55,10}), "full scenario step 1");

        insertAtTail(h, t, 25);
        insertAtPostion(h, t, 0, 79);
        insertAtPostion(h, t, 4, 85);
        insertAtPostion(h, t, 7, 37);
        ASSERT(toVec(h) == (vector<int>{79,78,12,55,85,10,25,37}), "full scenario step 2");
        ASSERT(t->data == 37, "tail is 37");

        deleteNode(h, t, 7);
        ASSERT(toVec(h) == (vector<int>{79,78,12,55,85,10,25}), "after delete tail");
        ASSERT(t->data == 25, "tail updated to 25");

        deleteNode(h, t, 2);
        ASSERT(toVec(h) == (vector<int>{79,78,55,85,10,25}), "after delete middle");
        ASSERT(isConsistent(h, t), "full scenario consistent");
        delete h;
    }

    // --- Results ---
    cout << "\n===== Results =====" << endl;
    cout << "Passed: " << passed << "/" << passed + failed << endl;
    if(failed) cout << "FAILED: " << failed << " test(s)" << endl;
    else       cout << "All tests passed!" << endl;

    return failed ? 1 : 0;
}
