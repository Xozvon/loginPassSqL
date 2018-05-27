#ifndef LOGIN_H
#define LOGIN_H
#include <QMainWindow>

class Users
{
public:
    Users();
    Users(QString login,QString password);
    QString login;
    QString password;
    QString getLogin();
    QString getPassword();
};

#endif // LOGIN_H
