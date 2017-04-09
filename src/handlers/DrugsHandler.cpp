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
    
    Document drugs, config;
    char _drugs_buffer[65536], _config_buffer[65536], _files_path_buffer[65536];
    StringBuffer drugs_buffer;
    
    FILE* config_pointer = fopen("config.json", "r");
    FileReadStream config_stream(config_pointer, _config_buffer, sizeof(_config_buffer));
    config.ParseStream(config_stream);
    fclose(config_pointer);
    
    if (config.HasMember("files_path")) {
        
        sprintf(_files_path_buffer, "%s/drugs.json", config["files_path"].GetString());
        FILE* drugs_pointer = fopen(_files_path_buffer, "r");
        
        if (drugs_pointer) {
            FileReadStream drugs_stream(drugs_pointer, _drugs_buffer, sizeof(_drugs_buffer));
            drugs.ParseStream(drugs_stream);
            fclose(drugs_pointer);

            Writer<StringBuffer> writer(drugs_buffer);
            drugs.Accept(writer);
            
            response.headers().add<Net::Http::Header::ContentType>(MIME(Application, Json));

            response.send(Http::Code::Ok, drugs_buffer.GetString());
            
        } else {
            response.send(Http::Code::Internal_Server_Error);
        }
    } else {
        response.send(Http::Code::Internal_Server_Error);
    }
    
}
