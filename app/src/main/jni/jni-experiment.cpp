/*
 * Red Hat OpenShift Mobile
 * 2016
 */
#include <string>
#include <jni.h>

using namespace std;

class API{
    public:
        API();
        ~API();
        string getString();
    private:
        string something;
};

API::API() {
    something = "A random string!";
}

API::~API() {
}

string API::getString() {
    return something;
}

extern "C" {

jstring
Java_com_example_jniexperiment_JniExperiment_helloString(JNIEnv *env,
                                                      jobject this_obj) {
    API api;
    return env->NewStringUTF(api.getString().c_str());
}

}