#include "Logger.h"

Logger& Logger::get() {
    static Logger instance(std::cout);
    return instance;
}


Logger::Logger (std::ostream& os) :
    s_error(os.rdbuf()), s_warning(os.rdbuf()), s_log(os.rdbuf()), s_info(os.rdbuf()), s_verbose(os.rdbuf()) {
}

Logger::~Logger() {};

void Logger::error (std::string msg) {
    this->s_error << getDateAndHours() << BOLD(FRED("error  ")) << " - " << msg << std::endl;
}

void Logger::warning(std::string msg) {
    this->s_warning << getDateAndHours() << BOLD(FYEL("warning")) << " - " << msg << std::endl;
}

void Logger::log(std::string msg) {
    this->s_log << getDateAndHours() << BOLD(FBLU("log    ")) << " - " << msg << std::endl;
}

void Logger::info(std::string msg) {
    this->s_info << getDateAndHours() << BOLD(FCYN("info   ")) << " - " << msg << std::endl;
}

void Logger::verbose(std::string msg) {
    this->s_verbose << getDateAndHours() << BOLD(FGRN("verbose")) << " - " << msg << std::endl;
}

std::string Logger::getDateAndHours () {
    std::string s = "";

    std::ostringstream os;
    std::time_t t = std::time(NULL);
    char mbstr[100];

    if (printDate) {
        if (printHour) {
            if (std::strftime(mbstr, sizeof(mbstr), "%d/%m/%Y %H:%M:%S", std::localtime(&t))) { os << mbstr; s = os.str(); } 
            else return "";
        } else {
            if (std::strftime(mbstr, sizeof(mbstr), "%d/%m/%Y", std::localtime(&t))) { os << mbstr; s = os.str(); } 
            else return "";
        }
    } else {
        if (printHour) {
            if (std::strftime(mbstr, sizeof(mbstr), "%H:%M:%S", std::localtime(&t))) { os << mbstr; s = os.str(); } 
            else return "";
        } else {
            return "";
        }
    }

    for (int i = s.length(); i < dateHoursSize; i++) // adjust size
        s += " ";

    return s + " ";
}

void Logger::redirectTo (unsigned int levels, std::ostream& os) {
    if (levels & Error)
        this->s_error.rdbuf(os.rdbuf());
    if (levels & Warning)
        this->s_warning.rdbuf(os.rdbuf());
    if (levels & Info)
        this->s_info.rdbuf(os.rdbuf());
    if (levels & Log)
        this->s_log.rdbuf(os.rdbuf());
    if (levels & Verbose)
        this->s_verbose.rdbuf(os.rdbuf());
}
