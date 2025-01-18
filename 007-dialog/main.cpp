#include <QApplication>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QDialog dialog;
    dialog.setWindowTitle("Dialog Example");

    QVBoxLayout *layout = new QVBoxLayout(&dialog);
    QLabel *label = new QLabel("This is a dialog", &dialog);
    layout->addWidget(label);

    QPushButton *button = new QPushButton("Close", &dialog);
    layout->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, [&dialog]() {
        dialog.close();
    });

    dialog.exec(); // 显示模态对话框

    return app.exec();
}
