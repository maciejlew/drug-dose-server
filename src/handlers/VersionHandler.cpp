/* 
 * File:   VersionHandler.cpp
 * Author: Maciej Lew <lion.net.pl>
 *
 * Created on 14 marca 2017, 21:33
 */

#include "VersionHandler.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
using namespace rapidjson;

VersionHandler::VersionHandler() {
    std::cout << "Constructing VersionHandler" << std::endl;
}

VersionHandler::~VersionHandler() {
    std::cout << "Destructing VersionHandler" << std::endl;
}

void VersionHandler::onRequest(const Rest::Request& request, Net::Http::ResponseWriter response) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.Key("project");
    writer.String("DDS");
    writer.Key("version");
    writer.String(DDS_VERSION);
    writer.EndObject();
    response.send(Http::Code::Ok, s.GetString());
}