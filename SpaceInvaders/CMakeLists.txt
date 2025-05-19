cmake_minimum_required(VERSION 3.16)

project(SpaceInvaders VERSION 1.3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(USE_SFML "Build graphical version with SFML" ON)

if (APPLE)
    add_compile_options(-Wall -Wextra -pedantic -Wconversion)
else()
    add_compile_options(-Wall -Wextra -pedantic -Wconversion -static-libstdc++)
endif()

find_package(Curses REQUIRED)
file(GLOB SRC_FILES src/*.cpp)

# ────────────────────── SFML ────────────────────────────────────────────────
set(SFML_LIBS)

if (USE_SFML)
    # 1) пробуем Homebrew-версию 3
    find_package(SFML 3 COMPONENTS Graphics Window System QUIET)

    if (SFML_FOUND)
        list(APPEND SFML_LIBS SFML::Graphics SFML::Window SFML::System)
    else()
        # 2) ищем классическую 2.x
        find_package(SFML 2 COMPONENTS Graphics Window System REQUIRED)
        list(APPEND SFML_LIBS sfml-graphics sfml-window sfml-system)
    endif()
else()
    list(FILTER SRC_FILES EXCLUDE REGEX "SFMLRenderer.cpp")
endif()

# ────────────────────── Executable ─────────────────────────────────────────
add_executable(space_invaders ${SRC_FILES})

target_include_directories(space_invaders PRIVATE
    ${CURSES_INCLUDE_DIR}
)

target_link_libraries(space_invaders PRIVATE
    ${CURSES_LIBRARIES}
    ${SFML_LIBS}
)

if (USE_SFML)
    target_compile_definitions(space_invaders PRIVATE USE_SFML)
endif()
