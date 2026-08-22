/*
 * Quadric - Interview Question
 *
 * Given an undirected graph G with V vertices where each vertex is an object with
 * pointers to neighbors, determine the smallest nonnegative integer N such that G
 * can be considered an N-partite graph.
 *
 * N-partite graph: a graph that consists of N groups of nodes, where:
 *   1) Each group consists of 0+ nodes
 *   2) Each node belongs to exactly a single group
 *   3) No 2 nodes within the same group have any edges between them
 *      (i.e. no edges within a group, only edges between groups)
 *
 * N >= 0
 *
 * class Node:
 *
 *     neighbors: list[Node]
 *
 * inp: list[Node]
 *
 * What does the algorithm generally look like? How do you know it's correct for all
 * cases? What's the worst case runtime?
 */

/*
 * Scratch notes (README.md from the pad)
 *
 * ```
 * 1-4
 *  \|
 * 2-5
 *
 * 3-6
 *
 * N=3
 * 3-partite
 * {1, 2, 3} {4, 6} {5}
 * ```
 ////////////////////////// MY Solution. 
 * 1-4
 *  \|
 * 2-5
 *
 * 1 -> 4, 5
 * 2 -> 5
 * 4 -> 1, 5
 * 5 -> 1, 2, 4
 *
 * // 1->
 * <!-- b1 = 1
 * b2 = 4, 5 -->
 *
 * b1 = 1
 *
 * // 2->
 * <!-- b1 = 1, 2
 */

/*
 * WHY THE ORIGINAL BUCKET IDEA WAS WRONG
 *
 * Edges: 1-4, 1-5, 2-5, 4-5
 *
 * The scratch attempt did "visit node X, then place X's *neighbors* into a bucket",
 * producing b2 = {4, 5}. That is invalid: 4-5 is itself an edge, so 4 and 5 cannot
 * share a group.
 *
 * Correct framing: don't place a node's neighbors. Place *the node itself* into the
 * first group that contains none of its neighbors; open a new group only if no
 * existing group qualifies. That is exactly graph coloring, and the minimum N is the
 * chromatic number.
 *
 * For this graph {1, 4, 5} form a triangle (pairwise adjacent), so N = 3:
 *   g1 = {1}, g2 = {4}, g3 = {5}
 * and 2 (adjacent only to 5) drops into g1 or g2. Answer N = 3, not 2.
 *
 * CAVEATS
 *  - Greedy is not minimal. "Smallest unused color among colored neighbors" gives
 *    only an upper bound; the result depends on vertex ordering.
 *  - The exact minimum is NP-hard in general. Easy special cases:
 *      no vertices                  -> N = 0
 *      vertices but no edges        -> N = 1
 *      has edges, no odd cycle      -> N = 2 (bipartite, BFS/DFS 2-coloring)
 *      otherwise                    -> real chromatic-number search (backtracking,
 *                                      or try k = 3, 4, ... with a feasibility check)
 *
 * Runtime of the greedy pass below: O(V + E) amortized -- each vertex scans its own
 * adjacency list once to mark forbidden colors, then picks the smallest free color.
 * Space: O(V + maxDegree).
 */

