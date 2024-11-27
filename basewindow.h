#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QDebug>
#include <QWidget>
#include <QMouseEvent>

class BaseWindow : public QWidget
{
    Q_OBJECT
public:
    explicit BaseWindow(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;
    void mouseReleaseEvent(QMouseEvent *) override;
    bool mbDragging;
    QPoint mptLastPosition;


signals:

};

#endif // BASEWINDOW_H
