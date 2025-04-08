#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool CheckEnail(const string& email) {
    // Проверка минимальной длины
    if (email.length() < 5) return false; // a@b.c - минимально возможный email

    // Поиск символа @
    size_t at_pos = email.find('@');
    if (at_pos == string::npos || at_pos == 0 || at_pos == email.length() - 1) {
        return false;
    }

    // Проверка локальной части (до @)
    for (size_t i = 0; i < at_pos; i++) {
        char c = email[i];
        if (!isalnum(c) && c != '.' && c != '_' && c != '-') {
            return false;
        }
    }

    // Проверка на точку после @
    size_t dot_pos = email.find('.', at_pos);
    if (dot_pos == string::npos || dot_pos == at_pos + 1 || dot_pos == email.length() - 1) {
        return false;
    }

    // Проверка доменной части (после @)
    for (size_t i = at_pos + 1; i < email.length(); i++) {
        char c = email[i];
        if (!isalnum(c) && c != '.' && c != '-') {
            return false;
        }
    }

    // Проверка на две точки подряд
    if (email.find("..") != string::npos) {
        return false;
    }

    return true;
}

int main(int argc, char* argv[]) {
    string email;

    if (argc > 1) {
        email = argv[1];
    }
    else {
        cout << "Enter email address: ";
        getline(cin, email);
    }

    if (CheckEnail(email)) {
        cout << "Valid email address" << endl;
    }
    else {
        cout << "Invalid email address" << endl;
    }

    return 0;
}