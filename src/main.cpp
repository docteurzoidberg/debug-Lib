#include "Logger.h"
#include <iostream>


int main (int argc, char **argv) {
    Logger::redirectToFile(Logger::Log | Logger::Verbose | Logger::Info, "log2.txt");

    Logger::log("un petit log : log2");
    Logger::warning("un warning : cout");
    Logger::info("info : log2");
    Logger::error("HOLY SHIT : cout");
    Logger::verbose("nan je rigole : log2");

    Logger::redirectTo(Logger::All, std::cout);
    Logger::redirectToFile(Logger::Error | Logger::Verbose | Logger::Info, "log.txt");

    Logger::log("2cout");
    Logger::warning("2cout");
    Logger::info("2log");
    Logger::error("2log");
    Logger::verbose("2log");

    Logger::redirectTo(Logger::All, std::cout);
    Logger::redirectToFile(Logger::Log | Logger::Info, "log2.txt");

    Logger::log("3 : log2");
    Logger::warning("3 : cout");
    Logger::info("3 : log2");
    Logger::error("3 : cout");
    Logger::verbose("3 : cout");

    Logger::info("Time to Section !");

    Logger::beginSection("Section A", Logger::Info);
    Logger::info("ok");
    Logger::hideSection("Section A");
        Logger::beginSection("Section B", Logger::Info);
        Logger::endSection("Section B");
    Logger::info("nooooooooo");
    Logger::showSection("Section A", Logger::Info);
    Logger::info("now it's ok");
    Logger::hideSection("Section A");
    Logger::info("nooooooooo come oooooon");
    Logger::endSection("Section A");
    Logger::info("section ended");

    return 0;
}