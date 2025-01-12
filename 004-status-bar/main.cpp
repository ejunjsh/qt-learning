#include <QApplication>
#include <QMainWindow>
#include <QStatusBar>
#include <QPushButton>
#include <QLabel>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        // 创建一个标签并将其添加到状态栏
        statusLabel = new QLabel("Ready", this);
        statusBar()->addWidget(statusLabel);

        // 创建一个按钮
        QPushButton *button = new QPushButton("Show Message", this);
        connect(button, SIGNAL(clicked()), this, SLOT(showMessage()));
        setCentralWidget(button);
    }

private slots:
    void showMessage() {
        statusBar()->showMessage("Button clicked", 3000); // 显示消息，持续时间为3秒
    }

private:
    QLabel *statusLabel;
};

#include "main.moc"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
