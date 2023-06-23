#pragma once
#include <Arduino.h>
#include <memory>
enum level { LOG_TRACE, LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_FATAL };

extern const char* level_strings[];
extern std::shared_ptr<Print> printable;

inline void setLogPrintTarget(std::shared_ptr<Print> target) {
  printable = target;
}

template <typename... Args>
inline void Log(enum level level,
                const char* file,
                int line,
                const char* fmt,
                Args... args) {
  if (printable == nullptr) {
    return;
  }
  printable->printf("[%s]    \t%s:%d:    \t", level_strings[level], file, line);
  printable->printf(fmt, args...);
  printable->println();
}
#define log(LEVEL, ...) Log((LEVEL), __FILE__, __LINE__, __VA_ARGS__)
#define log_trace(...) Log(LOG_TRACE, __FILE__, __LINE__, __VA_ARGS__)
#define log_debug(...) Log(LOG_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define log_info(...) Log(LOG_INFO, __FILE__, __LINE__, __VA_ARGS__)
#define log_warn(...) Log(LOG_WARN, __FILE__, __LINE__, __VA_ARGS__)
#define log_error(...) Log(LOG_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define log_fatal(...) Log(LOG_FATAL, __FILE__, __LINE__, __VA_ARGS__)
