#include "basewindow.h"

BaseWindow::BaseWindow(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    mbDragging = false;
}

void BaseWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        mptLastPosition = event->globalPos() - frameGeometry().topLeft();
        mbDragging = true;
        qDebug() << "Drag Start Position:" << mptLastPosition;
    }

    // Call parent implementation if needed
    QWidget::mousePressEvent(event);
}

void BaseWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (mbDragging) {
        QPoint delta = event->globalPos() - mptLastPosition;
        move(delta);
        qDebug() << "Window Moved To:" << pos();
    }

    // Call parent implementation if needed
    QWidget::mouseMoveEvent(event);
}

void BaseWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        mbDragging = false;
        qDebug() << "Drag Ended at:" << pos();
    }

    // Call parent implementation if needed
    QWidget::mouseReleaseEvent(event);
}
