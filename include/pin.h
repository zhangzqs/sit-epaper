#pragma once
namespace PIN {
    namespace SPI {
        const int SCK = 18;
        const int MISO = 23;
        const int MOSI = 19;
    }
    namespace EPD {
        const int DC = 17;
        const int RST = 16;
        const int BUSY = 4;
        const int CS = 5; 
    }
    namespace BUTTON {
        const int BUTTON_1 = 0;
        const int BUTTON_2 = 33;
        const int BUTTON_3 = 32;
    }
    namespace SD {
        const int DET = 15;
        const int CS = 13;
    }
    namespace LED {
        const int LED_1 = 22;
    }
}