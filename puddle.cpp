#include "Colors.h"
#include <cmath>
#include <iostream>
struct vector2 {
  int x;
  int y;
};

struct circle {
  vector2 position;
  int size;
  int lifeTime;
};

#define CIRCLE_COUNT 1
#define DEBUG_SCREEN_SIZE 21

void print2DArray(int array[DEBUG_SCREEN_SIZE][DEBUG_SCREEN_SIZE]) {
  for (int i = 0; i < DEBUG_SCREEN_SIZE; i++) {
    for (int n = 0; n < DEBUG_SCREEN_SIZE; n++) {

      switch (array[i][n]) {
      case 1:
        std::cout << COLOR(55, 55, 55);
        break;
      default:
        break;
      }

      std::cout << "  " << NOCOLOR;
    }
    std::cout << '\n';
  }
}

int evaluatePoint(vector2 point, vector2 circleCenter, float radius) {

  float magnitude =
      std::hypot(point.x - circleCenter.x, point.y - circleCenter.y);

  if (magnitude < radius + .5 && magnitude > radius - .25) {
    return 1;
  } else {
    return 0;
  }
}

int main() {

  int screen[DEBUG_SCREEN_SIZE][DEBUG_SCREEN_SIZE];

  circle circles[CIRCLE_COUNT];
  for (int b = 0; b < CIRCLE_COUNT; b++) {
    circles[b] = {{11, 11}, 9, 0};
    for (int i = 0; i < DEBUG_SCREEN_SIZE; i++) {
      for (int n = 0; n < DEBUG_SCREEN_SIZE; n++) {
        screen[i][n] =
            evaluatePoint({i, n}, circles[b].position, circles[b].size);
      }
    }
  }
  print2DArray(screen);

  main();

  return 0;
}
