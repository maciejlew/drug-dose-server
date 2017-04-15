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

void DrugsHandler::onRequest(const Net::Rest::Request& request, Net::Http::ResponseWriter response) {
    
    std::string files_path;
    
    getSettings().get("files_path", files_path);
    
    if (!files_path.empty()) {
        
        std::ostringstream s;
        s << files_path << "/drugs.json";
        
        Http::serveFile(response, s.str().c_str(), MIME(Application, Json));
            
    } else {
        response.send(Http::Code::Internal_Server_Error);
    }
    
}
