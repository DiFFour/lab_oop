#include "SequenceHandler6.h"
#include "FormattedPrint6.h"  // Добавили наш новый заголовочный файл
namespace Print6 {
int run() {
    char type;
    bool continueExecution = true;
    while (continueExecution) {
        PrintFormatted("Выберите тип данных: (i) {} или (f) {}.\n", "целые числа", "вещественные числа");
        std::cin >> type;

        if (type == 'i') {
            SequenceHandler<int> intHandler;
            intHandler.inputSequence();
            intHandler.handleSequence();
        } else if (type == 'f') {
            SequenceHandler<double> doubleHandler;
            doubleHandler.inputSequence();
            doubleHandler.handleSequence();
        } else {
            PrintFormatted("Ошибка: неизвестный {} данных. Попробуйте снова.\n", "тип");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        PrintFormatted("Хотите выполнить ещё одну операцию? ({} / {}): ", "y", "n");
        char userResponse;
        std::cin >> userResponse;
        if (userResponse == 'n' || userResponse == 'N') {
            continueExecution = false;
        } else if (userResponse != 'y' && userResponse != 'Y') {
            PrintFormatted("Ошибка: введён недопустимый символ. {}\n", "Завершаю программу.");
            continueExecution = false;
        }
    }
    PrintFormatted("Программа {}\n", "завершена");
    return 0;
}
}