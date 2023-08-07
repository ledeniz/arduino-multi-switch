#pragma once
#include "Arduino.h"

class Switch {
    private:
        unsigned short _settingPin;
        unsigned short _settingMode;

        boolean _settingToggle;
        boolean _settingInvert;

        boolean _state;
        boolean _last_state;
        unsigned long _state_time;

        unsigned short _debounce;

    public:
        Switch();

        unsigned long time;

};