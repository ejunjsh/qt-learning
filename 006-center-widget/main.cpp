#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        // 创建中心部件
        QWidget *centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);

        // 创建布局管理器
        QVBoxLayout *layout = new QVBoxLayout(centralWidget);

        // 在中心部件中添加标签
        QLabel *label = new QLabel("This is the central widget content", centralWidget);
        layout->addWidget(label);
    }
};

#include "main.moc"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
