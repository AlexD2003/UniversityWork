#ifndef SONGEXCEPTION_H
#define SONGEXCEPTION_H


#include <exception>
#include <string>
using namespace std;
class SongException : public exception {
public:
    explicit SongException(const string& message) : message(message) {}

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    string message;
};
#endif // SONGEXCEPTION_H
