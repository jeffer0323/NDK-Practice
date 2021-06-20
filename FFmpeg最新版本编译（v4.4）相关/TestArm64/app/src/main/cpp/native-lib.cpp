#include <jni.h>
#include <string>
extern  "C"{
#include <libavcodec/avcodec.h>
}
extern "C" JNIEXPORT jstring JNICALL
Java_edu_moocany_testarm64_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = avcodec_configuration();
    //std::string hello = av_version_info();
    return env->NewStringUTF(hello.c_str());

}
