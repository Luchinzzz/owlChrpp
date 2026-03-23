#pragma once
#include <memory>
#include <string>
#include <chrpp.hh>
#include "AnySimpleType.h"
#include "parsercowl.h"
#include "types.h"

namespace chr {

// ── Ordinamento Logical_var per std::set ──────────────────────────────────────
template<typename T>
bool operator<(const Logical_var<T>& a, const Logical_var<T>& b) {
    if (a.ground() && b.ground())
        return *a < *b;
    return &a < &b;
}

// ── Wrapper AnySimpleType ─────────────────────────────────────────────────────
template<>
struct Type_instruction_wrapper<std::shared_ptr<AnySimpleType>, false> {
    static std::string to_string(const std::shared_ptr<AnySimpleType>& ptr) {
        if (!ptr) return "null";
        return "AnySimpleType(id=" + ptr->toString() + ")";
    }
    static void update_hash(const std::shared_ptr<AnySimpleType>& ptr) {
        if (ptr) XXHash<unsigned int>::update(ptr->getId());
    }
    static bool is_equal(const std::shared_ptr<AnySimpleType>& a,
                          const std::shared_ptr<AnySimpleType>& b) {
        if (!a || !b) return a == b;
        return a->getId() == b->getId();
    }
};

// ── Wrapper Value ─────────────────────────────────────────────────────────────
template <>
struct Type_instruction_wrapper<Value, false> {
    static std::string to_string(const Value& v) {
        return "Value(" + v.val + ")";
    }
    static void update_hash(const Value& v) {
        XXHash<std::string>::update(v.val);
    }
    static bool is_equal(const Value& a, const Value& b) {
        return a.val == b.val;
    }
};

// ── Wrapper std::set<std::string>::iterator ───────────────────────────────────
template<>
struct Type_instruction_wrapper<std::set<std::string>::iterator, false> {
    static std::string to_string(const std::set<std::string>::iterator& it) {
        return *it;
    }
    static void update_hash(const std::set<std::string>::iterator&) {}
    static bool is_equal(const std::set<std::string>::iterator& a,
                          const std::set<std::string>::iterator& b) {
        return a == b;
    }
};

// ── Wrapper LogicalVarSetIterator ─────────────────────────────────────────────
template<>
struct Type_instruction_wrapper<LogicalVarSetIterator, false> {
    static std::string to_string(const LogicalVarSetIterator&) {
        return "LogicalVarSetIterator";
    }
    static void update_hash(const LogicalVarSetIterator&) {}
    static bool is_equal(const LogicalVarSetIterator& a,
                          const LogicalVarSetIterator& b) {
        return a == b;
    }
};

} // namespace chr

// ── XXHash specialisations ────────────────────────────────────────────────────
template <>
struct chr::XXHash<std::shared_ptr<AnySimpleType>> {
    static void update(const std::shared_ptr<AnySimpleType>& ptr) {
        if (ptr)
            chr::XXHash<unsigned int>::update(ptr->getId());
        else
            chr::XXHash<unsigned int>::update(0);
    }
};

template <>
struct chr::XXHash<Value> {
    static void update(const Value& v) {
        std::string composite = v.val;
        if (v.typeVal)
            composite += "::" + std::to_string(v.typeVal->getId());
        else
            composite += "::null";
        chr::XXHash<std::string>::update(composite);
    }
};

template <>
struct chr::XXHash<LogicalVarSetIterator> {
    static void update(const LogicalVarSetIterator& it) {
        chr::XXHash<size_t>::update(reinterpret_cast<size_t>(&(*it)));
    }
};