#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <memory>
#include <chrpp.hh>
#include "AnySimpleType.h"
#include "parsercowl.h"
#include "constants.h"
#include "types.h"
#include <filesystem>

namespace fs = std::filesystem;

// ── Display ───────────────────────────────────────────────────────────────────

inline void afficher(const std::string& x) {
    std::cout << x << std::endl;
}

inline void afficher(const std::string& x, const std::string& y) {
    std::cout << x << "    " << y << std::endl;
}

// ── File output ───────────────────────────────────────────────────────────────

inline void stockerRealisation(std::string x, std::string y) {
    std::ofstream out(output_file_Real, std::ios::app);
    if (!out) { std::cerr << "Impossible d'ouvrir output.txt\n"; return; }
    out << x << " " << y << "\n";
    out.close();
}

inline void stockerClassification(std::string x, std::string y) {
    std::ofstream out(output_file_Classif, std::ios::app);
    if (!out) { std::cerr << "Impossible d'ouvrir  output_file_Classif\n"; return; }
    out << x << " " << y << "\n";
    out.close();
}

inline void stockerQueries(const StringSet& s, int id) {
    //std::ofstream out(output_file_Queries, std::ios::app);
    std::string queriesFilename = output_file_Queries + "_" + std::to_string(id);
    std::ofstream out(queriesFilename, std::ios::app);
    if (!out) { std::cerr << "Impossible d'ouvrir  output_file_Queries\n"; return; }
    out << id << " : ";
    for (const std::string& res : s)
        out << res << "  ";
    out << std::endl;
    out.close();
}

// ── String helpers ────────────────────────────────────────────────────────────

inline std::string valueToString(const Value& v) {
    return "\"" + v.val + "\"";
}

inline StringSet makeVec(const std::string& a, const std::string& b) {
    StringSet s;
    s.insert(s.end(), a);
    s.insert(s.end(), b);
    return s;
}

inline void afficherResultatSet(const StringSet& s, int id) {
    std::cout << id << " : ";
    for (const std::string& res : s)
        std::cout << res << "  ";
    std::cout << std::endl;
}

inline bool samePrefix(const std::string& px, const std::string& x) {
    size_t pos = px.find(':');
    std::string pref = px.substr(0, pos);
    return (pref == x);
}

inline bool prefixIntern(const std::string& uri) {
    size_t pos = uri.find('#');
    std::string pref = uri.substr(0, pos);
    return (pref == "http://anonymous.org");
}

inline std::string constructFullUri(const std::string& prefix,
                              const std::string& localName) {
    auto pos = localName.find(':');
    std::string name = localName.substr(pos + 1);
    return prefix + ":" + name;
}

// ── OWL / CHR helpers ─────────────────────────────────────────────────────────

inline bool different(const chr::Logical_var<int>& A,
               const chr::Logical_var<int>& B,
               const chr::Logical_var<int>& C) {
    return A != B && B != C && A != C;
}

inline bool contains(const chr::Logical_var<int>& x, const LogicalVarSet& l) {
    return l.find(x) != l.end();
}

inline LogicalVarSetIterator getBegin(const LogicalVarSet& s) { return s.begin(); }
inline LogicalVarSetIterator getEnd  (const LogicalVarSet& s) { return s.end();   }

inline bool sameDataType(const std::shared_ptr<AnySimpleType> dr1,
                   const std::shared_ptr<AnySimpleType> dr2) {
    if (!dr1 || !dr2) return false;
    return dr1->getId() == dr2->getId();
}

inline bool invalidType(const std::shared_ptr<AnySimpleType> dr, const Value& v) {
    if (!dr || !v.typeVal) return true;
    return !v.typeVal->verify(dr.get());
}

inline Value createValue(const std::string& val,
                   const std::shared_ptr<AnySimpleType> typeVal) {
    Value v;
    v.val     = val;
    v.typeVal = typeVal;
    return v;
}

inline bool equalIncrement(int j, int i) {
    return j == i + 1;
}

template <typename T>
inline bool checkClassification(T& pb, const std::string& x, const std::string& c) {
    auto it = pb.get_owlClassAssertion_store().begin();
    while (!it.at_end()) {
        if ((*std::get<1>(*it)) == x && (*std::get<2>(*it)) == c)
            return true;
        ++it;
    }
    return false;
}




// ── Create output directories if they don't exist ────────────────────────────
// void create_output_dirs() {
//     const std::vector<std::string> dirs = {
//         "results",
//         "results/queries"
//     };

//     for (const auto& dir : dirs) {
//         if (!fs::exists(dir)) {
//             fs::create_directories(dir);
//             std::cout << "Created directory: " << dir << std::endl;
//         }
//     }
// }
