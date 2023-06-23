#pragma once

#include <queue>

using Runnable = std::function<void()>;
class AppComponent {
 private:
  std::queue<Runnable> shouldRunOnLoop;

 protected:
  void runOnLoopOnce(Runnable runnable) { shouldRunOnLoop.push(runnable); }

 public:
  virtual const char* name() = 0;
  virtual void loop() {
    while (!shouldRunOnLoop.empty()) {
      Runnable runnable = shouldRunOnLoop.front();
      runnable();
      shouldRunOnLoop.pop();
    }
  }
};