/* 
 * File:   VersionHandler.cpp
 * Author: Maciej Lew <lion.net.pl>
 *
 * Created on 14 marca 2017, 21:33
 */

#include "VersionHandler.h"

VersionHandler::VersionHandler() {
    std::cout << "Constructing VersionHandler" << std::endl;
}

VersionHandler::~VersionHandler() {
    std::cout << "Destructing VersionHandler" << std::endl;
}

void VersionHandler::onRequest(const Rest::Request& request, Net::Http::ResponseWriter response) {
    response.send(Http::Code::Ok, "DDS " DDS_VERSION);
}