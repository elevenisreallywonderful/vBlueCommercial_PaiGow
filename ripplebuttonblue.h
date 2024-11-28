#include <QApplication>
#include <QPushButton>
#include <QTimer>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>
#include <QStyleOption>
#include <QStylePainter>
#include <QDebug>

class AirplaneButton : public QPushButton {
	Q_OBJECT

public:
	AirplaneButton(QWidget* parent = nullptr)
        : QPushButton(parent), isPressed(false), buttonText(""), iconPath(""), pressedColor(QColor(0, 99, 229))
    {
		rippleTimer = new QTimer(this);
		connect(rippleTimer, &QTimer::timeout, this, &AirplaneButton::expandRipple);
	}

    void setButtonText(const QString &text) { buttonText = text; }
    void setIconPath(const QString &path) { iconPath = path; }
    void setPressedColor(QColor color){ pressedColor = color; }

protected:
	void paintEvent(QPaintEvent* event) override {
		QPushButton::paintEvent(event);

		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing);

		// Draw ripples
		painter.setPen(Qt::NoPen);
		for (const auto& ripple : ripples) {
            QColor color(pressedColor.red(), pressedColor.green(), pressedColor.blue(), ripple.alpha);
			painter.setBrush(color);
			painter.drawEllipse(ripple.center, ripple.radius, ripple.radius);
		}

        // Finally, draw the button text on top of the ripple effect
        QStyleOptionButton opt;
        opt.initFrom(this);
        opt.rect = style()->subElementRect(QStyle::SE_PushButtonContents, &opt, this);

        opt.state = QStyle::State_Enabled | QStyle::State_Raised;
        if (isDown()) {
            opt.state |= QStyle::State_Sunken;
        }
        if (isChecked()) {
            opt.state |= QStyle::State_On;
        }
        if(!buttonText.isEmpty())
            opt.text = buttonText;
        else
            opt.text = this->text();
        if(!iconPath.isEmpty())
            opt.icon = QIcon(iconPath);

        opt.iconSize = iconSize();

        QStylePainter textAndIconPainter(this);
        textAndIconPainter.drawControl(QStyle::CE_PushButtonLabel, opt);
	}

	void mousePressEvent(QMouseEvent* event) override {
		if (event->button() == Qt::LeftButton) {
			isPressed = true;
			addRipple(event->pos());

			if (!rippleTimer->isActive()) {
                rippleTimer->start(6);
			}
		}
		QPushButton::mousePressEvent(event);
	}

	void mouseReleaseEvent(QMouseEvent* event) override {
		if (event->button() == Qt::LeftButton) {
			isPressed = false;
		}
		QPushButton::mouseReleaseEvent(event);
	}

private slots:
	void expandRipple() {
        for (auto& ripple : ripples) {
            ripple.radius += 3;
            ripple.alpha -= isPressed ? 1 : 5;
            if (isPressed)
                ripple.alpha = qMax(ripple.alpha, 50);//is long press , keep
        }

		ripples.erase(std::remove_if(ripples.begin(), ripples.end(), [](const Ripple& r) { return r.alpha <= 0; }), ripples.end());
		if (!isPressed && ripples.empty()) {
			rippleTimer->stop();
		}

		update();
	}

private:
	struct Ripple {
		QPoint center;
		int radius;
		int alpha;
	};

	QVector<Ripple> ripples;
	QTimer* rippleTimer;
	bool isPressed;
    QString buttonText;
    QString iconPath;
    QColor pressedColor;

	void addRipple(const QPoint& pos) {
		ripples.append({ pos, 0, 255 });
	}
};

