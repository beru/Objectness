project(BING_linux)
cmake_minimum_required(VERSION 2.6)

find_package(OpenMP REQUIRED)

add_library(LIBLINEAR LibLinear/linear.cpp LibLinear/linear.h LibLinear/train.c LibLinear/tron.cpp LibLinear/tron.h)
add_library(BLAS LibLinear/blas/blas.h LibLinear/blas/blasp.h LibLinear/blas/daxpy.c LibLinear/blas/ddot.c LibLinear/blas/dnrm2.c LibLinear/blas/dscal.c)

file( GLOB LIB_SOURCES *.cpp )
file( GLOB LIB_HEADERS *.h )
add_library( ${PROJECT_NAME} ${LIB_SOURCES} ${LIB_HEADERS} )

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file( GLOB APP_SOURCES apps/*.cpp )
foreach( testsourcefile ${APP_SOURCES} )
    # I used a simple string replace, to cut off .cpp.
    GET_FILENAME_COMPONENT(testname ${testsourcefile} NAME_WE)
    add_executable(${testname} ${testsourcefile})
    # Make sure YourLib is linked to each app
    target_link_libraries(${testname} ${PROJECT_NAME} LIBLINEAR BLAS opencv_core opencv_imgproc opencv_highgui)
endforeach( testsourcefile ${APP_SOURCES} )

list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -fopenmp -ftree-vectorize")
#list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -fopenmp -ftest-coverage -fprofile-arcs")

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wno-deprecated")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}  -Wno-deprecated")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wno-deprecated")
#set(CMAKE_BUILD_TYPE 'release')
set(CMAKE_BUILD_TYPE "Debug")

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}  -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
