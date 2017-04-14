/* 
 * File:   DrugsHandler.cpp
 * Author: Maciej Lew <lion.net.pl>
 *
 * Created on 28 marca 2017, 20:33
 */

#include "DrugsHandler.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/filereadstream.h"
#include <cstdio>
using namespace rapidjson;

DrugsHandler::DrugsHandler() {
    std::cout << "Constructing DrugsHandler" << std::endl;
}

DrugsHandler::~DrugsHandler() {
    std::cout << "Destructing DrugsHandler" << std::endl;
}

void DrugsHandler::onRequest(const Net::Rest::Request& request, Net::Http::ResponseWriter response) {
    
    Document config;
    char _config_buffer[65536];
    
    FILE* config_pointer = fopen("config.json", "r");
    FileReadStream config_stream(config_pointer, _config_buffer, sizeof(_config_buffer));
    config.ParseStream(config_stream);
    fclose(config_pointer);
    
    if (config.HasMember("files_path")) {
        
        std::ostringstream s;
        s << config["files_path"].GetString() << "/drugs.json";
        
        Http::serveFile(response, s.str().c_str(), MIME(Application, Json));
            
    } else {
        response.send(Http::Code::Internal_Server_Error);
    }
    
}
