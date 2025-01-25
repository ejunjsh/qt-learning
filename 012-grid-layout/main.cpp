#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget *widget = new QWidget();
    QGridLayout *layout = new QGridLayout(widget);

    QPushButton *button1 = new QPushButton("Button 1");
    QPushButton *button2 = new QPushButton("Button 2");
    QPushButton *button3 = new QPushButton("Button 3");

    layout->addWidget(button1, 0, 0); // 第一行，第一列
    layout->addWidget(button2, 0, 1); // 第一行，第二列
    layout->addWidget(button3, 1, 0, 1, 2); // 第二行，从第一列开始，占据两列

    widget->setLayout(layout);
    widget->show();

    return app.exec();
}