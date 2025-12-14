cmake_minimum_required(VERSION 3.20)
project(mindseye_ledger_http LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# ---- HTTP server: cpp-httplib (header-only) ----
FetchContent_Declare(
  httplib
  GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
  GIT_TAG v0.16.3
)
FetchContent_MakeAvailable(httplib)

# ---- Submodules ----
add_subdirectory(external/mindseye-ledger-core)

add_executable(mindseye_ledger_http
  src/main.cpp
  src/server.cpp
  src/routes.cpp
  src/sse_bus.cpp
  src/handlers/health.cpp
  src/handlers/append.cpp
  src/handlers/latest.cpp
  src/handlers/blocks.cpp
  src/handlers/verify.cpp
  src/handlers/proof.cpp
)

target_include_directories(mindseye_ledger_http
  PUBLIC
    include
)

target_include_directories(mindseye_ledger_http
  PRIVATE
    ${httplib_SOURCE_DIR}
)

target_link_libraries(mindseye_ledger_http
  PRIVATE
    mindseye_ledger_core
)

if (MSVC)
  target_compile_options(mindseye_ledger_http PRIVATE /W4)
else()
  target_compile_options(mindseye_ledger_http PRIVATE -Wall -Wextra -Wpedantic)
endif()
