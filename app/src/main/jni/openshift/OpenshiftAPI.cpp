/*
 * Red Hat OpenShift Mobile
 * 2016
 */

#include "OpenshiftAPI.h"
#include <sstream>
#include <iostream>
#include <android/log.h>

OpenshiftAPI::OpenshiftAPI() {
    something = "A random, outsider, string!";
}

OpenshiftAPI::~OpenshiftAPI() {
}


/**
 * A non-threadsafe simple libcURL-easy based HTTP downloader
 */
class HTTPDownloader {
public:
    HTTPDownloader();
    ~HTTPDownloader();
    /**
     * Download a file using HTTP GET and store in in a std::string
     * @param url The URL to download
     * @return The download result
     */
    std::string download(const std::string& url);
private:
    void* curl;
};


size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    string data((const char*) ptr, (size_t) size * nmemb);
    *((stringstream*) stream) << data << endl;
    return size * nmemb;
}

HTTPDownloader::HTTPDownloader() {
    curl = curl_easy_init();
}

HTTPDownloader::~HTTPDownloader() {
    curl_easy_cleanup(curl);
}

string HTTPDownloader::download(const std::string& url) {
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    // Follow redirection
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    // Prevent "longjmp causes uninitialized stack frame" bug
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
    curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "deflate");
    std::stringstream out;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
    // Perform the request, res will get the return code
    CURLcode res = curl_easy_perform(curl);
    // Check for errors
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
        __android_log_print(ANDROID_LOG_VERBOSE, "jniwebrest", "Failed: %d", res);

    }
    __android_log_print(ANDROID_LOG_VERBOSE, "jniwebrest", "Result id: %d", res);

    return out.str();
}

string OpenshiftAPI::useCurl() {
    HTTPDownloader downloader;
    string content = downloader.download("https://openshift.redhat.com/broker/rest/cartridges");
    cout << content << endl;
    __android_log_print(ANDROID_LOG_VERBOSE, "jniwebrest", "cURL content: %s", content.c_str());
    return content;
}
