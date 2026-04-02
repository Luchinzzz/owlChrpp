# owl2chr — OWL 2 RL Declarative Reasoner based on CHR++

owl2chr is a declarative inference engine for OWL 2 RL ontologies, built on top of **CHR++** (Constraint Handling Rules) and the **COWL** C library for OWL 2 parsing.

## Description

This project implements an inference and reasoning engine for OWL 2 (Web Ontology Language) ontologies. It combines:
- **CHR++**: Constraint handling rules system for logical inference
- **COWL**: C library for OWL 2 ontology parsing
- **Query system**: Query interface to interrogate ontologies

### Supported OWL 2 RL Inferences

- **Class hierarchy**: SubClassOf, EquivalentClass, transitivity
- **Object properties**: SubObjectProperty, transitivity, symmetry, inverse
- **Data properties**: SubDataProperty, domains, ranges, XSD types
- **Complex classes**:
  - IntersectionOf (conjunction)
  - UnionOf (disjunction)
  - ComplementOf (negation)
  - ObjectSomeValuesFrom (∃R.C)
  - ObjectAllValuesFrom (∀R.C)
  - DataSomeValuesFrom, DataAllValuesFrom
  - ObjectMaxCardinality, DataMaxCardinality
  - HasValue, OneOf, HasKey
- **Individuals**: SameIndividual, DifferentIndividuals
- **Constraints**: DisjointClasses, DisjointProperties
- **owl:Thing** and **owl:Nothing**

### Query System

1. **querySuperClassOfUri(URI)** — Retrieves all superclasses of a class (including owl:Thing)
2. **querySubClassOfUri(URI)** — Retrieves all subclasses of a class
3. **queryClassificationUri(URI)** — Retrieves all classes an individual is an instance of
4. **queryInstanceURI(IndividualURI, ClassURI)** — Checks if an individual is an instance of a class
5. **queryInstancesURI(ClassURI)** — Lists all individuals of a class

---

## Installation

See [INSTALL.md](INSTALL.md) for full installation instructions.

### Requirements

- **CMake** ≥ 3.14
- **GCC/G++** with C++17 support
- **Git**
- **COWL** (OWL 2 library — included as a submodule)
- **CHR++** ≥ commit `a9ebc45` (February 2, 2026) — version `v1.7.0-44` or newer
  - Repository: https://gitlab.com/vynce/chrpp
  - Must be compiled **in-source** (see below)

> **CHR++ version note**: versions older than commit `a9ebc45` generate incorrect guard expressions in `owlrules.cpp`, leading to wrong inference results or crashes. If a new CHR++ version is released, verify it includes this commit before upgrading.

### Quick Install

```bash
# 1. Clone and build CHR++ in-source (IMPORTANT: no build/ subdirectory)
cd ~/projects
git clone https://gitlab.com/vynce/chrpp.git
cd chrpp
cmake .      # in-source build — chrppc will be at chrpp/chrppc/chrppc
make
cd ..

# 2. Clone owlChrpp with submodules
git clone --recurse-submodules https://github.com/arigraphitech/owlChrpp.git
cd owlChrpp

# 3. Build (Release -O3 by default, owlrules.cpp auto-generated)
cmake -S . -B build
cd build && make -j$(nproc)

# 4. Run (from the project root)
cd ..
./build/ParserProject examples/ofn/OWL2RL-10.ofn
```

If CHR++ is not in `../chrpp` (sibling directory), specify the path:
```bash
cmake -DCHRPP_ROOT=/absolute/path/to/chrpp -S . -B build
```

**CMake output messages**:
- `CHR++ found: .../chrppc/chrppc (owlrules.cpp auto-regeneration enabled)` → ready
- `chrppc not found — using pre-generated owlrules.cpp` → CHR++ not found, see [INSTALL.md](INSTALL.md)

---

### CMake Build Logic

The CMake workflow is based on two separate targets with distinct dependencies:
```bash
owlrules.chrpp ──(chrppc)──► owlrulesOWL2.cpp/.hh ──► [owlrulesOWL2.o library] ──► libowl_rules.a
                                                                                        │
main.cpp ───────────────(g++ -std=c++17 -O3)──────────────────────────────► ParserProject (executable)

```

#### Target 1 — owl_rules (static library)
Contains only owlrules.cpp generated from owlrules.chrpp.
Recompiled only when owlrules.chrpp changes.
main.cpp is not among its dependencies, so modifying it does not trigger recompilation

##### Target 2 — ParserProject (executable)
Contains only main.cpp and links owl_rules.
When main.cpp changes, CMake recompiles only main.cpp and relinks, CHR rules remain unchanged.
Useful CMake Commands:

