#include "mainview.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <loginwindow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "BlueCommercialCasino_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    LoginWindow w;
    w.show();
    return a.exec();
}
