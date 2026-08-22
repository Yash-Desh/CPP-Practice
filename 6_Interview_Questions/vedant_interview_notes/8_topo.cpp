// Author: Yash Deshpande
// Date  : 18-08-2026
// Interviwee: Vedant Paranjpe
// Interviewer: Ashok Ayyamani (Apple)
// Link  : https://gist.github.com/VedantParanjape/b6c5ee1cf6953a8e1ec0f5f9d95ed163

// Imagine we have a small runtime system that executes computation nodes. Each node represents an procedure that produces certain tensors and depends on some other tensors produced by earlier nodes.
// You’re given a list of these nodes, where each node specifies:
// * Its name
// * Which tensors it needs as input
// * Which tensors it outputs
// Your task is to determine a valid sequence of execution that respects dependencies — i.e., an procedure can only run once all of its input tensors are available.
// If no such order exists, it means there’s a circular dependency somewhere.
// ops = [
//     {"name": "E", "inputs": ["t3", "t4"], "outputs": ["t5"]}
//     {"name": "A", "inputs": [], "outputs": ["t1"]},
//     {"name": "B", "inputs": ["t1"], "outputs": ["t2"]},
//     {"name": "C", "inputs": ["t2"], "outputs": ["t3"]},
//     {"name": "D", "inputs": ["t1"], "outputs": ["t4"]},
// ]

#include <type_traits>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct Node_ {
  std::string name;
  std::vector<int> inputs;
  std::vector<int> output;
}Node;

std::vector<int> getValidOrdering(std::vector<Node*> ops) {
  map<int, vector<int>> table;
  map<int, int> inorder;

  vector<int> ret;

  for (Node *op: ops) {
    for (int ot: op->output)
      for (int inp: op->inputs) {
        table[ot].push_back(inp);
        inorder[inp]++;
      }
  }

  queue<int> q;
  for (auto elem: inorder) {
    if (elem.second == 0) {
      q.push(elem.first);
    }
  }

  while (!q.empty()) {
    int top = q.front();
    q.pop();

    for (int child: table[top]) {
      inorder[child]--;
      if (inorder[child] == 0)
        q.push(child);
    }
    ret.push_back(top);
  }

  bool valid = std::all_of(inorder.begin(), inorder.end(), [](auto &a) {return a.second == 0;});
  return valid ? ret : {};
}

int main() {
  
}

/*

Can we think in this way. Each output from                                            
  // ops = [                                                                            
  //     {"name": "E", "inputs": ["t3", "t4"], "outputs": ["t5"]}                       
  //     {"name": "A", "inputs": [], "outputs": ["t1"]},                                
  //     {"name": "B", "inputs": ["t1"], "outputs": ["t2"]},                            
  //     {"name": "C", "inputs": ["t2"], "outputs": ["t3"]},                            
  //     {"name": "D", "inputs": ["t1"], "outputs": ["t4"]},                            
  // ]                                                                                  
  has an incoming dependency from the inputs in the grap ?   

  Yes — that's exactly the forward convention, and it's the cleaner of the two.

  "t5 has an incoming dependency from t3 and t4" means the edges point input → output,
  and the in-degree of a tensor is the number of prerequisites it's waiting on. That
  maps directly onto the intuition: in-degree 0 means "nothing left to wait for, ready
  to produce."

  Reading your op list under that rule:

  A: [] -> t1          t1 has no incoming edges       indeg(t1) = 0
  B: t1 -> t2          t1 -> t2                       indeg(t2) = 1
  C: t2 -> t3          t2 -> t3                       indeg(t3) = 1
  D: t1 -> t4          t1 -> t4                       indeg(t4) = 1
  E: t3,t4 -> t5       t3 -> t5, t4 -> t5             indeg(t5) = 2

          t1 (0)
         /     \
       t2       t4
        |         \
       t3 -------> t5

  t1 is the only zero — it's the seed, which is right, since A is the only op that runs
  with no prerequisites. t5 has in-degree 2 because E genuinely needs both t3 and t4.
  Compare that to what the current code computes, where t1 came out with in-degree 2 and
  t5 didn't exist as a key at all.

  In code that's the block with the two lines swapped:

  for (Node *op : ops)
    for (int inp : op->inputs)
      for (int ot : op->output) {
        table[inp].push_back(ot);   // prerequisite -> dependent
        inorder[ot]++;              // the dependent owes one
      }

  Two practical advantages over your reverse form, beyond readability:

  - No final reverse. Kahn's emission order is already the execution order.
  - Seeding is only needed for sources. You still want the emplace(t, 0) pass so pure
  sources like t1 exist as keys — under this convention inorder[ot]++ never touches t1.
  Same requirement as before, just landing on the other end of the graph.

  One caveat worth holding onto: this models dependencies between tensors, and it only
  works because each tensor here has exactly one producer. If two ops both output t3,
  the tensor graph can't express "t3 is ready only after both have run." The general
  formulation makes ops and tensors both nodes — t_in → op → t_out — which also gives
  you the op ordering the question actually asks for, and reduces the edge count from
  inputs × outputs to inputs + outputs.


*/