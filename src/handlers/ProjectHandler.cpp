/* 
 * File:   ProjectHandler.cpp
 * Author: Maciej Lew <lion.net.pl>
 *
 * Created on 14 marca 2017, 21:33
 */

#include "ProjectHandler.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
using namespace rapidjson;

ProjectHandler::ProjectHandler() {
    std::cout << "Constructing ProjectHandler" << std::endl;
}

ProjectHandler::~ProjectHandler() {
    std::cout << "Destructing ProjectHandler" << std::endl;
}

void ProjectHandler::onRequest(const Rest::Request& request, Net::Http::ResponseWriter response) {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.Key("project");
    writer.String("DDS");
    writer.Key("full_name");
    writer.String("Drug Dose Server");
    writer.Key("version");
    writer.String(DDS_VERSION);
    writer.Key("license");
    writer.String("MIT");
    writer.EndObject();
    response.send(Http::Code::Ok, s.GetString());
}