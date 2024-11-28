#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>

#include "basewindow.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public BaseWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

    enum LoginPageIndex{
        Login = 0,
        Register,
        ChangePassword,
        Recharge
    };

private slots:
    void on_goSignupBtn_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
