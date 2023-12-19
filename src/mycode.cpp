#include "mycode.h"

void hello(std::istream &ist, std::ostream& ost) {
    std::string name;

    // Чтение имени из входного потока
    ist >> name;

    // Проверка на пустую строку
    if (name.empty()) {
        ost << "Извините, имя не было введено.";
    } else {
        ost << "Привет, ";

        // Если имя - это "Вася", то выводим особое приветствие
        if (name == "Вася") {
            ost << "Вася!";
        } else {
            // Иначе просто приветствуем по имени
            ost << name << "!";
        }
    }
}