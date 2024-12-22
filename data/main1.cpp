#include "STRING1.h"
namespace STRING1 {
int run() {
    STRING str1("Hello");
    STRING str2("Hello");

    /* Демонстрация метода Print */
    str1.Print();
    str2.Print();

    /* Сравнение строк str1 и str2 */
    unsigned comparisonResult = str1.Strcmp(str2);
    std::printf("Comparison result: %u\n", comparisonResult);

    /* Изменение строки str1 */
    str1.Setstr("World");
    str1.Print();

    /* Сравнение строк str1 и str2 снова */
    comparisonResult = str1.Strcmp(str2);
    std::printf("Comparison result: %u\n", comparisonResult);

    return 0;
}
}