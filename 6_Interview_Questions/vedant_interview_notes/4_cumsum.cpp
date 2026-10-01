// Author: Yash Deshpande
// Date  : 18-08-2026
// Interviwee: Vedant Paranjpe
// Interviewer: Man Wang (Microsoft)
// Link  : https://gist.github.com/VedantParanjape/de52f8f3e762676de4ecb1948bd4b568


/**
 * C++ Hardware-Aware Optimization Interview: 2D Cumulative Sum
 *
 *
 * Run:
 *   ./cumsum_baseline
 *   ./cumsum_optimized
 */

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

// ============================================================================
// Stage 1: Implement this function  (candidate starts here)
// ============================================================================
// cumsum
// asscicative property
// (a+b) + c = a +(b+c)
// 1 row, 100K columns 4 cores

// 4 processor
// each does 2 sum
// 1 3 3 7   5 11  7 15
// 1 2 3 4   5  6  7  8
// 1 3 6 10 15 21 28 36
/**
 * Compute cumulative sum of a 2D array along the specified axis.
 *
 * @param input   Flattened 2D array in row-major order (size = rows * cols)
 * @param output  Pre-allocated buffer for the result   (size = rows * cols)
 * @param rows    Number of rows
 * @param cols    Number of columns
 * @param axis    0 = column-wise cumsum, 1 = row-wise cumsum
 *
 * Example (3x4):
 *   Input:               axis=1 output:         axis=0 output:
 *   1  2  3  4           1  3  6 10             1  2  3  4
 *   5  6  7  8           5 11 18 26             6  8 10 12
 *   9 10 11 12           9 19 30 42            15 18 21 24
 *
 */
 
void cumsum_axis0_blocked(const int* input, int* output, size_t rows, size_t cols) {
    int remain_cols = cols % 16;
    
    for (size_t i = 0; i < cols; i = i + 16) {
        for (size_t j = 0; j < rows; j++) {
            int bounds = 16;
            if (i + 16 > cols)
                bounds = remain_cols;
            if (j == 0) {
                for (int k = 0; k < bounds; k++)
                    output[j * cols + i + k] = input[j * cols + i + k];           
            }
            else {
                for (int k = 0; k < bounds; k++)
                    output[j * cols + i + k] = input[j * cols + i + k] + output[(j - 1) * cols + i + k];
            }
        }
    }
}

void cumsum(const int* input, int* output, size_t rows, size_t cols, int axis) {
    if (axis == 1)
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                if (j == 0)
                    output[i * cols + j] = input[i * cols + j];
                else
                    output[i * cols + j]  = input[i * cols + j] + output[i * cols + j - 1];
            }
        }
    if (axis == 0)
        cumsum_axis0_blocked(input, output, rows, cols);
}

void cumsum_reference(const int* input, int* output, size_t rows, size_t cols, int axis) {
    // TODO: Implement cumsum here.
    // Start with a simple, correct solution — don't worry about performance yet.
    (void)input;
    (void)output;
    (void)rows;
    (void)cols;
    (void)axis;
    
    if (axis == 1)
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                if (j == 0)
                    output[i * cols + j] = input[i * cols + j];
                else
                    output[i * cols + j]  = input[i * cols + j] + output[i * cols + j - 1];
            }
        }
    if (axis == 0)
        for (size_t i = 0; i < cols; i++) {
            for (size_t j = 0; j < rows; j++) {
                if (j == 0)
                    output[j * cols + i] = input[j * cols + i];
                else
                    output[j * cols + i] = input[j * cols + i] + output[(j - 1) * cols + i];
            }
        }
}


// ============================================================================
// Test Utilities
// ============================================================================