```bash
# Configure + build
cmake -B build
cmake --build build

# Force regeneration of CHR++ output (if changed)
cmake --build build --target generate_rules

# Build only the executable main.cpp (if changed)
cmake --build build --target ParserProject

# Clean build
rm -rf build && cmake -B build && cmake --build build
```
---
## Input Format

The engine accepts **OWL 2 Functional Syntax** (`.ofn`) only:

```
Prefix(ex:=<http://example.org#>)
Ontology(
    Declaration(Class(ex:Student))
    SubClassOf(ex:PhDStudent ex:Student)
    ClassAssertion(ex:Student ex:Alice)
    ObjectPropertyAssertion(ex:enrolledIn ex:Alice ex:Math101)
)
```

### Converting from Other Formats (RDF/XML, Turtle, Manchester, etc.)

Use **ROBOT CLI** to convert any OWL format to OWL Functional Syntax:

#### Install ROBOT

```bash
# Download the ROBOT jar
curl -L https://github.com/ontodev/robot/releases/latest/download/robot.jar -o robot.jar

# Create a wrapper script (Linux/macOS)
echo '#!/bin/sh' > robot
echo "java -jar $(pwd)/robot.jar \"\$@\"" >> robot
chmod +x robot
sudo mv robot /usr/local/bin/robot
```

Requires Java 11+. Verify: `java -version`

#### Convert to OWL Functional Syntax

```bash
# From RDF/XML (.owl, .rdf)
robot convert --input my_ontology.owl --format ofn --output my_ontology.ofn

# From Turtle (.ttl)
robot convert --input my_ontology.ttl --format ofn --output my_ontology.ofn

# From Manchester Syntax (.omn)
robot convert --input my_ontology.omn --format ofn --output my_ontology.ofn

# From OWL/XML (.owx)
robot convert --input my_ontology.owx --format ofn --output my_ontology.ofn
```

Supported input formats: `owl` (RDF/XML), `ttl` (Turtle), `omn` (Manchester), `owx` (OWL/XML), `obo`, `json` (OWL/JSON).

---

## Usage

### Basic Execution

```bash
# Run from the project root
./build/ParserProject [ontology_file.ofn]
```

If no file is specified, `examples/ofn/OWL2RL-10.ofn` is used by default.

### Test Ontologies (OWL2Bench)

The project includes OWL2Bench benchmark ontologies in `examples/ofn`:

| File | Size | Generated by | Use |
|------|------|--------------|-----|
| `OWL2RL-11.ofn` | 206 KB (very small) | Intermediate dataset | Quick testing, debugging |
| `OWL2RL-10.ofn` | 749 KB (small) | Intermediate dataset | **Recommended for development testing** |
| `OWL2RL-1.ofn` | 3.2 MB (large) | OWL2Bench (1 university) | Full benchmarking |
| `OWL2RL-2.ofn` | 6.3 MB (very large) | OWL2Bench (2 universities) | Performance stress testing |

**Note**: Files 11 and 10 are intermediate-size datasets created for practical testing purposes. Files 1 and 2 are official OWL2Bench-generated ontologies where the number corresponds to the **number of universities** in the ontology (1 university = 3.2 MB, 2 universities = 6.3 MB).

### Test Examples

```cpp
// In main.cpp main()

// Add the query here
std::vector<Query> queries = {
    {"obj", "<https://kracr.iiitd.edu.in/OWL2Bench#isMemberOf>"},
    {"obj", "<https://kracr.iiitd.edu.in/OWL2Bench#isPartOf>"},
    {"data", "<https://kracr.iiitd.edu.in/OWL2Bench#hasAge>"},
}
...
{
    ...
    auto space = OWL2::create();
    ParserCowl<OWL2> parser("examples/ofn/OWL2RL-11.ofn", *space);
    parser.load();

    space->realisation();
    space->classification();
    ...
}
```

---

### Query Mapping in owl2chr

The engine maps query types to specific reasoning functions in the `OWL2` space. Each query has a **type** and a **URI**, and the type determines which query function is called.

---

#### Mapping Table

| Query Type       | Function Called                                  | Description |
|-----------------|--------------------------------------------------|-------------|
| `obj`           | `space->queryObjAssertionUri(q.uri)`           | Retrieves all object property assertions for the given URI. Example: all `isMemberOf` relationships. |
| `super`         | `space->querySuperClassOfUri(q.uri)`           | Retrieves all superclasses of a class URI (including `owl:Thing`). |
| `sub`           | `space->querySubClassOfUri(q.uri)`             | Retrieves all subclasses of a class URI. 
| `data`          | `space->queryDataAssertionUri(q.uri)`          | Retrieves all data property assertions for a URI. Example: `hasAge`. |
| `subj`          | `space->querySubjectByObjectUri(q.uri)`        | Retrieves subjects for a given object property. Example: who `isHeadOf` a department. |
| `obj-subject`   | `space->queryObjAssertionSubjectUri(q.uri)` | Retrieves object property assertions with a specific subject. Example: `hasCollegeDiscipline`. |
| `inst`          | `space->queryInstancesURI(q.uri)`              | Retrieves all individuals that are instances of the given class URI. Example: all `T20CricketFan` individuals. |

