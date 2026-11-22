#include <assert.h>
#include <stdio.h>

struct Book {
    char title[64];
    int pages;
    float price;
};

int main(void)
{
    struct Book book = {
        .title = "Programowanie w C",
        .pages = 320,
        .price = 49.5f
    };

    assert(book.pages == 320);
    assert(book.price == 49.5f);

    printf("title: %s\n", book.title);
    printf("pages: %d\n", book.pages);
    printf("price: %.2f\n", book.price);

    return 0;
}