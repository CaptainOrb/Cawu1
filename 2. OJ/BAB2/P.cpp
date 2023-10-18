#include <stdio.h>

int main()
{
    double X, Y, price;
    // after = before - (before * y/100)
    // after + (before*diskon/100) = before
    // after - (diskon/100)before = after
    // ((100-diskon)before)/100 = after
    // after * 100 = (100-diskon)before
    // before = (after * 100)/(100-diskon)

    // x = before; y = diskon; z = after;
    // afterprice = price - (price*diskon)
    // price = afterprice + (price*diskon)
    scanf("%lf %lf", &X, &Y);
    price = (100*Y)/(100-X);
    printf("$%.2lf\n", price);
    scanf("%lf %lf", &X, &Y);
    price = (100*Y)/(100-X);
    printf("$%.2lf\n", price);
    scanf("%lf %lf", &X, &Y);
    price = (100*Y)/(100-X);
    printf("$%.2lf\n", price);
    scanf("%lf %lf", &X, &Y);
    price = (100*Y)/(100-X);
    printf("$%.2lf\n", price);
}