/* 
 * File:   main.cpp
 * Author: Maciej Lew <lion.net.pl>
 *
 * Created on 12 marca 2017, 16:35
 */

#include <cstdlib>

#include "pistache/endpoint.h"

#define DDS_VERSION "0.1.0"

using namespace Net;

class VersionHandler : public Http::Handler {
public:

    HTTP_PROTOTYPE(VersionHandler)

    void onRequest(const Http::Request& request, Http::ResponseWriter response) {
         response.send(Http::Code::Ok, "DDS " DDS_VERSION);
    }
};

int main() {
    Http::listenAndServe<VersionHandler>("*:9080");
}

