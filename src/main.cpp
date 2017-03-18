/* 
 * File:   main.cpp
 * Author: Maciej Lew <lion.net.pl>
 *
 * Created on 12 marca 2017, 16:35
 */

#include <cstdlib>

#include "pistache/endpoint.h"
#include "VersionHandler.h"

using namespace Net;

int main() {
    Http::listenAndServe<VersionHandler>("*:9080");
}