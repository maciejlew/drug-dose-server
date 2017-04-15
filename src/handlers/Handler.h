/* 
 * File:   Handler.h
 * Author: Maciej Lew <lion.net.pl>
 *
 * Created on 15 kwietnia 2017, 19:04
 */

#ifndef HANDLER_H
#define HANDLER_H

#include "pistache/http.h"
#include "pistache/endpoint.h"
#include "pistache/description.h"
#include "SettingsParser/SettingsParser.hpp"

class Handler {
    
private:
    
    SettingsParser settings;
    
public:
    
    Handler(SettingsParser settings);
    
    SettingsParser getSettings();
    
};

#endif /* HANDLER_H */

