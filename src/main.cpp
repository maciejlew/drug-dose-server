/* 
 * File:   main.cpp
 * Author: Maciej Lew <lion.net.pl>
 *
 * Created on 12 marca 2017, 16:35
 */

#include <cstdlib>

#include "pistache/endpoint.h"
#include "pistache/http.h"
#include "ProjectHandler.h"
#include "Endpoint.h"

#include "SettingsParser/SettingsParser.hpp"
#include <iostream>
#include <vector>

using namespace Net;

int main() {
    
    SettingsParser settings;
    if (!settings.loadFromFile("dds.ini")) {
        return -1;
    }
    
    Net::Port port(9080);

    int thr = 2;

    Net::Address addr(Net::Ipv4::any(), port);

    Endpoint stats(addr, settings);

    stats.init(thr);
    stats.start();

    stats.shutdown();
}