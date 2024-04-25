#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <Windows.h>

using namespace std;

struct Book {
    string title;
    string author;
    string genre;
    string description;
    bool reserved;
};

vector<Book> libraryCatalog;

void searchBook() {
    string keyword;
    cout << "Введите ключевое слово для поиска: ";
    cin >> keyword;

    cout << "Результаты поиска:" << endl;
    for (Book book : libraryCatalog) {
        if (book.title.find(keyword) != string::npos || book.author.find(keyword) != string::npos || book.genre.find(keyword) != string::npos) {
            cout << "Название: " << book.title << endl;
            cout << "Автор: " << book.author << endl;
            cout << "Жанр: " << book.genre << endl;
            cout << "Описание: " << book.description << endl;
            if (book.reserved) {
                cout << "Книга зарезервирована" << endl;
            }
            else {
                cout << "Книга не зарезервирована" << endl;
            }
        }
    }
}

void addBook() {
    string title, author, genre, description;
    cout << "\nВведите название книги: ";
    cin.ignore();
    getline(cin, title);
    cout << "Введите автора книги: ";
    getline(cin, author);
    cout << "Введите жанр книги: ";
    getline(cin, genre);
    cout << "Введите описание книги: ";
    getline(cin, description);

    Book newBook;
    newBook.title = title;
    newBook.author = author;
    newBook.genre = genre;
    newBook.description = description;
    newBook.reserved = false;

    libraryCatalog.push_back(newBook);
    cout << "Книга успешно добавлена в каталог" << endl;
}

void displayBookInfo(Book book) {
    cout << "\nНазвание: " << book.title << endl;
    cout << "Автор: " << book.author << endl;
    cout << "Жанр: " << book.genre << endl;
    cout << "Описание: " << book.description << endl;
    if (book.reserved) {
        cout << "Книга зарезервирована" << endl;
    }
    else {
        cout << "Книга не зарезервирована" << endl;
    }
}

void reserveBook() {
    string title;
    cout << "Введите название книги, которую хотите зарезервировать: ";
    cin.ignore();
    getline(cin, title);

    for (Book& book : libraryCatalog) {
        if (book.title == title) {
            book.reserved = true;
            cout << "Книга " << title << " успешно зарезервирована" << endl;
            return;
        }
    }
    cout << "Книга не найдена" << endl;
}

void displayReservedBooks() {
    cout << "Список зарезервированных книг:" << endl;
    for (Book book : libraryCatalog) {
        if (book.reserved) {
            displayBookInfo(book);
        }
    }
}

void cancelReservation() {
    string title;
    cout << "Введите название книги, резервацию которой хотите отменить: ";
    cin.ignore();
    getline(cin, title);

    for (Book& book : libraryCatalog) {
        if (book.title == title) {
            book.reserved = false;
            cout << "Резервация книги " << title << " успешно отменена" << endl;
            return;
        }
    }
    cout << "Книга не найдена" << endl;
}

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    libraryCatalog.push_back({ "Война и Мир", "Л.Н.Толстой", "Русская классика", "Роман Льва Толстого, в которых автор описывает солнечную жизнь на фоне грандиозного исторического события — вторжения французской армии во главе с Наполеоном", false });
    libraryCatalog.push_back({ "Мертвые души", "Н.В. Гоголь", "Поэма", "История Чичикова, странствующего чиновника среднего звена, отчаянно пытающегося нажить своё состояние", false });
    libraryCatalog.push_back({ "Инструкция по сборке мебели IКЕА", "Инженер из IКЕА", "Готическая литература", "Ужасное чтиво. Ходят легенды, что если ее прочитать вслух, то можно вызвать Сатану", false });

    cout << "";

    int choice;
    while (true) {
        cout << "Список доступных книг:\n";
        for (const Book& book : libraryCatalog) {
            if (!book.reserved) {
                displayBookInfo(book);
            }
        }

        cout << "\nВыберите действие:\n1.Найти книгу\n2.Зарезервировать книгу\n3.Показать зарезервированные книги\n4.Отменить резервацию\n5.Добавить книгу\n6.Выйти";
        int choice;
        cout << "\nВаш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            searchBook();
            break;
        case 2:
            reserveBook();
            break;
        case 3:
            displayReservedBooks();
            break;
        case 4:
            cancelReservation();
            break;
        case 5:
            addBook();
            break;
        case 6:
            return 0;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}