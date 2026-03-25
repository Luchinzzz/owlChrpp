cmake_minimum_required(VERSION 3.14)

project(ParserProject LANGUAGES C CXX)

# ── Standard C++17 ────────────────────────────────────────────────────────────
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ── Build type ────────────────────────────────────────────────────────────────
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# ── Warnings ──────────────────────────────────────────────────────────────────
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    add_compile_options(-Wall -Wpedantic)
endif()

# === Profilage gprof (décommenter si besoin) ==================================
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")

# === Traces CHR++ (décommenter si besoin) =====================================
# add_compile_definitions(TRACE_ON)

# ── Localisation de CHR++ ─────────────────────────────────────────────────────
if(NOT DEFINED CHRPP_ROOT)
    if(DEFINED ENV{CHRPP_ROOT})
        set(CHRPP_ROOT "$ENV{CHRPP_ROOT}")
    else()
        set(CHRPP_ROOT "${CMAKE_SOURCE_DIR}/../chrpp")
    endif()
endif()
set(CHRPP_COMPILER ${CHRPP_ROOT}/chrppc/chrppc)
set(CHRPP_RUNTIME  ${CHRPP_ROOT}/runtime)
set(CHRPP_RUNTIME_BUILD ${CHRPP_ROOT}/build/runtime)

# ── Fichiers CHR source et C++ générés ────────────────────────────────────────
# owlrules.chrpp  →  (chrppc --output_dir .)  →  owlrulesOWL2.cpp
#                                                 owlrulesOWL2.hh
#                                                 owlrules_chr.cpp  (ignoré)
set(CHR_FILE     ${CMAKE_CURRENT_SOURCE_DIR}/owlrules.chrpp)
set(OWL2_CPP     ${CMAKE_CURRENT_SOURCE_DIR}/owlrulesOWL2.cpp)
set(OWL2_HH      ${CMAKE_CURRENT_SOURCE_DIR}/owlrulesOWL2.hh)
set(OWL2_CHR_CPP ${CMAKE_CURRENT_SOURCE_DIR}/owlrules_chr.cpp)

# ── Sous-module COWL ──────────────────────────────────────────────────────────
add_subdirectory(lib/cowl EXCLUDE_FROM_ALL)

# Chemins vers les bibliothèques statiques COWL et ulib
set(COWL_LIB ${CMAKE_SOURCE_DIR}/build/lib/cowl/libcowl.a)
set(ULIB_LIB ${CMAKE_SOURCE_DIR}/build/lib/cowl/lib/ulib/ulib.a)

# ─────────────────────────────────────────────────────────────────────────────
# GÉNÉRATION : owlrules.chrpp → owlrulesOWL2.cpp + owlrulesOWL2.hh
# ─────────────────────────────────────────────────────────────────────────────
if(EXISTS ${CHRPP_COMPILER})
    message(STATUS "CHR++ trouvé : ${CHRPP_COMPILER} — génération de owlrulesOWL2.cpp/.hh")

    add_custom_command(
        OUTPUT  ${OWL2_CPP} ${OWL2_HH} ${OWL2_CHR_CPP}
        COMMAND ${CHRPP_COMPILER} --output_dir ${CMAKE_CURRENT_SOURCE_DIR} ${CHR_FILE}
        COMMAND ${CMAKE_COMMAND} -E remove ${OWL2_CHR_CPP}
        DEPENDS ${CHR_FILE}
        COMMENT "Génération de owlrulesOWL2.cpp/.hh depuis owlrules.chrpp"
        VERBATIM
    )
else()
    message(STATUS "chrppc non trouvé — utilisation de owlrulesOWL2.cpp/.hh pré-générés")
    set(OWL2_CPP ${CMAKE_CURRENT_SOURCE_DIR}/owlrulesOWL2.cpp)
    set(OWL2_HH  ${CMAKE_CURRENT_SOURCE_DIR}/owlrulesOWL2.hh)
endif()

# Cible manuelle pour forcer la régénération
add_custom_target(generate_owl_cpp
    DEPENDS ${OWL2_CPP} ${OWL2_HH}
    COMMENT "owlrulesOWL2.cpp/.hh régénérés depuis owlrules.chrpp"
)

# ─────────────────────────────────────────────────────────────────────────────
# TARGET 1 : libowl_rules  (owlrulesOWL2.cpp compilé séparément → .o → .a)
# Recompilé seulement si owlrules.chrpp change.
# ─────────────────────────────────────────────────────────────────────────────
add_library(owl_rules STATIC
    ${OWL2_CPP}
)

target_include_directories(owl_rules
    PUBLIC
        ${CMAKE_CURRENT_BINARY_DIR}          # owlrulesOWL2.hh (généré)
        ${CMAKE_SOURCE_DIR}/include          # parsercowl.h, owlrules.h, etc.
        ${CHRPP_RUNTIME}                     # ../chrpp/runtime
        ${CHRPP_RUNTIME_BUILD}               # ../chrpp/build/runtime
        lib/cowl/include
        lib/cowl/lib/ulib/include
)

target_link_libraries(owl_rules PUBLIC cowl ulib)

# ─────────────────────────────────────────────────────────────────────────────
# TARGET 2 : ParserProject  (main.cpp + linkage con owl_rules)
# Recompila solo main.cpp quando cambia, non le regole CHR.
# ─────────────────────────────────────────────────────────────────────────────
add_executable(ParserProject
    main.cpp
)

target_include_directories(ParserProject
    PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}          # owlrulesOWL2.hh — da includere in main.cpp
        ${CMAKE_SOURCE_DIR}/include
        ${CHRPP_RUNTIME}
        ${CHRPP_RUNTIME_BUILD}
        lib/cowl/include
        lib/cowl/lib/ulib/include
)

# ── Création des dossiers results et results/queries ─────────────────────────
add_custom_target(create_output_dirs ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/results
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/results/queries
    COMMENT "Création des dossiers results/ et results/queries/"
)

# ParserProject dépend de la création des dossiers
add_dependencies(ParserProject create_output_dirs)

# Lier l'exécutable à owl_rules (e transitivamente a cowl/ulib)
target_link_libraries(ParserProject PRIVATE owl_rules)