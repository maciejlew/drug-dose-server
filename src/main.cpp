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

using namespace Net;

int main() {
    
    Net::Port port(9080);

    int thr = 2;

    Net::Address addr(Net::Ipv4::any(), port);

    Endpoint stats(addr);

    stats.init(thr);
    stats.start();

    stats.shutdown();
}