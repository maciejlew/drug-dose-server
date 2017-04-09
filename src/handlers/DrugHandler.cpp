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
    Document drug, config;
    char _drug_buffer[65536], _config_buffer[65536];
    StringBuffer drug_buffer;
    
    FILE* config_pointer = fopen("config.json", "r");
    FileReadStream config_stream(config_pointer, _config_buffer, sizeof(_config_buffer));
    config.ParseStream(config_stream);
    fclose(config_pointer);
    
    if (config.HasMember("files_path")) {
        
        auto id = request.param(":id").as<std::string>();
        
        std::ostringstream s;
        s << config["files_path"].GetString() << "/" << id << ".json";
        
        std::cout << s.str() << std::endl;
        
        FILE* drug_pointer = fopen(s.str().c_str(), "r");
        
        if (drug_pointer) {
            FileReadStream drug_stream(drug_pointer, _drug_buffer, sizeof(_drug_buffer));
            drug.ParseStream(drug_stream);
            fclose(drug_pointer);

            Writer<StringBuffer> writer(drug_buffer);
            drug.Accept(writer);

            response.headers().add<Net::Http::Header::ContentType>(MIME(Application, Json));
            
            response.send(Http::Code::Ok, drug_buffer.GetString());
            
        } else {
            response.send(Http::Code::Internal_Server_Error);
        }
    } else {
        response.send(Http::Code::Internal_Server_Error);
    }
}
