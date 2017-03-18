/* 
 * File:   VersionHandler.h
 * Author: Maciej Lew <lion.net.pl>
 *
 * Created on 15 marca 2017, 21:50
 */

#ifndef VERSIONHANDLER_H
#define VERSIONHANDLER_H

#define DDS_VERSION "0.1.1"

#include "pistache/endpoint.h"

using namespace Net;

class VersionHandler : public Http::Handler {
public:

    VersionHandler();

    ~VersionHandler();

    HTTP_PROTOTYPE(VersionHandler)

    void onRequest(const Http::Request& request, Http::ResponseWriter response);

private:

};

#endif /* VERSIONHANDLER_H */

