cmake_minimum_required(VERSION 2.8)

aux_source_directory(./binary_tree BINARY_DIR_SRCS)
aux_source_directory(./red_black_tree RED_BLACK_DIR_SRCS)

include_directories(binary_tree)
include_directories(red_black_tree)


set(LIB_BASE
        pthread
        )

add_executable(red_black_tree_basic ${RED_BLACK_DIR_SRCS})
target_link_libraries(red_black_tree_basic ${LIB_BASE})


add_executable(binary_tree_basic ${BINARY_DIR_SRCS})
target_link_libraries(binary_tree_basic ${LIB_BASE})