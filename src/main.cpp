#include "Logger.h"
#include <iostream>


int main (int argc, char **argv) {
    std::ofstream logFile("log.txt", std::ios::out | std::ios::app);

    if(logFile)
        Logger::get().redirectTo(Log | Verbose | Info, logFile);
    else
        std::cout << "Erreur à l'ouverture !" << std::endl;

    Logger::get().log("un petit log");
    Logger::get().warning("un warning");
    Logger::get().info("info");
    Logger::get().error("HOLY SHIT");
    Logger::get().verbose("nan je rigole");

    if (logFile)
        logFile.close();

    return 0;
}