If a query type is not recognized, the program prints an error message:

```cpp
std::cerr << "Type of query not recognized: " << q.type << std::endl;
```

## Architecture

### Project Structure

```
owlChrpp/
├── owlrules.chrpp         # CHR++ rules
├── owlrules.cpp           # Generated by chrppc from owlrules.chrpp
├── owlrules.hpp           # Header file for OWL2 CHR++ rules 
├── main.cpp               # Main C++ file
├── include                # Header files to include
    ├── parsercowl.h       # COWL parser for OWL 2        
    ├── Parser.h           # Generic parsing interface   
    ├── AnySimpleType.h    # XSD data types   
    ├── constants.h        # Global constant variables (e.g. output files names)   
    ├── types.h            # Variables types definition
    ├── chr_traits.h       # CHR++ structs    
    └── utils.h            # Utility functions   
├── CMakeLists.txt         # Build configuration
├── results/               # File results 
|   └── queries/           # Queries results
├── lib/cowl/              # COWL (Git submodule)
├── build/                 # Build directory (generated)
└── examples/              # Ontologies examples
    ├── ofn                # Examples in ofn format         
    ├── owl                # Examples in owl format    
    ├── ttl                # Examples in ttl format    
    └── json               # Examples in json format    
```

---

## Tests and Benchmarks

### Running CHR++ Tests

Tests are configured in the `main()` function of `main.cpp`. Uncomment the desired task:

#### Classification (CT) — Class Hierarchy

```cpp
space->classification();
```

Generates `res_classification` in `results` folder with all inferred SubClassOf pairs.

#### Realisation (CR) — Individual Types

```cpp
space->realisation();
```

Generates inferred types `res_realisation` in `results`for each individual.

#### SPARQL Queries

```cpp
space->queryObjAssertionUri(std::string("https://kracr.iiitd.edu.in/OWL2Bench#isMemberOf"));
space->queryInstancesURI(std::string("https://kracr.iiitd.edu.in/OWL2Bench#T20CricketFan"));
// ... etc.
```

Results are written to `results/queries/res_queries_{ID}`.

### Recompile and Run

```bash
cd build && make
cd ..
./build/ParserProject examples/ofn/OWL2RL-10.ofn
```

---

## Reference Results (Pellet + Jena)

Reference results were generated with **Pellet** (OWL reasoner) and **Apache Jena** (SPARQL queries).

### Classification — Pellet

```bash
cd owl2bench/
java -jar "Experiments/java runnable jar files/pellet.jar" OWL2RL-10.owl classification > classification_pellet.txt
```

### Realisation — Pellet

```bash
java -jar "Experiments/java runnable jar files/pellet.jar" OWL2RL-10.owl realisation > realisation_pellet.txt
```

### SPARQL Queries — Apache Jena + Pellet

Reference results: `owl2bench/sparql_reference_results/pellet_results/OWL2RL-10/`

---

## Comparing Results

### Classification — compare_classification.py

```bash
python3 compare_classification.py <chrpp_output> <pellet_reference>
```

### Realisation — compare_instances.py

```bash
python3 compare_instances.py <chrpp_output> <gold_file>
```

### SPARQL Queries — compare_query_results.py

```bash
python3 compare_query_results.py <chrpp_sortie_file> <pellet_results_dir>

# Example:
python3 compare_query_results.py sortie.txt ../../../owl2bench/sparql_reference_results/pellet_results/OWL2RL-10
```

---

## Development

### Modifying CHR++ Rules

1. Edit `owlrules.chrpp`
2. Recreate `owlrules.hpp` by doing `chrppc owlrules.chrpp -sout > owlrules.hpp` or `/absolute/path/to/chrppc owlrules.chrpp -sout > owlrules.hpp`
3. Recompile — `owlrules.cpp` is auto-regenerated: `cd build && make` or `cmake --build build --target generate_rules`
3. Commit the updated `owlrules.cpp` if sharing your changes

### Adding a New Query

```chrpp
// In owlrules.chrpp

// 1. Declare the constraint
<chr_constraint>
    myNewQuery(+std::string)
</chr_constraint>

// 2. Add passive deduplication rule
myNewQuery(X) #passive \ myNewQuery(X) <=> true ;;

// 3. Implement query logic
myNewQuery(URI), logicalName(URI,X) ==>
    res(someResult) ;;
```
