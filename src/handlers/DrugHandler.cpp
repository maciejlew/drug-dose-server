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

void DrugHandler::onRequest(const Net::Rest::Request& request, Net::Http::ResponseWriter response) {
    
    std::string files_path;
    
    getSettings().get("files_path", files_path);
    
    if (!files_path.empty()) {
        
        auto id = request.param(":id").as<std::string>();
        
        std::ostringstream s;
        s << files_path << "/" << id << ".json";
        
        std::cout << s.str() << std::endl;
        
        Http::serveFile(response, s.str().c_str(), MIME(Application, Json));
            
    } else {
        response.send(Http::Code::Internal_Server_Error);
    }
}
