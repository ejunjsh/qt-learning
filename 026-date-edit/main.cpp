#include <QApplication>
#include <QWidget>
#include <QDateEdit>
#include <QVBoxLayout>
#include <QDebug>

class MyWidget : public QWidget {
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        QDateEdit *dateEdit = new QDateEdit(this);
        dateEdit->setDateRange(QDate(2000, 1, 1), QDate(2100, 12, 31)); // 设置日期范围
        dateEdit->setDate(QDate::currentDate()); // 设置默认日期为当前日期

        connect(dateEdit, SIGNAL(dateChanged(const QDate&)), this, SLOT(onDateChanged(const QDate&)));

        layout->addWidget(dateEdit);
        setLayout(layout);
    }

private slots:
    void onDateChanged(const QDate &date) {
        qDebug() << "Selected Date:" << date.toString("yyyy-MM-dd");
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MyWidget widget;
    widget.setWindowTitle("QDateEdit Example");
    widget.show();

    return app.exec();
}

#include "main.moc"