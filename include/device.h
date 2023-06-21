#pragma once

#include <OneButton.h>

#include "pin.h"
namespace Device {
    OneButton button1(PIN::BUTTON::BUTTON_1, true);
    OneButton button2(PIN::BUTTON::BUTTON_2, true);
    OneButton button3(PIN::BUTTON::BUTTON_3, true);
    
};