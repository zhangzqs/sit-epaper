#pragma once

enum level { LOG_TRACE, LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_FATAL };

#define log(LEVEL, ...) Log((LEVEL), __FILE__, __LINE__)((FMT), __VA_ARGS__)
#define log_trace(FMT, ...) Log(LOG_TRACE, __FILE__, __LINE__)((FMT), __VA_ARGS__)
#define log_debug(FMT, ...) Log(LOG_DEBUG, __FILE__, __LINE__)((FMT), __VA_ARGS__)
#define log_info(FMT, ...) Log(LOG_INFO, __FILE__, __LINE__)((FMT), __VA_ARGS__)
#define log_warn(FMT, ...) Log(LOG_WARN, __FILE__, __LINE__)((FMT), __VA_ARGS__)
#define log_error(FMT, ...) Log(LOG_ERROR, __FILE__, __LINE__)((FMT), __VA_ARGS__)
#define log_fatal(FMT, ...) Log(LOG_FATAL, __FILE__, __LINE__)((FMT), __VA_ARGS__)

static const char *level_colors[] = {"\x1b[94m", "\x1b[36m", "\x1b[32m",
                                     "\x1b[33m", "\x1b[31m", "\x1b[35m"};

static const char *level_strings[] = {"TRACE", "DEBUG", "INFO",
                                      "WARN",  "ERROR", "FATAL"};

class Log {
private:
  enum level level;
  const char *file;
  int line;
public:

  Log(enum level level, const char *file, int line) {
    this->level = level;
    this->file = file;
    this->line = line;
  }
  ~Log() {
    if (level >= this->level) {
      Serial.printf("%s[%s]\x1b[0m    \t\x1b[90m%s:%d:    \x1b[0m \t\n",  //
             level_colors[level],                                //
             level_strings[level],                               //
             file,                                               //
             line);
    }
  }
    template <typename... Args> void operator()(const char *fmt, Args... args) {
    if (level >= this->level) {
      Serial.printf("%s[%s]\x1b[0m    \t\x1b[90m%s:%d:    \x1b[0m \t",  //
             level_colors[level],                                //
             level_strings[level],                               //
             file,                                               //
             line);
      Serial.printf(fmt, args...);
      Serial.printf("\n");
    }
  }
};
