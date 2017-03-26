/* 
 * File:   ProjectHandler.h
 * Author: Maciej Lew <lion.net.pl>
 *
 * Created on 15 marca 2017, 21:50
 */

#ifndef VERSIONHANDLER_H
#define VERSIONHANDLER_H

#define DDS_VERSION "0.1.1"

#include "pistache/http.h"
#include "pistache/endpoint.h"
#include "pistache/description.h"

using namespace Net;

class ProjectHandler {
public:

    ProjectHandler();

    ~ProjectHandler();

    void onRequest(const Rest::Request& request, Net::Http::ResponseWriter response);

private:
    
};

#endif /* VERSIONHANDLER_H */

