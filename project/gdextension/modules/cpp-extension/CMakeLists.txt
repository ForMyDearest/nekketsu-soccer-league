set(LIBNAME "CPP-EXTENSION" CACHE STRING "The name of the library")

file(GLOB_RECURSE SOURCES "private/*.cpp")
file(GLOB_RECURSE HEADERS "public/*.hpp")

add_library(${LIBNAME} SHARED)

target_include_directories(${LIBNAME} PUBLIC public)

target_sources(
    ${LIBNAME}
    PRIVATE
    ${SOURCES}
    ${HEADERS}
)

# Fetch a list of the xml files to use for documentation and add to our target
file(GLOB_RECURSE DOC_XML LIST_DIRECTORIES NO CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/doc_classes/*.xml")

# conditionally add doc data to compile output
if (DOC_XML)
    if (GODOTCPP_TARGET MATCHES "editor|template_debug")
        target_doc_sources(${LIBNAME} ${DOC_XML})
    endif ()
endif ()

target_link_libraries(${LIBNAME} PUBLIC godot-cpp)

set_target_properties(
    ${LIBNAME}
    PROPERTIES
    # The generator expression here prevents msvc from adding a Debug or Release subdir.
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/${GODOTCPP_PLATFORM}"
    PREFIX ""
    OUTPUT_NAME "${LIBNAME}${GODOTCPP_SUFFIX}"
)