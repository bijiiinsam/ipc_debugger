cmake_minimum_required(VERSION 3.10)
project(ipc_debugger C)

set(CMAKE_C_STANDARD 11)

add_executable(ipc_debugger
        main.c
        logger.c
        simulator.c
        analyzer.c
        ui.c
)

target_link_libraries(ipc_debugger pthread)
