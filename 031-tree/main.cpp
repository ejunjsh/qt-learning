#include <QApplication>
#include <QWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QVBoxLayout>
#include <QDebug>

class MyWidget : public QWidget {
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        QTreeWidget *treeWidget = new QTreeWidget(this);
        QTreeWidgetItem *rootItem = new QTreeWidgetItem(treeWidget);
        rootItem->setText(0, "Root Node");

        QTreeWidgetItem *childItem = new QTreeWidgetItem(rootItem);
        childItem->setText(0, "Child Node");

        treeWidget->addTopLevelItem(rootItem);

        connect(treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(onItemClicked(QTreeWidgetItem*, int)));

        layout->addWidget(treeWidget);
        setLayout(layout);
    }

private slots:
    void onItemClicked(QTreeWidgetItem *item, int column) {
        qDebug() << "Selected Node:" << item->text(column);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MyWidget widget;
    widget.setWindowTitle("QTreeWidget Example");
    widget.show();

    return app.exec();
}

#include "main.moc"
