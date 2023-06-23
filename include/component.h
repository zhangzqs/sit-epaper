#pragma once

#include <Log.h>
#include <queue>

using Runnable = std::function<void()>;
class AppComponent {
 private:
  std::queue<Runnable> shouldRunOnLoop;

 protected:
  void runOnLoopOnce(Runnable runnable) {
    log_debug("%s: runOnLoopOnce", name());
    shouldRunOnLoop.push(runnable);
  }

 public:
  virtual const char* name() = 0;
  virtual void loop() {
    while (!shouldRunOnLoop.empty()) {
      Runnable runnable = shouldRunOnLoop.front();
      log_debug("%s: running runnable", name());
      runnable();
      shouldRunOnLoop.pop();
    }
  }
};