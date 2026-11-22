#include <stdio.h>

typedef union {
    unsigned char character;
    float real;
} ExampleData;

int main(void)
{
    ExampleData data;

    printf("sizeof(unsigned char): %zu\n", sizeof(unsigned char));
    printf("sizeof(float): %zu\n", sizeof(float));
    printf("sizeof(ExampleData): %zu\n", sizeof(ExampleData));

    data.character = 'A';
    printf("character: %c\n", data.character);

    data.real = 2.5f;
    printf("real: %.4f\n", data.real);

    return 0;
}