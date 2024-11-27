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

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
