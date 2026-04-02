cmake_minimum_required(VERSION 3.14)
project(ParserProject LANGUAGES C CXX)

# ── C++17 Standard ────────────────────────────────────────────────────────────
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

# ── CHR++ paths ───────────────────────────────────────────────────────────────
if(NOT DEFINED CHRPP_ROOT)
    if(DEFINED ENV{CHRPP_ROOT})
        set(CHRPP_ROOT "$ENV{CHRPP_ROOT}")
    else()
        set(CHRPP_ROOT "${CMAKE_SOURCE_DIR}/../chrpp")
    endif()
endif()
set(CHRPP_COMPILER      ${CHRPP_ROOT}/chrppc/chrppc)
set(CHRPP_RUNTIME       ${CHRPP_ROOT}/runtime)
set(CHRPP_RUNTIME_BUILD ${CHRPP_ROOT}/build/runtime)

# ── CHR++ source and generated C++ files ──────────────────────────────────────
set(CHR_FILE     ${CMAKE_CURRENT_SOURCE_DIR}/owlrules.chrpp)
set(OWL2_CPP     ${CMAKE_CURRENT_SOURCE_DIR}/owlrulesOWL2.cpp)
set(OWL2_HH      ${CMAKE_CURRENT_SOURCE_DIR}/owlrulesOWL2.hh)
set(OWL2_CHR_CPP ${CMAKE_CURRENT_SOURCE_DIR}/owlrules_chr.cpp)
set(OWL2_O       ${CMAKE_CURRENT_BINARY_DIR}/owlrulesOWL2.o)

# ── Submodule COWL ────────────────────────────────────────────────────────── 
add_subdirectory(lib/cowl EXCLUDE_FROM_ALL) 
link_directories(${CMAKE_SOURCE_DIR}/lib/cowl/build/lib/ulib)

# ── Generate C++ files from CHR++ ─────────────────────────────────────────────
if(EXISTS ${CHRPP_COMPILER})
    message(STATUS "CHR++ found: ${CHRPP_COMPILER} - generating C++ files from ${CHR_FILE}")
    # Include CHR++ runtime headers for the generated .cpp file
    include_directories(${CHRPP_RUNTIME})
    add_custom_command(
        OUTPUT ${OWL2_CPP} ${OWL2_HH}
        COMMAND ${CHRPP_COMPILER} --output_dir ${CMAKE_CURRENT_SOURCE_DIR} ${CHR_FILE}
        COMMAND ${CMAKE_COMMAND} -E remove ${OWL2_CHR_CPP}
        DEPENDS ${CHR_FILE}
        COMMENT "Generating owlrulesOWL2.cpp/.hh from owlrules.chrpp"
        VERBATIM
    )
else()
    message(FATAL_ERROR "chrppc not found: ${CHRPP_COMPILER}")
endif()

# ── Compile generated .o with explicit include paths ──────────────────────────

add_custom_command(
    OUTPUT ${OWL2_O}
    COMMAND ${CMAKE_CXX_COMPILER} -c
        -I${CMAKE_CURRENT_SOURCE_DIR} 
        -I${CHRPP_RUNTIME} 
        -I${CHRPP_RUNTIME_BUILD} 
        -I${CMAKE_SOURCE_DIR}/lib/cowl/include 
        -I${CMAKE_SOURCE_DIR}/lib/cowl/lib/ulib/include 
        ${OWL2_CPP} -o ${OWL2_O}
    DEPENDS ${OWL2_CPP} ${OWL2_HH}
    COMMENT "Compiling owlrulesOWL2.o with all include paths"
    VERBATIM
)

# ── Static library owl_rules ──────────────────────────────────────────────────
add_library(owl_rules STATIC ${OWL2_O})
set_target_properties(owl_rules PROPERTIES LINKER_LANGUAGE CXX)
add_custom_target(generate_rules
    DEPENDS ${OWL2_CPP} ${OWL2_HH}
)
add_dependencies(owl_rules generate_rules)

# # Static library using the object files
# add_library(owl_rules STATIC $<TARGET_OBJECTS:owl_rules_obj>)

# ── Main executable ParserProject ─────────────────────────────────────────────

add_executable(ParserProject  main.cpp)
target_include_directories(ParserProject
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}          # owlrulesOWL2.hh
        ${CMAKE_SOURCE_DIR}/include          # project headers
        ${CHRPP_RUNTIME}
        ${CHRPP_RUNTIME_BUILD}
        ${CMAKE_SOURCE_DIR}/lib/cowl/include
        ${CMAKE_SOURCE_DIR}/lib/cowl/lib/ulib/include
)

target_link_libraries(ParserProject PRIVATE cowl ulib owl_rules)