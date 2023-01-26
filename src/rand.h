#pragma once

#include <random>

float rand(float min, float max) {
  static std::random_device rd{};
  static std::mt19937 gen{rd()};

  std::uniform_real_distribution<float> distrib{min, max};
  return distrib(gen);
}
