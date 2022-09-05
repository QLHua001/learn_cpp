cmake_minimum_required(VERSION 3.0.0)
project(learn_cpp VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_BUILD_TYPE debug)

include_directories(./include)

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

set(libraries ${OpenCV_LIBS})
set(src ${main} ${SRC_LIST})


set(EXECUTABLE_OUTPUT_PATH ../output)
add_executable(${PROJECT_NAME} ${src})
target_link_libraries(${PROJECT_NAME} ${libraries})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
