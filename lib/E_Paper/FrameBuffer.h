#pragma once
#include <memory.h>
#include <memory>
enum ThreeColor { WHITE = 0, BLACK = 1, RED = 2 };

class FrameBuffer {
 private:
  std::unique_ptr<uint8_t[]> buffer;
  uint16_t width;
  uint16_t height;

 public:
  FrameBuffer(uint16_t width, uint16_t height, uint8_t* buffer)
      : width(width), height(height) {
    this->buffer = std::unique_ptr<uint8_t[]>(buffer);
  }

  FrameBuffer(const FrameBuffer& other)
      : width(other.width), height(other.height) {
    buffer = std::unique_ptr<uint8_t[]>(new uint8_t[(width * height * 2) / 8]);
    memcpy(buffer.get(), other.buffer.get(), (width * height * 2) / 8);
  }

  FrameBuffer(FrameBuffer&& other) : width(other.width), height(other.height) {
    buffer = std::move(other.buffer);
  }

  void setPixel(uint16_t x, uint16_t y, ThreeColor color) {
    uint16_t index = (x + y * width) * 2;
    uint8_t value = buffer[index / 8];
    uint8_t mask = 0x03 << (index % 8);
    value &= ~mask;
    value |= color << (index % 8);
    buffer[index / 8] = value;
  }

  ThreeColor getPixel(uint16_t x, uint16_t y) {
    uint16_t index = (x + y * width) * 2;
    uint8_t value = buffer[index / 8];
    return (ThreeColor)((value >> (index % 8)) & 0x03);
  }

  uint8_t* const getBuffer() { return buffer.get(); }

  uint16_t getWidth() { return width; }

  uint16_t getHeight() { return height; }
};