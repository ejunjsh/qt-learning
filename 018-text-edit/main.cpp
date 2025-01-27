#include <QApplication>
#include <QWidget>
#include <QTextEdit>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("QTextEdit Example");
    window.setMinimumSize(400,400);
    QTextEdit *textEdit = new QTextEdit(&window);
    textEdit->setText("Default Text");

    window.show();
    return app.exec();
}
