# Sets the minimum version of CMake required to build the native
# library. You should either keep the default value or only pass a
# value of 3.4.0 or lower.

cmake_minimum_required(VERSION 3.4.1)

set(opencv_root_dir ${CMAKE_SOURCE_DIR})
set(INC_DIR ${opencv_root_dir}/include)

set(opencv_lib_dir ${opencv_root_dir}/prebuilt)

set(SOURCE_FILES    src/main/cpp/native-lib.cpp
                    src/main/cpp/com_niu_flvthumbnail_FlvUtil.h
                    src/main/cpp/com_niu_flvthumbnail_FlvUtil.cpp
                           )

#添加头文件目录
include_directories(${INC_DIR})

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds it for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.
             ${SOURCE_FILES} )

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

#添加外部动态链接库
add_library(lib_opencv SHARED IMPORTED)
set_target_properties(lib_opencv PROPERTIES IMPORTED_LOCATION
                 ${opencv_lib_dir}/${ANDROID_ABI}/libopencv_java3.so)

target_link_libraries(native-lib lib_opencv)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because system libraries are included in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.



# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in the
# build script, prebuilt third-party libraries, or system libraries.

#target_link_libraries( # Specifies the target library.
#                      native-lib

                       # Links the target library to the log library
                       # included in the NDK.
#                       ${log-lib} )
