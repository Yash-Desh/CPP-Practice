// Author : Yash Deshpande
// Date   : 16-07-2026
// Topic  : [[nodiscard]] attribute (C++17)

// -------------------------------------------------------------------------- //
// DISCLAIMER:
// The notes/explanations in this file were drafted with the help of an LLM
// (Anthropic Claude Opus 4.8) on 16-07-2026. Verify against a standard
// reference (cppreference / the C++ standard) before relying on details.
//
// CONTEXT:
// This concept was encountered while working on COMGR (Code Object Manager)
// in amd-llvm for the Hotswap team at AMD.
// -------------------------------------------------------------------------- //

#include <iostream>
using namespace std;

// [[nodiscard]] is a standard C++ attribute (C++17). It tells the compiler to
// emit a warning if the caller ignores (discards) the function's return value.
// This is useful for functions where dropping the result is almost always a bug
// e.g. status/error codes, allocation results, or "success" flags.

// --- 1. On a function ---
[[nodiscard]] bool didItSucceed() {
    return true;
}

// --- 2. With a message (C++20) explaining *why* the value matters ---
[[nodiscard("check the returned error code")]] int computeErrorCode() {
    return 0;
}

// --- 3. On a type: every function returning this type is then covered ---
enum class [[nodiscard]] Status {
    Ok,
    Failed
};

Status runTask() {
    return Status::Ok;
}

int main() {
    // Ignoring the return value -> compiler warning:
    // didItSucceed();
    // computeErrorCode();
    // runTask();

    // Correct usage: consume the result.
    bool ok = didItSucceed();
    int code = computeErrorCode();
    Status s = runTask();

    // To deliberately discard (and silence the warning), cast to void:
    (void)didItSucceed();

    cout << "ok=" << ok << " code=" << code
         << " status=" << (s == Status::Ok ? "Ok" : "Failed") << endl;

    return 0;
}

// -------------------------------------------------------------------------- //
// Key points:
//  - Produces a WARNING, not an error (unless compiled with -Werror).
//  - Suppress intentionally with a (void) cast.
//  - Part of the standard attribute family: [[deprecated]], [[maybe_unused]],
//    [[fallthrough]], [[likely]], [[unlikely]], etc.
// -------------------------------------------------------------------------- //
