#include <bits/stdc++.h>
using namespace std;

mt19937 rng;

/**
 * @brief Generates a random integer between the specified range [a, b].
 * 
 * This function uses a Mersenne Twister random number generator to produce
 * a uniformly distributed random integer within the inclusive range [a, b].
 * 
 * @param a The lower bound of the range (inclusive).
 * @param b The upper bound of the range (inclusive).
 * @return int32_t A random integer between a and b (inclusive).
 */
auto random_int(int32_t a, int32_t b) -> int32_t {
    uniform_int_distribution<int32_t> dist(a, b);
    return dist(rng);
}

/**
 * @brief Generates a random tree and prints its edges.
 * 
 * This function generates a random tree with a random number of nodes between 3 and 100.
 * It first generates a list of edges to form a tree, then randomly shuffles the vertices
 * and the order of the edges. Finally, it prints the edges of the tree.
 * 
 * @note This function is based on the implementation by errichto.
 *       Source: https://github.com/Errichto/youtube/blob/master/testing/gen_tree2.cpp
 */
auto generate_tree() -> void {
    int32_t cnt_nodes = random_int(3, 100);
    cout << cnt_nodes << endl;
    vector<pair<int32_t, int32_t>> edges;
    for (int32_t node = 2; node <= cnt_nodes; ++node) {
        edges.emplace_back(random_int(1, node - 1), node);
    }

    // Re-naming vertices
    vector<int32_t> perm(cnt_nodes + 1);
    for (int32_t node = 1; node <= cnt_nodes; ++node) {
        perm[node] = node;
    }
    
    // Randomly shuffle the vertices and order of edges
    random_shuffle(perm.begin() + 1, perm.end());
    random_shuffle(edges.begin(), edges.end());

    for (auto &[x, y]: edges) {
        auto u = perm[x], v = perm[y];
        if (rand() % 2) {
            swap(u, v);
        }
        cout << u << ' ' << v << endl;
    }
}


/**
 * @brief Generates a vector of random integers within a specified range.
 * 
 * This function creates a vector of size `n` and fills it with random integers
 * in the range [a, b].
 * 
 * @param n The size of vector.
 * @param a The lower bound of the range (inclusive).
 * @param b The upper bound of the range (inclusive).
 * @return A vector of random integers of size `n`.
 */
auto random_array(
    int32_t n,
    int32_t a,
    int32_t b
) -> vector<int32_t> {
    vector<int32_t> arr(n);
    for (int32_t i = 0; i < n; ++i) {
        arr[i] = random_int(a, b);
    }
    return arr;
}

int32_t main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <seed>" << endl;
        return 1;
    }
    rng = mt19937(atoi(argv[1]) * time(0));
    
    // Example 1: Generate a random array
    auto n = random_int(1, 10);
    auto arr = random_array(n, 1, 100);
    for (auto &x: arr) {
        cout << x << ' ';
    }
    cout << endl;

    // Example 2: Generate a random tree
    generate_tree();
}