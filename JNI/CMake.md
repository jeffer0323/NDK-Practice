### CMake

---

##### 1.静态库&动态库

静态库：.a(.o)文件，编译期的时候，把静态库完整全部Copy一份去执行的

动态库：.so文件，运行的时候，才会去加载，而且只加载一次(System.loadLIbary(xx.so))，当加载一次之后，在内存中存在副本

编译在Android平台可用的动静态库则需要使用NDK工具链来编译



##### 2.CmakeLists

一般配置：

```Cmake
# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

file(GLOB allCpp ${CMAKE_SOURCE_DIR}/*.cpp)
# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             ${allCpp} )



# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# 引入FFmpeg的头文件
include_directories(${CMAKE_SOURCE_DIR}/include)


# 引入FFmpeg的库文件，设置内部的方式引入，指定库的目录是 -L  指定具体的库-l
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/jni/${CMAKE_ANDROID_ARCH_ABI}")


# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib
                       avfilter avformat avcodec avutil swresample swscale
                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} z)
```

更多配置细节：

可参见cmake官网