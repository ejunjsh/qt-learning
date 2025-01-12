#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QDebug>
#include <QApplication>
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow(){}
private slots:
    void openFile() {
        QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("All Files (*)"));
        if (!filePath.isEmpty()) {
            qDebug() << "Selected file: " << filePath;
        }
    }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *menuBar = new QMenuBar(this);
    QMenu *fileMenu = menuBar->addMenu(tr("File"));

    QAction *openAction = new QAction(tr("Open"), this);
    fileMenu->addAction(openAction);
    connect(openAction, SIGNAL(triggered()), this, SLOT(openFile()));
    setMenuBar(menuBar);
}
#include "main.moc"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
