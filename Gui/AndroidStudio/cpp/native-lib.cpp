#include <jni.h>
#include <string>
#include <year.hpp>
#include <iostream>
#include <android/log.h>


// DisplayMonth JNI calls
extern "C"
JNIEXPORT jstring JNICALL
Java_com_kwrp_planner_1gui_DisplayMonth_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "1";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL Java_com_kwrp_planner_1gui_DisplayMonth_testJNI(
        JNIEnv *env,
        jobject /* this */) {
    Year year("29/10/1991");
    std::string date = year.getDate();
    return env->NewStringUTF(date.c_str());
}


// DisplayDay JNI calls
extern "C"
JNIEXPORT jstring JNICALL Java_com_kwrp_planner_1gui_DisplayDay_jniGetCurrentDate(
        JNIEnv *env,
        jobject /* this */) {
    Day *date = new Day();
    return env->NewStringUTF((date->getDate()).data());
}
// DisplayDay JNI calls
extern "C"
JNIEXPORT jstring JNICALL Java_com_kwrp_planner_1gui_DisplayMonth_jniGetCurrentDate(
        JNIEnv *env,
        jobject /* this */) {
    Day *date = new Day();
    return env->NewStringUTF((date->getDate()).data());
}


extern "C"
JNIEXPORT jstring JNICALL Java_com_kwrp_planner_1gui_DisplayDay_jniGetEvents(
        JNIEnv *env,
        jobject /* this */) {

    std::string e = "Hello World";
    return env->NewStringUTF(e.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL Java_com_kwrp_planner_1gui_DisplayDay_jniGetDay(
        JNIEnv *env,
        jobject /* this */) {
    Day *day = new Day();
    std::string e = day->getDate();
    return env->NewStringUTF(e.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL Java_com_kwrp_planner_1gui_DisplayDay_jniCreateEvent(
        JNIEnv *env, jobject,
        jstring title, jstring description, jstring start, jstring duration) {
    std::string confirm = "Event Created";
    return env->NewStringUTF(confirm.c_str());
}



