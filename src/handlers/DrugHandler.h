
/* 
 * File:   DrugHandler.h
 * Author: Maciej Lew <lion.net.pl>
 *
 * Created on 04 kwietnia 2017, 20:14
 */

#ifndef DRUGHANDLER_H
#define DRUGHANDLER_H

#include "pistache/http.h"
#include "pistache/endpoint.h"
#include "pistache/description.h"
#include "Handler.h"


using namespace Net;

class DrugHandler : public Handler {
public:

    DrugHandler(SettingsParser settings) : Handler(settings) {}

    void onRequest(const Rest::Request& request, Net::Http::ResponseWriter response);

private:
    
};

#endif /* DRUGHANDLER_H */

