// CSLL Practice - Implement all functions below
// Compile: g++ -o csll_practice 102_CSLL_practice_template.cpp

// Note: CSLL uses only a tail pointer (no head needed).
//       tail->next always points to the "head" (first node).

#include <bits/stdc++.h>
using namespace std;

class Node {
    // TODO: Define data and next pointer, and a constructor
public: 
    int data; 
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// ========== Implement these functions ==========

void insertAfterValue(Node*& tail, int element, int x)
{
    // TODO: Insert node with value x right after the node containing 'element'
    // Handle: empty list, element not found, element is tail
    // If element is tail, update tail to new node? No — only if you want tail insert.
    //   Actually: just insert after. If element == tail, the new node sits between
    //   old tail and head, so new node becomes the new tail. Update tail.
    Node* temp = new Node(x);
    if(tail == nullptr) {
        tail = temp;
        tail->next = tail;
    }
    else {
        Node* curr = tail;
        do{
            if(curr->data == element) {
                break;
            }
            curr = curr->next;
        }
        while(curr != tail);

        if(curr->data != element) {
            cout << "Elemenet Not Found";
            return;
        }
        if(curr == tail) {
            tail = temp;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteByValue(Node*& tail, int val)
{
    // TODO: Delete the first node with value val
    // Handle: empty list, single node, deleting head, deleting tail, deleting middle
    if(tail == nullptr) {
        return;
    }
    if(tail->next == tail) {
        if(tail->data != val) { return; }
        Node* temp = tail;
        tail = nullptr;
        delete temp;
        return;
    }
    Node* prev = tail;
    Node* curr = tail->next;
    do {
        if(curr->data == val) {
            break;
        }
        prev = curr;
        curr = curr->next;
    }while(curr != tail->next);

    if(curr->data != val) {
        return;
    }
    if(curr == tail) {
        tail = prev;
    }
    prev->next = curr->next;
    curr->next = nullptr;
    delete curr;
}

int getLength(Node* tail)
{
    // TODO: Return the number of nodes in the list
    // Handle: empty list
    int count = 0;
    if(tail == nullptr) {
        return 0;
    }
    else {
        Node* ptr = tail;
        do{
            count++;
            ptr = ptr->next;
        }while(ptr != tail);
    }
    return count;
}

bool search(Node* tail, int val)
{
    // TODO: Return true if val exists in the list, false otherwise
    // Handle: empty list
    if(tail == nullptr) {
        return false;
    }
    Node* ptr = tail;
    do {
        if(ptr->data == val) {
            break;
        }
        ptr = ptr->next;
    }while(ptr != tail);

    return ptr->data == val;
}

// ========== Testing Harness (do not modify below this line) ==========

// Helper: collect CSLL values starting from head (tail->next) into a vector
vector<int> toVec(Node* tail)
{
    if(!tail) return {};
    vector<int> v;
    Node* cur = tail->next; // head
    do {
        v.push_back(cur->data);
        cur = cur->next;
    } while(cur != tail->next);
    return v;
}

// Helper: verify the list is actually circular
bool isCircular(Node* tail)
{
    if(!tail) return true; // empty is trivially ok
    Node* cur = tail->next; // head
    int safety = 10000;
    do {
        cur = cur->next;
        if(--safety <= 0) return false; // infinite loop / broken
    } while(cur != tail->next);
    return true;
}

// Helper: verify tail->next is head (basic structural check)
bool tailPointsToHead(Node* tail)
{
    if(!tail) return true;
    // Walk from tail->next all the way around, last before coming back should be tail
    Node* cur = tail->next;
    while(cur->next != tail->next)
    {
        cur = cur->next;
    }
    return cur == tail;
}

int main()
{
    int passed = 0, failed = 0;
    auto ASSERT = [&](bool cond, const string& name) {
        if(cond) { passed++; cout << "  PASS: " << name << endl; }
        else     { failed++; cout << "  FAIL: " << name << endl; }
    };

    // ==========================================
    //   TEST GROUP 1: insertAfterValue
    // ==========================================
    cout << "\n--- insertAfterValue ---" << endl;
    {
        // Insert into empty list (element is ignored, just insert)
        Node* tail = NULL;
        insertAfterValue(tail, 99, 10);
        ASSERT(tail != NULL, "insertAfterValue into empty: tail not NULL");
        ASSERT(toVec(tail) == vector<int>{10}, "insertAfterValue into empty: values");
        ASSERT(tail->next == tail, "single node points to itself");
        ASSERT(isCircular(tail), "circular after insertAfterValue empty");
    }
    {
        // Build list by appending after tail each time
        Node* tail = NULL;
        insertAfterValue(tail, 99, 10);
        insertAfterValue(tail, 10, 20);
        insertAfterValue(tail, 20, 30);
        ASSERT(toVec(tail) == (vector<int>{10,20,30}), "build list by appending");
        ASSERT(tail->data == 30, "tail is last appended");
        ASSERT(tail->next->data == 10, "head is first inserted");
        ASSERT(isCircular(tail), "circular after 3 appends");
        ASSERT(tailPointsToHead(tail), "tail->next is head");
    }
    {
        // Insert in the middle: insert 25 after 20
        Node* tail = NULL;
        insertAfterValue(tail, 99, 10);
        insertAfterValue(tail, 10, 20);
        insertAfterValue(tail, 20, 30);
        insertAfterValue(tail, 20, 25);
        ASSERT(toVec(tail) == (vector<int>{10,20,25,30}), "insert 25 after 20");
        ASSERT(tail->data == 30, "tail unchanged when inserting in middle");
        ASSERT(isCircular(tail), "circular after mid insert");
    }
    {
        // Insert after tail node -> new node becomes tail
        Node* tail = NULL;
        insertAfterValue(tail, 99, 10);
        insertAfterValue(tail, 10, 20);
        insertAfterValue(tail, 20, 30);
        ASSERT(toVec(tail) == (vector<int>{10,20,30}), "insert after tail value");
        ASSERT(tail->data == 30, "tail updated to new node");
        ASSERT(tail->next->data == 10, "head still correct");
        ASSERT(isCircular(tail), "circular after tail-value insert");
    }
    {
        // Insert after head node
        Node* tail = NULL;
        insertAfterValue(tail, 99, 10);
        insertAfterValue(tail, 10, 30);
        insertAfterValue(tail, 10, 20);
        ASSERT(toVec(tail) == (vector<int>{10,20,30}), "insert after head value");
        ASSERT(isCircular(tail), "circular after head-value insert");
    }

    // ==========================================
    //   TEST GROUP 2: deleteByValue
    // ==========================================
    cout << "\n--- deleteByValue ---" << endl;
    {
        // Delete from single-node list
        Node* tail = NULL;
        insertAfterValue(tail, 99, 10);
        deleteByValue(tail, 10);
        ASSERT(tail == NULL, "delete single node: tail is NULL");
    }
    {
        // Delete head node
        Node* tail = NULL;
        insertAfterValue(tail, 99, 10);
        insertAfterValue(tail, 10, 20);
        insertAfterValue(tail, 20, 30);
        deleteByValue(tail, 10);
        ASSERT(toVec(tail) == (vector<int>{20,30}), "delete head value");
        ASSERT(tail->data == 30, "tail unchanged after head delete");
        ASSERT(tail->next->data == 20, "new head is 20");
        ASSERT(isCircular(tail), "circular after head delete");
        ASSERT(tailPointsToHead(tail), "tail->next is head after delete");
    }
    {
        // Delete tail node
        Node* tail = NULL;
        insertAfterValue(tail, 99, 10);
        insertAfterValue(tail, 10, 20);
        insertAfterValue(tail, 20, 30);
        deleteByValue(tail, 30);
        ASSERT(toVec(tail) == (vector<int>{10,20}), "delete tail value");
        ASSERT(tail->data == 20, "tail updated after tail delete");
        ASSERT(tail->next->data == 10, "head still 10");
        ASSERT(isCircular(tail), "circular after tail delete");
    }
    {
        // Delete middle node
        Node* tail = NULL;
        insertAfterValue(tail, 99, 10);
        insertAfterValue(tail, 10, 20);
        insertAfterValue(tail, 20, 30);
        insertAfterValue(tail, 30, 40);
        deleteByValue(tail, 20);
        ASSERT(toVec(tail) == (vector<int>{10,30,40}), "delete middle value");
        ASSERT(isCircular(tail), "circular after middle delete");
        ASSERT(tailPointsToHead(tail), "structure ok after middle delete");
    }

    // ==========================================
    //   TEST GROUP 3: getLength
    // ==========================================
    cout << "\n--- getLength ---" << endl;
    {
        Node* tail = NULL;
        ASSERT(getLength(tail) == 0, "length of empty list");
    }
    {
        Node* tail = NULL;
        insertAfterValue(tail, 99, 10);
        ASSERT(getLength(tail) == 1, "length of 1-node list");
    }
    {
        Node* tail = NULL;
        insertAfterValue(tail, 99, 10);
        insertAfterValue(tail, 10, 20);
        insertAfterValue(tail, 20, 30);
        insertAfterValue(tail, 30, 40);
        insertAfterValue(tail, 40, 50);
        ASSERT(getLength(tail) == 5, "length of 5-node list");
    }

    // ==========================================
    //   TEST GROUP 4: search
    // ==========================================
    cout << "\n--- search ---" << endl;
    {
        Node* tail = NULL;
        ASSERT(search(tail, 10) == false, "search in empty list");
    }
    {
        Node* tail = NULL;
        insertAfterValue(tail, 99, 10);
        insertAfterValue(tail, 10, 20);
        insertAfterValue(tail, 20, 30);
        ASSERT(search(tail, 10) == true, "search head value");
        ASSERT(search(tail, 30) == true, "search tail value");
        ASSERT(search(tail, 20) == true, "search middle value");
        ASSERT(search(tail, 99) == false, "search missing value");
    }

    // ==========================================
    //   TEST GROUP 5: Full integration scenario
    // ==========================================
    cout << "\n--- Full scenario ---" << endl;
    {
        Node* tail = NULL;

        // Build list: 10 -> 20 -> 30
        insertAfterValue(tail, 99, 10);
        insertAfterValue(tail, 10, 20);
        insertAfterValue(tail, 20, 30);
        ASSERT(toVec(tail) == (vector<int>{10,20,30}), "step1: build list");

        insertAfterValue(tail, 10, 15);
        ASSERT(toVec(tail) == (vector<int>{10,15,20,30}), "step2: insert 15 after 10");

        insertAfterValue(tail, 30, 35);
        ASSERT(toVec(tail) == (vector<int>{10,15,20,30,35}), "step3: insert 35 after tail");
        ASSERT(tail->data == 35, "tail updated to 35");

        ASSERT(getLength(tail) == 5, "step4: length is 5");
        ASSERT(search(tail, 15) == true, "step4: 15 found");
        ASSERT(search(tail, 99) == false, "step4: 99 not found");

        deleteByValue(tail, 10);
        ASSERT(toVec(tail) == (vector<int>{15,20,30,35}), "step5: delete head 10");
        ASSERT(tail->next->data == 15, "new head is 15");

        deleteByValue(tail, 35);
        ASSERT(toVec(tail) == (vector<int>{15,20,30}), "step6: delete tail 35");
        ASSERT(tail->data == 30, "tail updated to 30");

        deleteByValue(tail, 20);
        ASSERT(toVec(tail) == (vector<int>{15,30}), "step7: delete middle 20");

        ASSERT(getLength(tail) == 2, "step8: length is 2");
        ASSERT(isCircular(tail), "final: still circular");
        ASSERT(tailPointsToHead(tail), "final: tail->next is head");
    }

    // --- Results ---
    cout << "\n===== Results =====" << endl;
    cout << "Passed: " << passed << "/" << passed + failed << endl;
    if(failed) cout << "FAILED: " << failed << " test(s)" << endl;
    else       cout << "All tests passed!" << endl;

    return failed ? 1 : 0;
}
