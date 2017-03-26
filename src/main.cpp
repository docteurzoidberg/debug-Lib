#include "Logger.h"
#include <iostream>


int main (int argc, char **argv) {
    std::ofstream logFile("log.txt", std::ios::out | std::ios::app);

    if(logFile)
        Logger::redirectTo(Log | Verbose | Info, logFile);
    else
        std::cout << "Erreur à l'ouverture !" << std::endl;

    Logger::log("un petit log");
    Logger::warning("un warning");
    Logger::info("info");
    Logger::error("HOLY SHIT");
    Logger::verbose("nan je rigole");

    if (logFile)
        logFile.close();

    return 0;
}