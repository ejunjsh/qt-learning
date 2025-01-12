#include <QMainWindow>
#include <QToolBar>
#include <QFileDialog>
#include <QLabel>
#include <QApplication>
#include <QStatusBar>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow(){}
private slots:
    void openFile() {
        QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("All Files (*)"));
        if (!filePath.isEmpty()) {
            statusBarLabel->setText("Selected file: " + filePath);
        }
    }

private:
    QLabel *statusBarLabel;
};

MainWindow::MainWindow(QWidget *parent )
    : QMainWindow(parent) {
    QToolBar *toolBar = new QToolBar("MyToolBar", this);
   addToolBar(toolBar);

   QAction *openAction = new QAction("Open", this);
   connect(openAction, SIGNAL(triggered()), this, SLOT(openFile()));
   toolBar->addAction(openAction);

   statusBarLabel = new QLabel(this);

   statusBar()->addWidget(statusBarLabel);
};
#include "main.moc"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}

