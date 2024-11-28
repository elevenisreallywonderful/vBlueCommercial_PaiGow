#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    BaseWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_goSignupBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(LoginPageIndex::Register);
}


void LoginWindow::on_goChangePasswordBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(LoginPageIndex::ChangePassword);
}


void LoginWindow::on_changepasswordBackBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(LoginPageIndex::Login);
}


void LoginWindow::on_signupBackBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(LoginPageIndex::Login);
}


void LoginWindow::on_goChargeBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(LoginPageIndex::Recharge);
}


void LoginWindow::on_rechargeBackBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(LoginPageIndex::Login);
}

