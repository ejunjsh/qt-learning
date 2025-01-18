#include <QApplication>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QDialog dialog;
    dialog.setWindowTitle("Modal Dialog Example");

    QVBoxLayout *layout = new QVBoxLayout(&dialog);
    QLabel *label = new QLabel("This is a modal dialog.", &dialog);
    layout->addWidget(label);

    QPushButton *okButton = new QPushButton("OK", &dialog);
    layout->addWidget(okButton);

    QPushButton *closeButton = new QPushButton("close", &dialog);
    layout->addWidget(closeButton);

    QObject::connect(okButton, &QPushButton::clicked, [&dialog]() {
        dialog.accept(); // 关闭对话框并返回 QDialog::Accepted
    });

    QObject::connect(closeButton, &QPushButton::clicked, [&dialog]() {
        dialog.reject(); // 关闭对话框并返回 QDialog::Rejected
    });

    int result = dialog.exec(); // 显示模态对话框

    if (result == QDialog::Accepted) {
        qInfo() << "User clicked OK.";
    } else {
        qInfo() << "User closed the dialog.";
    }

    return app.exec();
}