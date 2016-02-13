/*
 * Red Hat OpenShift Mobile
 * 2016
 */
#include <jni.h>
#include "openshift/OpenshiftAPI.h"
// #include <android/log.h>


using namespace std;


extern "C" {

jstring
Java_com_example_jniexperiment_JniExperiment_helloString(JNIEnv *env,
                                                      jobject this_obj) {
    // __android_log_print(ANDROID_LOG_VERBOSE, "jniwebrest", "Starting app");

    OpenshiftAPI api;
    return env->NewStringUTF(api.useCurl().c_str());
}

}
