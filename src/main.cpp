#include "Logger.h"
#include <iostream>


int main (int argc, char **argv) {
    Logger::createTransport(new Transport("log.txt"), "log");
    Logger::createTransport(new Transport(std::cerr), "cerr");
    Logger::addTransportOf(Logger::LOG, "log");
    Logger::setTransportOf(Logger::ERROR, "cerr");

    Logger::log("truc");
    Logger::setFormatOf("cout", "{day}/{mon}/{year} {hour}:{min}:{sec}:{mil}:{mic} => {col}{udl}{bld}{lvl}{clr} {30}: \"{col}{msg}{clr}\"");
    Logger::setFormatOf("cerr", "{day}/{mon}/{year} {hour}:{min}:{sec}:{mil}:{mic} => {col}{udl}{bld}{lvl}{clr} {30}: \"{col}{msg}{clr}\"");
    Logger::error("ERROR !");
    Logger::warn("you should be careful");

    Logger::title("Title", Logger::ALL);

    Logger::info("Let's play with sections !");
    Logger::section("A section", Logger::ALL ^ Logger::SPE, Logger::INFO);
        Logger::info("in the section");
        Logger::special("you can't see me");
        Logger::section("Another One", Logger::ALL ^ Logger::INFO, Logger::LOG);
            Logger::info("you can't see me");
            Logger::special("me too");
            Logger::warn("i'm important'");
    Logger::section_end("A section");
    Logger::info("NO !");
        Logger::section_end("Another One");
    Logger::special("now you can see me");

    return 0;
}