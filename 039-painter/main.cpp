#include <QApplication>
#include "customWidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    CustomWidget widget;
    widget.resize(300, 300);
    widget.show();

    return app.exec();
}