#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget *widget = new QWidget();
    QHBoxLayout *layout = new QHBoxLayout(widget);

    QPushButton *button1 = new QPushButton("Button 1");
    QPushButton *button2 = new QPushButton("Button 2");

    layout->addWidget(button1);
    layout->addWidget(button2);

    widget->setLayout(layout);
    widget->show();

    return app.exec();
}

