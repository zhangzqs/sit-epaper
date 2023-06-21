#pragma once

enum level { LOG_TRACE, LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_FATAL };

static const char *level_strings[] = {"TRACE", "DEBUG", "INFO",
                                      "WARN",  "ERROR", "FATAL"};

template <typename... Args> void Log(
    enum level level, 
    const char *file, 
    int line, 
    const char *fmt, 
    Args... args) {
    Serial.printf("[%s]    %s:%d:    t\n", level_strings[level], file, line);
}

#define log(LEVEL, ...) Log((LEVEL), __FILE__, __LINE__, (FMT), __VA_ARGS__)
#define log_trace(FMT, ...) Log(LOG_TRACE, __FILE__, __LINE__, (FMT), __VA_ARGS__)
#define log_debug(FMT, ...) Log(LOG_DEBUG, __FILE__, __LINE__, (FMT), __VA_ARGS__)
#define log_info(FMT, ...) Log(LOG_INFO, __FILE__, __LINE__, (FMT), __VA_ARGS__)
#define log_warn(FMT, ...) Log(LOG_WARN, __FILE__, __LINE__, (FMT), __VA_ARGS__)
#define log_error(FMT, ...) Log(LOG_ERROR, __FILE__, __LINE__, (FMT), __VA_ARGS__)
#define log_fatal(FMT, ...) Log(LOG_FATAL, __FILE__, __LINE__, (FMT), __VA_ARGS__)