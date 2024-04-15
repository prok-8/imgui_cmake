# SPDX-FileCopyrightText: 2024 Podpečan Rok <podpecanrok111@gmail.com>
# SPDX-License-Identifier: MIT

include(FetchContent)

add_executable(imgui_cmake_tests main.cpp)
target_link_libraries(imgui_cmake_tests PRIVATE imgui_cmake)