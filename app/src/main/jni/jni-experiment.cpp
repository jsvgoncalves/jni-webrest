/*
 * Red Hat OpenShift Mobile
 * 2016
 */
#include <string>
#include <jni.h>
#include "openshift/OpenshiftAPI.h"


using namespace std;


extern "C" {

jstring
Java_com_example_jniexperiment_JniExperiment_helloString(JNIEnv *env,
                                                      jobject this_obj) {
    OpenshiftAPI api;
    //return env->NewStringUTF(api.getString().c_str());
    return env->NewStringUTF(api.useCurl().c_str());
}

}