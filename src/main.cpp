#include "Logger.h"
#include <iostream>


int main (int argc, char **argv) {
    Logger::redirectToFile(Log | Verbose | Info, "log2.txt");

    Logger::log("un petit log");
    Logger::warning("un warning");
    Logger::info("info");
    Logger::error("HOLY SHIT");
    Logger::verbose("nan je rigole");

    Logger::redirectToFile(Error | Verbose | Info, "log.txt");

    Logger::log("2un petit log");
    Logger::warning("2un warning");
    Logger::info("2info");
    Logger::error("2HOLY SHIT");
    Logger::verbose("2nan je rigole");

    Logger::redirectToFile(Log | Info, "log2.txt");

    Logger::log("3un petit log");
    Logger::warning("3un warning");
    Logger::info("3info");
    Logger::error("3HOLY SHIT");
    Logger::verbose("3nan je rigole");
    return 0;
}