#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>

//          COLOR
#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FRED(x) KRED << x << RST
#define FGRN(x) KGRN << x << RST
#define FYEL(x) KYEL << x << RST
#define FBLU(x) KBLU << x << RST
#define FMAG(x) KMAG << x << RST
#define FCYN(x) KCYN << x << RST
#define FWHT(x) KWHT << x << RST

#define BOLD(x) "\x1B[1m" << x << RST
#define UNDL(x) "\x1B[4m" << x << RST

//          LEVEL DEBUG (Flag)
#define Error 1
#define Warning 2
#define Log 4
#define Info 8
#define Verbose 16

class Logger {
public:
    Logger(Logger const&) = delete;
    void operator=(Logger const&) = delete;
    static Logger& get();

    void error (std::string msg);
    void warning(std::string msg);
    void log(std::string msg);
    void info(std::string msg);
    void verbose(std::string msg);

    void redirectTo (unsigned int levels, std::ostream& os);

    void setDatePrinting (bool b) { printDate = b; };
    void setHourPrinting (bool b) { printHour = b; };
    void setMinimumDateHoursSize (int len) { dateHoursSize = len; }

private:

    Logger(std::ostream& os);
    ~Logger();
    std::string getDateAndHours ();

    std::ostream s_error;
    std::ostream s_warning;
    std::ostream s_log;
    std::ostream s_info;
    std::ostream s_verbose;

    bool printHour = false;
    bool printDate = true;
    int dateHoursSize = 0;
};

#endif