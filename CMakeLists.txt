cmake_minimum_required(VERSION 3.0.0)
project(learn_cpp VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_BUILD_TYPE debug)
# set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

include_directories(./include)
include_directories(./src)

set(libraries )
set(src )

# OpenCV Realease
set(OpenCV_DIR /workplace/package/opencv-3.4.16/output_linux/)
include_directories(${OpenCV_DIR}/include)
link_directories(${OpenCV_DIR}/lib)
set(OpenCV_LIBS libopencv_world.so)



set(main 
    ./main.cpp)

aux_source_directory(./src SRC_LIST)
aux_source_directory(./src/sort/ SRC_LIST)

# data_structures
# list_array
aux_source_directory(./data_structures/list_array SRC_LIST)
# linked_list
aux_source_directory(./data_structures/linked_list SRC_LIST)
# dlinked_list
aux_source_directory(./data_structures/dlinked_list SRC_LIST)

# algorithms
# Search
aux_source_directory(./algorithms/Search SRC_LIST)

# Sort
aux_source_directory(./algorithms/Sort SRC_LIST)

# C_Cpp_Misup
aux_source_directory(./src/C_Cpp_Mixup SRC_LIST)

# Class_Object
aux_source_directory(./src/Class_Object/ SRC_LIST)

# Containers
aux_source_directory(./src/Containers/Array SRC_LIST)
aux_source_directory(./src/Containers/Vector SRC_LIST)
aux_source_directory(./src/Containers/Deque SRC_LIST)
aux_source_directory(./src/Containers/List SRC_LIST)
aux_source_directory(./src/Containers/Forward_List SRC_LIST)
aux_source_directory(./src/Containers/Map SRC_LIST)
aux_source_directory(./src/Containers/Set SRC_LIST)
aux_source_directory(./src/Containers/String SRC_LIST)

# multi_thread
aux_source_directory(./src/multi_thread SRC_LIST)

# Overload
aux_source_directory(./src/Overload SRC_LIST)

# Smart_Pointer
aux_source_directory(./src/Smart_Pointer SRC_LIST)

# Lambda
aux_source_directory(./src/Lambda SRC_LIST)

# List_Initialization
aux_source_directory(./src/List_Initialization SRC_LIST)

# ConstExpr
aux_source_directory(./src/ConstExpr SRC_LIST)

# Const
aux_source_directory(./src/Const SRC_LIST)

# Reference
aux_source_directory(./src/Reference SRC_LIST)

# New_Delete
aux_source_directory(./src/New_Delete SRC_LIST)

# Inline
aux_source_directory(./src/Inline SRC_LIST)

# Regex
aux_source_directory(./src/Regex SRC_LIST)

# TypeID
aux_source_directory(./src/TypeID SRC_LIST)

# leetcode
aux_source_directory(./lt/ SRC_LIST)

set(libraries ${OpenCV_LIBS})
set(src ${main} ${SRC_LIST})


set(EXECUTABLE_OUTPUT_PATH ../output)
add_executable(${PROJECT_NAME} ${src})
target_link_libraries(${PROJECT_NAME} ${libraries})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
