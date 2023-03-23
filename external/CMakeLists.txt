cmake_minimum_required(VERSION 3.14)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

set(SDL_TEST OFF CACHE BOOL "" FORCE)
set(SDL_STATIC OFF CACHE BOOL "" FORCE)
set(SDL_SHARED ON CACHE BOOL "" FORCE)

add_subdirectory(googletest)
add_subdirectory(SDL)