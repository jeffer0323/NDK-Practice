# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)
project("testarm64")
# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
# 搜索指定的预构建库并将路径存储为变量。
# 由于CMake默认情况下在搜索路径中包括系统库，因此您只需要指定要添加的公共NDK库的名称即可。
# CMake在完成其构建之前会验证该库是否存在。
find_library(
        # 设置路径变量的名称
        log-lib

        # 指定您要CMake查找的NDK库的名称。
        log)

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~FFmpeg~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#

# 引入FFmpeg的头文件
include_directories(${CMAKE_SOURCE_DIR}/include)

# 方式一
# 引入FFmpeg的库文件，设置内部的方式引入，指定库的目录是 -L  指定具体的库-l
# 这种方式方便快捷
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/../jniLibs/${CMAKE_ANDROID_ARCH_ABI}")

# 方式二
#设置ffmpeg动态库所在路径的变量
#set(FF ${CMAKE_SOURCE_DIR}/libs/${CMAKE_ANDROID_ARCH_ABI})
#
#add_library(avcodec SHARED IMPORTED)
#set_target_properties(avcodec PROPERTIES IMPORTED_LOCATION ${FF}/libavcodec.so)
#
#add_library(avformat SHARED IMPORTED)
#set_target_properties(avformat PROPERTIES IMPORTED_LOCATION ${FF}/libavformat.so)
#
#add_library(avutil SHARED IMPORTED)
#set_target_properties(avutil PROPERTIES IMPORTED_LOCATION ${FF}/libavutil.so)
#
#add_library(swscale SHARED IMPORTED)
#set_target_properties(swscale PROPERTIES IMPORTED_LOCATION ${FF}/libswscale.so)
#
#add_library(swresample SHARED IMPORTED)
#set_target_properties(swresample PROPERTIES IMPORTED_LOCATION ${FF}/libswresample.so)
#
#add_library(avfilter SHARED IMPORTED)
#set_target_properties(avfilter PROPERTIES IMPORTED_LOCATION ${FF}/libavfilter.so)
#
#add_library(postproc SHARED IMPORTED)
#set_target_properties(postproc PROPERTIES IMPORTED_LOCATION ${FF}/libpostproc.so)

#找到包含所有cpp的文件
file(GLOB allCpp ${CMAKE_SOURCE_DIR}/*.cpp)

# 创建并命名一个库，将其设置为STATIC或SHARED，并提供其源代码的相对路径
# 您可以定义多个库，而CMake会为您构建它们
# Gradle会自动将共享库与您的APK打包在一起
message("allCpp = ${allCpp}")
add_library(
        # 设置库的名称
        native-lib

        # 将库设置为共享库
        SHARED

        # 提供源文件的相对路径
        ${allCpp})

# 链接库 指定库CMake应该链接到您的目标库。您可以链接多个库，
# 例如您在此构建脚本中定义的库，预构建的第三方库或系统库。
target_link_libraries(
        native-lib
        log
        avfilter
        avformat
        swresample
        swscale
        avutil
        avcodec
        postproc
)
