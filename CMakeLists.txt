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

# ── Fichiers CHR source et C++ généré ─────────────────────────────────────────
# owlrules.chr  →  (chrppc)  →  owl.cpp  →  libowl_rules.a
#
# owl.cpp est pré-généré et commité dans le dépôt.
# Pour le régénérer après modification de owlrules.chr :
#   cmake -DCHRPP_ROOT=/chemin/vers/chrpp ..
#   make generate_owl_cpp
set(OWL_CPP  ${CMAKE_SOURCE_DIR}/owlrules.cpp)
set(CHR_FILE ${CMAKE_CURRENT_SOURCE_DIR}/owlrules.chrpp)

if(EXISTS ${CHRPP_COMPILER})
    message(STATUS "CHR++ trouvé : ${CHRPP_COMPILER} — régénération automatique de owl.cpp")
    include_directories(${CHRPP_RUNTIME})

    # Règle de génération : owlrules.chr → owl.cpp
    # Dépend UNIQUEMENT de owlrules.chr, pas de main.cpp ni des headers utils/types.
    add_custom_command(
        OUTPUT  ${OWL_CPP}
        COMMAND ${CHRPP_COMPILER} ${CHR_FILE} -t -sout > ${OWL_CPP}
        DEPENDS ${CHR_FILE}
        COMMENT "Génération de owl.cpp depuis owlrules.chr"
        VERBATIM
    )
else()
    message(STATUS "chrppc non trouvé — utilisation de owl.cpp pré-généré")
    if(EXISTS ${CHRPP_RUNTIME})
        include_directories(${CHRPP_RUNTIME})
    endif()
endif()

# ── Sous-module COWL ──────────────────────────────────────────────────────────
add_subdirectory(lib/cowl EXCLUDE_FROM_ALL)
link_directories(${CMAKE_SOURCE_DIR}/lib/cowl/build/lib/ulib)

# ─────────────────────────────────────────────────────────────────────────────
# TARGET 1 : libowl_rules  (règles CHR compilées une seule fois)
# ─────────────────────────────────────────────────────────────────────────────
# Contient UNIQUEMENT owlrules.cpp (généré depuis owlrules.chr).
# Toute la logique de raisonnement est ici.
# Recompilé seulement si owlrules.chr change.
add_library(owl_rules STATIC
    ${OWL_CPP}
)

target_include_directories(owl_rules
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include          # parsercowl.h, owlrules.h, AnySimpleType.h,
                                     # constants.h, types.h, utils.h, chr_traits.h
        lib/cowl/include
)

target_link_libraries(owl_rules PUBLIC cowl ulib)

# Cible manuelle pour forcer la régénération de owl.cpp
add_custom_target(generate_owl_cpp
    DEPENDS ${OWL_CPP}
    COMMENT "owl.cpp régénéré depuis owlrules.chr"
)

# ─────────────────────────────────────────────────────────────────────────────
# TARGET 2 : ParserProject  (point d'entrée — recompile seulement si main.cpp change)
# ─────────────────────────────────────────────────────────────────────────────
# Contient UNIQUEMENT main.cpp.
# Ne recompile PAS les règles CHR quand main.cpp est modifié.
add_executable(ParserProject
    main.cpp
)

target_include_directories(ParserProject
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include          # mêmes headers que owl_rules
        lib/cowl/include
)

# Lier l'exécutable à la bibliothèque des règles (et transitivement à cowl/ulib)
target_link_libraries(ParserProject PRIVATE owl_rules)