/*
 * DRY RUN 1 -- the pad's example (expected N = 3)
 *
 *   1-4
 *    \|
 *   2-5      3-6
 *
 * Edges: 1-4, 1-5, 2-5, 4-5, 3-6
 *
 * Adjacency lists:
 *   1 -> 4, 5        4 -> 1, 5
 *   2 -> 5           5 -> 1, 2, 4
 *   3 -> 6           6 -> 3
 *
 * Iterate `inp` in order 1, 2, 3, 4, 5, 6. For each node we look ONLY at neighbours
 * that already have a colour, mark those colours forbidden, and take the smallest
 * colour left. Uncoloured neighbours are ignored -- they will see us when their turn
 * comes, which is what makes one pass enough.
 *
 *   node | coloured neighbours | forbidden | chosen | groups after
 *   -----+---------------------+-----------+--------+---------------------------
 *     1  | -- (4,5 uncoloured) | {}        |   0    | g1={1}
 *     2  | -- (5 uncoloured)   | {}        |   0    | g1={1,2}
 *     3  | -- (6 uncoloured)   | {}        |   0    | g1={1,2,3}
 *     4  | 1->c0               | {0}       |   1    | g1={1,2,3} g2={4}
 *     5  | 1->c0, 2->c0, 4->c1 | {0,1}     |   2    | ... g2={4} g3={5}
 *     6  | 3->c0               | {0}       |   1    | ... g2={4,6} g3={5}
 *
 * Result: N = 3, partition {1,2,3} {4,6} {5} -- exactly the pad's expected answer.
 *
 * Note how node 5 is what forces the third group: by the time we reach it, its
 * neighbours already occupy colours 0 and 1, so 2 is the smallest colour available.
 * That is the triangle {1,4,5} showing up -- three mutually adjacent nodes can never
 * fit in fewer than three groups, so here greedy happens to hit the true minimum.
 *
 *
 * DRY RUN 2 -- where greedy overshoots (crown graph, true N = 2)
 *
 * Six nodes u1,u2,u3 = 1,2,3 and v1,v2,v3 = 4,5,6, with u_i adjacent to v_j for every
 * i != j. Edges: 1-5, 1-6, 2-4, 2-6, 3-4, 3-5.
 *
 * A crown graph is the complete bipartite graph K(3,3) with its "perfect matching"
 * removed -- every u connects to every v EXCEPT its own partner (1-4, 2-5, 3-6 are
 * the missing edges):
 *
 *        u side          v side
 *          1 . . . . . . . 4        legend:  ---  edge present
 *            \         /                     ...  matched pair, NO edge
 *             \       /
 *              \     /
 *          2 . .\. ./. . . 5
 *              \ \ / /
 *               \ X /
 *                \|/
 *          3 . . /|\. . . .6
 *               / | \
 *
 *   1 -> 5, 6      4 -> 2, 3
 *   2 -> 4, 6      5 -> 1, 3
 *   3 -> 4, 5      6 -> 1, 2
 *
 * Every node has degree 2, and the graph is one big 6-cycle in disguise:
 * 1-5-3-4-2-6-1. An even cycle, so it is bipartite and 2 groups suffice.
 *
 * This is bipartite -- {1,2,3} | {4,5,6} is a perfectly legal 2-group answer, since
 * no u touches another u and no v touches another v. But feed the vertices in the
 * interleaved order 1, 4, 2, 5, 3, 6:
 *
 *   node | coloured neighbours | forbidden | chosen | groups after
 *   -----+---------------------+-----------+--------+---------------------------
 *     1  | -- (5,6 uncoloured) | {}        |   0    | g1={1}
 *     4  | -- (2,3 uncoloured) | {}        |   0    | g1={1,4}
 *     2  | 4->c0               | {0}       |   1    | g2={2}
 *     5  | 1->c0               | {0}       |   1    | g2={2,5}
 *     3  | 4->c0, 5->c1        | {0,1}     |   2    | g3={3}
 *     6  | 1->c0, 2->c1        | {0,1}     |   2    | g3={3,6}
 *
 * Result: N = 3 -- a valid partition, but not the minimum.
 *
 * The damage is done on the second row: 1 and 4 are NOT adjacent, so greedy cheerfully
 * puts them together, and that pairing then blocks colour 0 for everyone downstream.
 * Greedy commits to a choice permanently and never revisits it, which is exactly why
 * it yields an upper bound rather than the chromatic number. Order the same graph as
 * 1, 2, 3, 4, 5, 6 and it returns 2.
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
    int id;
    vector<Node*> neighbors;

    explicit Node(int id_) : id(id_) {}
};

// Greedy N-partite / graph-coloring pass.
//
// Returns the number of groups used (an UPPER BOUND on the true minimum N), and
// fills `groups` with the actual partition so the caller can inspect / verify it.
int greedyNPartite(const vector<Node*>& inp,
                   vector<vector<Node*>>& groups) {
    groups.clear();

    // color[node] = index of the group the node was placed into.
    unordered_map<const Node*, int> color;
    color.reserve(inp.size());

    // Reused across iterations: forbidden[c] == stamp means color c is taken by some
    // already-coloured neighbour of the current node. The stamp trick avoids clearing
    // the vector every iteration, keeping the whole pass O(V + E).
    vector<int> forbidden;
    int stamp = 0;

    for (Node* node : inp) {
        if (node == nullptr || color.count(node)) continue;  // skip dupes in `inp`

        ++stamp;
        if (forbidden.size() < node->neighbors.size() + 1) {
            forbidden.resize(node->neighbors.size() + 1, 0);
        }

        // Mark every colour already used by a neighbour.
        for (const Node* nb : node->neighbors) {
            auto it = color.find(nb);
            if (it == color.end()) continue;               // neighbour not coloured yet
            if (it->second < static_cast<int>(forbidden.size())) {
                forbidden[it->second] = stamp;
            }
        }

        // Smallest colour not used by any neighbour. A node of degree d can always be
        // satisfied by one of colours 0..d, so this loop terminates within d+1 steps.
        int chosen = 0;
        while (chosen < static_cast<int>(forbidden.size()) && forbidden[chosen] == stamp) {
            ++chosen;
        }

        color[node] = chosen;
        if (chosen >= static_cast<int>(groups.size())) {
            groups.resize(chosen + 1);
        }
        groups[chosen].push_back(node);
    }

    return static_cast<int>(groups.size());
}

// Sanity check: confirm no group contains two adjacent nodes.
bool isValidPartition(const vector<vector<Node*>>& groups) {
    for (const auto& group : groups) {
        for (const Node* a : group) {
            for (const Node* nb : a->neighbors) {
                if (find(group.begin(), group.end(), nb) != group.end()) {
                    return false;
                }
            }
        }
    }
    return true;
}

namespace {

void addEdge(Node& a, Node& b) {
    a.neighbors.push_back(&b);
    b.neighbors.push_back(&a);
}

void run(const char* label, const vector<Node*>& inp) {
    vector<vector<Node*>> groups;
    int n = greedyNPartite(inp, groups);

    cout << label << ": N = " << n
              << (isValidPartition(groups) ? "  (valid)" : "  (INVALID)") << "\n";
    for (size_t g = 0; g < groups.size(); ++g) {
        cout << "  g" << g + 1 << " = {";
        for (size_t i = 0; i < groups[g].size(); ++i) {
            cout << (i ? ", " : "") << groups[g][i]->id;
        }
        cout << "}\n";
    }
}

}  // namespace

int main() {
    // Case 1: empty graph -> N = 0.
    run("empty", {});

    // Case 2: 1-4, 1-5, 2-5, 4-5, plus isolated 3-6 edge.
    // {1,4,5} is a triangle, so the true minimum is 3.
    {
        Node n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
        addEdge(n1, n4);
        addEdge(n1, n5);
        addEdge(n2, n5);
        addEdge(n4, n5);
        addEdge(n3, n6);
        run("triangle+", {&n1, &n2, &n3, &n4, &n5, &n6});
    }

    // Case 3: crown graph on 6 vertices -- u_i adjacent to v_j for every i != j.
    // It is bipartite ({u1,u2,u3} | {v1,v2,v3}), so the true minimum is 2, but the
    // interleaved order u1,v1,u2,v2,u3,v3 makes greedy report 3. This is the concrete
    // demonstration that greedy is only an upper bound, not the chromatic number.
    {
        Node u1(1), u2(2), u3(3), v1(4), v2(5), v3(6);
        Node* us[] = {&u1, &u2, &u3};
        Node* vs[] = {&v1, &v2, &v3};
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i != j) addEdge(*us[i], *vs[j]);
            }
        }
        run("crown (truly 2-partite)", {&u1, &v1, &u2, &v2, &u3, &v3});
    }

    return 0;
}
