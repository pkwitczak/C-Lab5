#include <stdio.h>

typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    Point first;
    Point second;
} Rectangle;

int main(void)
{
    Rectangle rectangle;

    rectangle.first.x = 1.0f;
    rectangle.first.y = 2.0f;
    rectangle.second.x = 5.0f;
    rectangle.second.y = 7.0f;

    printf("first: (%.2f, %.2f)\n",
           rectangle.first.x, rectangle.first.y);

    printf("second: (%.2f, %.2f)\n",
           rectangle.second.x, rectangle.second.y);

    float width = rectangle.second.x - rectangle.first.x;
    float height = rectangle.second.y - rectangle.first.y;

    printf("width: %.2f\n", width);
    printf("height: %.2f\n", height);
    printf("area: %.2f\n", width * height);

    return 0;
}