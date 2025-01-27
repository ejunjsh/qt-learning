#include <QApplication>
#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QListWidgetItem>
#include <QDebug>

class MyWidget : public QWidget {
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        QListWidget *listWidget = new QListWidget(this);

        QListWidgetItem *item1 = new QListWidgetItem("Item 1");
        QListWidgetItem *item2 = new QListWidgetItem("Item 2");
        
        listWidget->addItem(item1);
        listWidget->addItem(item2);

        connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onItemClicked(QListWidgetItem*)));

        layout->addWidget(listWidget);
        setLayout(layout);
    }

private slots:
    void onItemClicked(QListWidgetItem *item) {
        qDebug() << "Selected Item:" << item->text();
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MyWidget widget;
    widget.setWindowTitle("QListWidget Example");
    widget.show();

    return app.exec();
}

#include "main.moc"