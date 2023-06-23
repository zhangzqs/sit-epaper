#include <Log.h>
const char* level_strings[] = {"TRACE", "DEBUG", "INFO",
                               "WARN",  "ERROR", "FATAL"};

std::shared_ptr<Print> printable = nullptr;
