#include <memory>
enum ThreeColor {
    WHITE = 0,
    BLACK = 1,
    RED = 2
};

class FrameBuffer {
private:
    std::unique_ptr<uint8_t[]> buffer;
    uint16_t width;
    uint16_t height;

public:
    FrameBuffer(uint16_t width, uint16_t height) : width(width), height(height) {
        buffer = std::unique_ptr<uint8_t[]>(new uint8_t[(width * height * 2) / 8]);
    }

    void setPixel(uint16_t x, uint16_t y, ThreeColor color) {
        uint16_t index = (x + y * width) * 2;
        uint8_t value = buffer[index / 8];
        uint8_t mask = 0x03 << (index % 8);
        value &= ~mask;
        value |= color << (index % 8);
        buffer[index / 8] = value;
    }

    void setPixel(uint16_t x, uint16_t y, uint8_t color) {
        uint16_t index = (x + y * width) * 2;
        uint8_t value = buffer[index / 8];
        uint8_t mask = 0x03 << (index % 8);
        value &= ~mask;
        value |= color << (index % 8);
        buffer[index / 8] = value;
    }

    uint8_t *const getBuffer() {
        return buffer.get();
    }

    uint16_t getWidth() {
        return width;
    }

    uint16_t getHeight() {
        return height;
    }
};