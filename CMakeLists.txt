cmake_minimum_required(VERSION 3.10)

set(CppStudy_PROJECT_NAME cpplearn)
set(SOURCE_DIR src)
set(SOURCE ${SOURCE_DIR}/main.cpp)
#file(GLOB SOURCES ./src/*.cpp)
set(LIBRARIES_DIR libs)
set(LIBRARIES
        singleLinkedList
        )

project(
        ${CppStudy_PROJECT_NAME}
        VERSION 1.0.0
        DESCRIPTION "to study For CPP and Cmake Project"
        LANGUAGES CXX
)

add_executable(${CppStudy_PROJECT_NAME} ${SOURCE})

# LIBRARY
foreach (LIBRARY ${LIBRARIES})
    add_subdirectory("${LIBRARIES_DIR}/${LIBRARY}")
endforeach (LIBRARY)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})

# Examples / Exercise
file(GLOB EXERCISE_HEADER_FILES "Exercise/*.hpp")
file(GLOB EXERCISE_INLINE_FILES "Exercise/*.inl")
file(GLOB EXERCISE_SOURCE_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/Exercise" "Exercise/*.cpp")
foreach (EXERCISE_SOURCE_FILE ${EXERCISE_SOURCE_FILES})
    string(REGEX REPLACE "(.*)\\.cpp" "\\1" EXERCISE_NAME ${EXERCISE_SOURCE_FILE})
    set(EXERCISE_TARGET "cpp-exercise-${EXERCISE_NAME}")
    add_executable(${EXERCISE_TARGET} ${EXERCISE_HEADER_FILES} ${EXERCISE_INLINE_FILES} "Exercise/${EXERCISE_SOURCE_FILE}")
    set_target_properties(${EXERCISE_TARGET} PROPERTIES COMPILE_FLAGS "${PEDANTIC_COMPILE_FLAGS}" FOLDER "Exercise")
    target_link_libraries(${EXERCISE_TARGET} ${LIBRARIES})
    list(APPEND INSTALL_TARGETS ${EXERCISE_TARGET})
    list(APPEND INSTALL_TARGETS_PDB ${EXERCISE_TARGET})
endforeach ()