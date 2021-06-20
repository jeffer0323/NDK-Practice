
#!/bin/bash
 
# 指定编译so支持的最新Android版本
API=21
 
# 工具链目录，  下方的目录随个人电脑不同而不同
TOOLCHAIN=/Users/jeffer/Library/Android/sdk/ndk/21.2.6472646/toolchains/llvm/prebuilt/darwin-x86_64
 
build()
{
./configure \
--prefix=$PREFIX \
--disable-static \
--enable-shared \
--enable-small \
--enable-gpl \
--disable-doc \
--disable-programs \
--disable-avdevice \
--enable-cross-compile \
--target-os=android \
--arch=$CPU \
--cc=$TOOLCHAIN/bin/$ARCH-linux-android$ANDROID_ARCH$API-clang \
--cross-prefix=$TOOLCHAIN/bin/$ARCH2-linux-android$ANDROID_ARCH- 
 
make clean
make -j4
make install
 
}

# armv7a
CPU=armv7
ARCH=armv7a
ARCH2=arm
ANDROID_ARCH=eabi
 
PREFIX=./SO/$CPU

build

# arm64 
CPU=arm64
ARCH=aarch64
ARCH2=aarch64
ANDROID_ARCH=''

PREFIX=./SO/$CPU

build