void print_array(const int* data, size_t rows, size_t cols, const std::string& name) {
    std::cout << name << " (" << rows << "x" << cols << "):\n";
    for (size_t r = 0; r < rows; r++) {
        std::cout << "  ";
        for (size_t c = 0; c < cols; c++) {
            std::cout << std::setw(4) << data[r * cols + c] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

bool compare_results(const int* result, const int* expected, size_t n, const std::string& test_name) {
    for (size_t i = 0; i < n; i++) {
        if (result[i] != expected[i]) {
            std::cout << "FAIL " << test_name << " at index " << i
                      << ": got " << result[i] << ", expected " << expected[i] << "\n";
            return false;
        }
    }
    std::cout << "PASS " << test_name << "\n";
    return true;
}

// ============================================================================
// Correctness Tests
// ============================================================================

void test_basic_3x4() {
    std::cout << "\n=== Test 1: Basic 3x4 Array ===\n";

    int data[] = {
        1,  2,  3,  4,
        5,  6,  7,  8,
        9, 10, 11, 12
    };
    constexpr size_t R = 3, C = 4;

    print_array(data, R, C, "Input");

    // axis=1 (row-wise)
    int expected_ax1[] = {
        1,  3,  6, 10,
        5, 11, 18, 26,
        9, 19, 30, 42
    };
    int result_ax1[R * C] = {};
    cumsum(data, result_ax1, R, C, 1);
    print_array(result_ax1, R, C, "axis=1 (row-wise)");
    compare_results(result_ax1, expected_ax1, R * C, "Test 1: axis=1");

    // axis=0 (column-wise)
    int expected_ax0[] = {
         1,  2,  3,  4,
         6,  8, 10, 12,
        15, 18, 21, 24
    };
    int result_ax0[R * C] = {};
    cumsum(data, result_ax0, R, C, 0);
    print_array(result_ax0, R, C, "axis=0 (column-wise)");
    compare_results(result_ax0, expected_ax0, R * C, "Test 1: axis=0");
}



void test_large_random() {
    std::cout << "\n=== Test 5: Large Random Array (Correctness) ===\n";

    constexpr size_t R = 100, C = 100;
    std::vector<int> data(R * C), out(R * C), expected(R * C);

    std::mt19937 gen(12345);
    std::uniform_int_distribution<int> dis(-100, 100);
    for (auto& v : data) v = dis(gen);

    cumsum(data.data(), out.data(), R, C, 1);
    cumsum_reference(data.data(), expected.data(), R, C, 1);
    compare_results(out.data(), expected.data(), R * C, "Test 5a: 100x100 random axis=1");

    cumsum(data.data(), out.data(), R, C, 0);
    cumsum_reference(data.data(), expected.data(), R, C, 0);
    compare_results(out.data(), expected.data(), R * C, "Test 5b: 100x100 random axis=0");
}


// Main
// ============================================================================

int main() {
    std::cout << "C++ Hardware-Aware Optimization Interview: 2D Cumulative Sum\n";
    std::cout << std::string(70, '=') << "\n";

    // --- Correctness ---
    std::cout << "\nCORRECTNESS TESTS\n";
    std::cout << std::string(70, '-') << "\n";

    //test_basic_3x4();

    test_large_random();



    return 0;
}


// ============================================================================
// Claude Analysis -> Not given in the question
// ============================================================================


/*

// What claude thinks needs to be done in this qs ? 
// Summary of what's expected

//   1. Correct naive implementation for both axes.
//   2. Recognize axis=0's stride problem and fix it with cache blocking.
//   3. Discuss SIMD applicability (works for axis=0 blocked, blocked by the dependency chain for axis=1).
//   4. Explain the associativity-based parallel scan for the single-huge-row / multicore case.


The following is an even better version of the blocked axis = 0 version

void cumsum_axis0(const int* in, int* out, size_t rows, size_t cols) {
    for (size_t j = 0; j < cols; j++)          // first row copies through
        out[j] = in[j];
    for (size_t i = 1; i < rows; i++)          // then each row = itself + row above
        for (size_t j = 0; j < cols; j++)
            out[i*cols + j] = in[i*cols + j] + out[(i-1)*cols + j];
}

taking the block width to the full row is strictly better, because now the inner loop is a pure contiguous stream with no
  loop-carried dependency at all. GCC vectorizes it automatically:

  optimized: loop vectorized using 64 byte vectors   # AVX-512

1. The inner loop is too short to vectorize well. 16 ints is one AVX-512 register. GCC can't
  amortize the vector setup over a 16-iteration trip count, so it largely gives up. With the full
  row it emits loop vectorized using 64 byte vectors and streams.
  2. Loop overhead per useful work. At B=16 you pay the row-loop bookkeeping and the if (i + 16 > 
  cols) bounds check every 16 elements. At B=4096 you pay it once per row.
  3. Each block re-streams the array. With B=16 on a 4096-wide row you make 256 separate passes
  over the 67 MB buffer. Every pass re-reads input from DRAM, because 67 MB doesn't stay resident
  in a 16 MB L3. Widening the block cuts the number of passes proportionally. This is the cost
  that keeps paying out well past the cache-line boundary — note the gains continue from 256 →
  1024 → 4096, long after the line-utilization argument is saturated.

  That third point is worth internalizing: blocking is normally a technique for increasing reuse, 
  but here it was manufacturing redundant traffic. The reason is that this kernel has no reuse to
  capture — each element is read once, added once, written once. There's no tile to hold in cache
  across iterations. So the usual justification for picking a block size that fits L1 or L2 simply
  doesn't apply, and the only thing block width controls is how many times you sweep the array.


--------------------------------------------------------------------------------
Further notes
--------------------------------------------------------------------------------

LOOP-CARRIED DEPENDENCE
  Iteration N needs a value iteration N-1 produced, so the iterations cannot be
  reordered, threaded, or packed into a SIMD register.

  axis=1: out[j] = out[j-1] + in[j]   -> dependence is in the INNER loop. Serial
          chain of adds, one per element. Cannot vectorize.
  axis=0: out[i][j] = in[i][j] + out[i-1][j]  -> the inner loop over j is
          dependence-free (each column is independent); the dependence sits on
          the OUTER loop over i, which is only `rows` long. Inner loop
          vectorizes fully.

  General trick: push the dependence out to an outer loop and leave the inner
  loop a clean contiguous stream.

ACCUMULATOR INSTEAD OF RE-READING output[]
  for (j...) { acc += in[i*cols + j]; out[i*cols + j] = acc; }

  Drops the j==0 branch and keeps the running sum in a register. The win is
  LATENCY, not memory traffic -- out[j-1] was just written and is still in the
  store buffer / L1, so it never costs a DRAM access. But a register-to-register
  add closes the dependence chain in ~1 cycle vs ~5 for store-to-load
  forwarding, and that chain is the entire critical path for axis=1.

  Does not apply to axis=0: the dependence there is on an entire row above
  (`cols` values), which no single register can hold.

BREAKING THE DEPENDENCE VIA ASSOCIATIVITY (the `4 processor` sketch at the top)
  Three phases, for 1 2 3 4 5 6 7 8 on 4 cores:

    1. Each core prefix-sums its own chunk, in parallel, no cross-talk:
         [1 2] [3 4] [5 6] [7 8]  ->  [1 3] [3 7] [5 11] [7 15]
       Chunk totals: 3, 7, 11, 15.
    2. Exclusive scan of the chunk totals (serial, but only `ncores` numbers):
         offsets: 0, 3, 10, 21
    3. Each core adds its single offset to every element of its chunk, in
       parallel:
         [1 3]+0  [3 7]+3  [5 11]+10  [7 15]+21
         -> 1 3 6 10 15 21 28 36

  Legal because (a+b)+c == a+(b+c): core 2 computes 5 locally and is handed
  1+2+3+4 = 10, i.e. the same sum regrouped. ~2x the total additions, but
  phases 1 and 3 are fully parallel and phase 2 stays tiny.

  Same structure inside one SIMD register = log-step shift-and-add scan
  (zeros shift in from the left):

    input:            1  2  3  4  5  6  7  8
    shift 1, add:     1  3  5  7  9 11 13 15
    shift 2, add:     1  3  6 10 14 18 22 26
    shift 4, add:     1  3  6 10 15 21 28 36

  log2(8) = 3 vector ops instead of 8 serial adds; 4 ops for a 16-wide AVX-512
  register. NOTE: only valid for associative operators (+, *, min, max).
  Floating-point + is not strictly associative, so the compiler will not do this
  reassociation for float/double without -ffast-math.

MEMORY-BANDWIDTH-BOUND
  Arithmetic intensity of the axis=0 kernel:
    bytes per element = 4 (read in) + 4 (read row above) + 4 (write out) = 12
    ops   per element = 1 add
    -> ~0.083 ops/byte

  A desktop CPU (~50 GB/s DRAM, ~200 G int-adds/s with AVX-512) needs roughly
  4 ops/byte to stay busy -- about 50x more than this kernel supplies. The adder
  finishes a vector in a cycle and then waits for the next 64 bytes.

  Consequences:
    - Wider SIMD (AVX2 -> AVX-512) buys almost nothing at large sizes.
    - Extra cores buy little once 2-3 of them saturate the memory controller.
    - The only real lever is REDUCING BYTES MOVED. That is exactly why full-row
      blocking beat B=16: same arithmetic, one sweep instead of cols/16 sweeps.
    - Other traffic cuts: compute in place (in == out) saves 4 bytes/elt;
      non-temporal stores skip the read-for-ownership on the write, another 4.

  Quick test: replace the kernel body with a plain copy out[x] = in[x]. If the
  runtime barely moves, you are memory-bound and SIMD cleverness will not help.

*/