/* 
 * File:   ProjectHandler.h
 * Author: Maciej Lew <lion.net.pl>
 *
 * Created on 15 marca 2017, 21:50
 */

#ifndef VERSIONHANDLER_H
#define VERSIONHANDLER_H

#define DDS_VERSION "0.1.2"
#define DDS_NAME "DDS"
#define DDS_FULL_NAME "Drug Dose Server"
#define DDS_LICENSE "MIT"

#include "pistache/http.h"
#include "pistache/endpoint.h"
#include "pistache/description.h"
#include "Handler.h"

using namespace Net;

class ProjectHandler : public Handler {
public:
    
    ProjectHandler(SettingsParser settings) : Handler(settings) {}

    void onRequest(const Rest::Request& request, Net::Http::ResponseWriter response);

private:
    
};

#endif /* VERSIONHANDLER_H */

