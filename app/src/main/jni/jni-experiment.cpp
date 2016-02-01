/*
 * Red Hat OpenShift Mobile
 * 2016
 */
#include <string>
#include <jni.h>

using namespace std;

extern "C" {

jstring
Java_com_example_jniexperiment_JniExperiment_helloString(JNIEnv *env,
                                                      jobject this_obj) {

    string str = "Hello yet again, maybe?";
    return env->NewStringUTF((const char *) str.c_str());
}

}