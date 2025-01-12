#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // QPushButton的默认信号（clicked）与槽的连接
    QPushButton *button = new QPushButton("Click Me");
    QObject::connect(button, &QPushButton::clicked, [=]() {
        qInfo() << "Button Clicked!";
    });

    // QLineEdit的默认信号（textChanged）与槽的连接
    QLineEdit *lineEdit = new QLineEdit();
    QObject::connect(lineEdit, &QLineEdit::textChanged, [=](const QString &text) {
        qInfo() << "Text Changed: " << text;
    });

    // 显示窗口
    button->show();
    lineEdit->show();

    return app.exec();
}
