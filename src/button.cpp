#include "common.h"

BaseButtonComponent::BaseButtonComponent(int pin) : pin(pin) {
  log_debug("Button1_Component::setup");
  std::unique_ptr<OneButton> m_p1(new OneButton(pin, true));
  this->button = std::move(m_p1);
  log_info("初始化按钮%s完成", name());

  button->attachClick(
      [](void* _thiz) {
        BaseButtonComponent* thiz = (BaseButtonComponent*)_thiz;
        log_info("按钮%s被点击", thiz->name());
        thiz->onClick();
      },
      this);

  button->attachDoubleClick(
      [](void* _thiz) {
        BaseButtonComponent* thiz = (BaseButtonComponent*)_thiz;
        log_info("按钮%s被双击", thiz->name());
        thiz->onDoubleClick();
      },
      this);

  button->attachLongPressStart(
      [](void* _thiz) {
        BaseButtonComponent* thiz = (BaseButtonComponent*)_thiz;
        log_info("按钮%s长按开始", thiz->name());
        thiz->onLongPressStart();
      },
      this);

  button->attachLongPressStop(
      [](void* _thiz) {
        BaseButtonComponent* thiz = (BaseButtonComponent*)_thiz;
        log_info("按钮%s长按结束", thiz->name());
        thiz->onLongPressStop();
      },
      this);
}

void BaseButtonComponent::loop() {
  this->button->tick();
}

Button1Component::Button1Component()
    : BaseButtonComponent(GENERATED::PIN::BUTTON::BUTTON_1) {}

void Button1Component::onClick() {
  log_info("按钮1被点击");
  Global::epaper->showTest();
}

void Button1Component::onDoubleClick() {
  log_info("按钮1被双击");
}

void Button1Component::onLongPressStart() {
  log_info("按钮1长按开始");
}

void Button1Component::onLongPressStop() {
  log_info("按钮1长按结束");
}
Button2Component::Button2Component()
    : BaseButtonComponent(GENERATED::PIN::BUTTON::BUTTON_2) {}

void Button2Component::onClick() {
  log_info("按钮2被点击");
}

void Button2Component::onDoubleClick() {
  log_info("按钮2被双击");
}

void Button2Component::onLongPressStart() {
  log_info("按钮2长按开始");
}

void Button2Component::onLongPressStop() {
  log_info("按钮2长按结束");
}
Button3Component::Button3Component()
    : BaseButtonComponent(GENERATED::PIN::BUTTON::BUTTON_3) {}

void Button3Component::onClick() {
  log_info("按钮3被点击");
}

void Button3Component::onDoubleClick() {
  log_info("按钮3被双击");
}

void Button3Component::onLongPressStart() {
  log_info("按钮3长按开始");
}

void Button3Component::onLongPressStop() {
  log_info("按钮3长按结束");
}
