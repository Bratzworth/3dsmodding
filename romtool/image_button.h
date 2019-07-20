#ifndef IMAGE_BUTTON
#define IMAGE_BUTTON

#include <QtGui/QIcon>
#include <QtWidgets/QPushButton>

class ImageButton : public QPushButton
{
public:
	explicit ImageButton(QWidget *parent = nullptr)
		:QPushButton(parent) {}

	explicit ImageButton(const QString &text, QWidget *parent = nullptr)
		:QPushButton(text, parent) {}

	ImageButton(const QIcon& icon, const QString &text, QWidget *parent = nullptr)
		:QPushButton(icon, text, parent){
		pressedIcon = icon;
		defaultIcon = icon;
	}

	void setPressedIcon(const QIcon &icon) {
		pressedIcon = icon;
	}

	void setDefaultIcon(const QIcon &icon) {
		setIcon(icon);
		defaultIcon = icon;
	}

protected:
	void mousePressEvent(QMouseEvent *e){
		setIcon(pressedIcon);
		QPushButton::mousePressEvent(e);
	}

	void mouseReleaseEvent(QMouseEvent *e) {
		setIcon(defaultIcon);
		QPushButton::mouseReleaseEvent(e);
	}

private:
	QIcon defaultIcon;
	QIcon pressedIcon;
};

#endif