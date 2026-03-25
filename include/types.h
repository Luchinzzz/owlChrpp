#pragma once
#include <set>
#include <vector>
#include <string>
#include <chrpp.hh>

// ── Alias ────────────────────────────────────────────────────────────────────
using LogicalVarSet         = std::set<chr::Logical_var<int>>;
using StringSet             = std::vector<std::string>;
using LogicalVarSetIterator = std::set<chr::Logical_var<int>>::iterator;

// ──Global counter ────────────────────────────────
static int global_counter = 0;

inline int get_next_id() {
    return global_counter++;
}

struct Query {
    std::string type;   
    std::string uri;
};
