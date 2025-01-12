#include <QMainWindow>
#include <QDockWidget>
#include <QPushButton>
#include <QLabel>
#include <QApplication>
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        // 创建一个按钮
        QPushButton *button = new QPushButton("Show Dock Widget", this);
        connect(button, SIGNAL(clicked()), this, SLOT(showDockWidget()));
        setCentralWidget(button);
    }

private slots:
    void showDockWidget() {
        // 创建停靠部件
        QDockWidget *dockWidget = new QDockWidget("Dock Widget", this);

        // 在停靠部件中添加一个标签
        QLabel *label = new QLabel("This is a dock widget", dockWidget);
        dockWidget->setWidget(label);

        // 将停靠部件添加到左侧停靠区域
        addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
    }
};


#include "main.moc"
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
