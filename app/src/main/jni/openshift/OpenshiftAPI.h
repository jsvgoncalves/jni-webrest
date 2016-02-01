/*
 * Red Hat OpenShift Mobile
 * 2016
 */

#ifndef JNI_EXPERIMENT_OPENSHIFTAPI_H
#define JNI_EXPERIMENT_OPENSHIFTAPI_H

#include <string>

using namespace std;

class OpenshiftAPI {
    public:
        OpenshiftAPI();
        ~OpenshiftAPI();
        string getString();
    private:
        string something;
};


#endif //JNI_EXPERIMENT_OPENSHIFTAPI_H
