cmake_minimum_required(VERSION 3.24)
project(PJC_CLion)


set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY  https://github.com/fmtlib/fmt
        GIT_TAG a33701196adfad74917046096bf5a2aa0ab0bb50
)

FetchContent_MakeAvailable(fmt)

add_executable(PJC_CLion c01.cpp)
add_executable(PJC_CLion2 c02.cpp)
add_executable(PJC_CLion3 c03.cpp)
add_executable(PJC_CLionCW cwiczenia.cpp)
add_executable(PJC_CLionKR02 kartkowka.cpp)
add_executable(PJC_CLion4 c04.cpp)
target_link_libraries(PJC_CLion3 fmt)
target_link_libraries(PJC_CLionCW fmt)
target_link_libraries(PJC_CLionKR02 fmt)