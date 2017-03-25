
/* 
 * File:   Endpoint.h
 * Author: Maciej Lew <lion.net.pl>
 *
 * Created on 22 marca 2017, 20:40
 */

#ifndef ENDPOINT_H
#define ENDPOINT_H

#include "pistache/endpoint.h"
#include "handlers/VersionHandler.h"

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
        VersionHandler version_handler;
        
        void setupRoutes() {
            using namespace Net::Rest;
            Routes::Get(router, "/version", Routes::bind(&VersionHandler::onRequest, &version_handler));

        }
};


#endif /* ENDPOINT_H */

