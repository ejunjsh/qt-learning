#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QDebug>

class MyWidget : public QWidget {
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {
        QPushButton *button = new QPushButton("Click Me", this);
        connect(button, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    }

private slots:
    void onButtonClicked() {
        qDebug() << "Button Clicked!";
    }
};
#include "main.moc"
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MyWidget widget;
    widget.show();

    return app.exec();
}
