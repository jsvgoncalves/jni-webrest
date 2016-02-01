/*
 * Red Hat OpenShift Mobile
 * 2016
 */

#include "OpenshiftAPI.h"

OpenshiftAPI::OpenshiftAPI() {
    something = "A random, outsider, string!";
}

OpenshiftAPI::~OpenshiftAPI() {
}

string OpenshiftAPI::getString() {
    return something;
}