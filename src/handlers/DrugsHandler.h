
/* 
 * File:   DrugsHandler.h
 * Author: Maciej Lew <lion.net.pl>
 *
 * Created on 29 marca 2017, 20:33
 */

#ifndef DRUGSHANDLER_H
#define DRUGSHANDLER_H

#include "pistache/http.h"
#include "pistache/endpoint.h"
#include "pistache/description.h"
#include "Handler.h"


using namespace Net;

class DrugsHandler : public Handler {
public:

    DrugsHandler(SettingsParser settings) : Handler(settings) {}
    
    void onRequest(const Rest::Request& request, Net::Http::ResponseWriter response);

private:
    
};

#endif /* DRUGSHANDLER_H */

