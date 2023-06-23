#pragma once

#include "OneButton.h"
#include "component.h"

class BaseButtonComponent : public AppComponent {
 private:
  int pin;
  std::unique_ptr<OneButton> button;

 public:
  BaseButtonComponent(int pin);

  void loop() override;

  virtual const char* name() override { return "ButtonComponent"; }

  virtual void onClick() {}

  virtual void onDoubleClick() {}

  virtual void onLongPressStart() {}

  virtual void onLongPressStop() {}
};

class Button1Component : public BaseButtonComponent {
 public:
  Button1Component();
  const char* name() override { return "Button1Component"; }

  void onClick() override;

  void onDoubleClick() override;

  void onLongPressStart() override;

  void onLongPressStop() override;
};

class Button2Component : public BaseButtonComponent {
 public:
  Button2Component();
  const char* name() override { return "Button2Component"; }

  void onClick() override;

  void onDoubleClick() override;

  void onLongPressStart() override;

  void onLongPressStop() override;
};

class Button3Component : public BaseButtonComponent {
 public:
  Button3Component();

  const char* name() override { return "Button3Component"; }

  void onClick() override;

  void onDoubleClick() override;

  void onLongPressStart() override;

  void onLongPressStop() override;
};