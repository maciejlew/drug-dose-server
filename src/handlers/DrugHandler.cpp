/* 
 * File:   DrugHandler.cpp
 * Author: Maciej Lew <lion.net.pl>
 *
 * Created on 04 kwietnia 2017, 20:14
 */

#include "DrugHandler.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/filereadstream.h"
#include <cstdio>
using namespace rapidjson;

DrugHandler::DrugHandler() {
    std::cout << "Constructing DrugHandler" << std::endl;
}

DrugHandler::~DrugHandler() {
    std::cout << "Destructing DrugHandler" << std::endl;
}

void DrugHandler::onRequest(const Net::Rest::Request& request, Net::Http::ResponseWriter response) {
    Document config;
    char _config_buffer[65536];
    
    FILE* config_pointer = fopen("config.json", "r");
    FileReadStream config_stream(config_pointer, _config_buffer, sizeof(_config_buffer));
    config.ParseStream(config_stream);
    fclose(config_pointer);
    
    if (config.HasMember("files_path")) {
        
        auto id = request.param(":id").as<std::string>();
        
        std::ostringstream s;
        s << config["files_path"].GetString() << "/" << id << ".json";
        
        std::cout << s.str() << std::endl;
        
        Http::serveFile(response, s.str().c_str(), MIME(Application, Json));
            
    } else {
        response.send(Http::Code::Internal_Server_Error);
    }
}
