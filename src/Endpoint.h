
/* 
 * File:   Endpoint.h
 * Author: Maciej Lew <lion.net.pl>
 *
 * Created on 22 marca 2017, 20:40
 */

#ifndef ENDPOINT_H
#define ENDPOINT_H

#include "pistache/endpoint.h"
#include "handlers/DrugsHandler.h"
#include "handlers/ProjectHandler.h"

class Endpoint
{
    
public:
    
    Endpoint(Net::Address addr)
        : httpEndpoint(std::make_shared<Net::Http::Endpoint>(addr))
    {
    }
    
    void init(size_t thr = 2) {
        auto opts = Net::Http::Endpoint::options()
            .threads(thr)
            .flags(Net::Tcp::Options::InstallSignalHandler);
        httpEndpoint->init(opts);
        setupRoutes();
    }

    void start() {
        httpEndpoint->setHandler(router.handler());
        httpEndpoint->serve();
    }
        
    void shutdown() {
        httpEndpoint->shutdown();
    }
        
    private:
        
        Rest::Router router;
        std::shared_ptr<Net::Http::Endpoint> httpEndpoint;
        ProjectHandler version_handler;
        DrugsHandler drugs_handler;
        
        void setupRoutes() {
            using namespace Net::Rest;
            Routes::Get(router, "/", Routes::bind(&ProjectHandler::onRequest, &version_handler));
            Routes::Get(router, "/drugs", Routes::bind(&DrugsHandler::onRequest, &drugs_handler));
        }
};


#endif /* ENDPOINT_H */

