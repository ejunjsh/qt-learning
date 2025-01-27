#include <QApplication>
#include <QWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QLabel>

class MyWidget : public QWidget {
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        QTabWidget *tabWidget = new QTabWidget(this);

        QWidget *page1 = new QWidget();
        QLabel *label1 = new QLabel("Content of Tab 1", page1);
        QVBoxLayout *page1Layout = new QVBoxLayout(page1);
        page1Layout->addWidget(label1);
        page1->setLayout(page1Layout);
        tabWidget->addTab(page1, "Tab 1");

        QWidget *page2 = new QWidget();
        QLabel *label2 = new QLabel("Content of Tab 2", page2);
        QVBoxLayout *page2Layout = new QVBoxLayout(page2);
        page2Layout->addWidget(label2);
        page2->setLayout(page2Layout);
        tabWidget->addTab(page2, "Tab 2");

        layout->addWidget(tabWidget);
        setLayout(layout);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MyWidget widget;
    widget.setWindowTitle("QTabWidget Example");
    widget.show();

    return app.exec();
}

#include "main.moc"
