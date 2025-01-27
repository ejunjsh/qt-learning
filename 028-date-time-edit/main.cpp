#include <QApplication>
#include <QWidget>
#include <QDateTimeEdit>
#include <QVBoxLayout>
#include <QDebug>

class MyWidget : public QWidget {
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        QDateTimeEdit *dateTimeEdit = new QDateTimeEdit(this);
        dateTimeEdit->setDateRange(QDate(2000, 1, 1), QDate(2100, 12, 31)); // 设置日期范围
        dateTimeEdit->setTimeRange(QTime(0, 0, 0), QTime(23, 59, 59)); // 设置时间范围
        dateTimeEdit->setDateTime(QDateTime::currentDateTime()); // 设置默认日期和时间为当前日期和时间

        connect(dateTimeEdit, SIGNAL(dateTimeChanged(const QDateTime&)), this, SLOT(onDateTimeChanged(const QDateTime&)));

        layout->addWidget(dateTimeEdit);
        setLayout(layout);
    }

private slots:
    void onDateTimeChanged(const QDateTime &dateTime) {
        qDebug() << "Selected Date and Time:" << dateTime.toString("yyyy-MM-dd hh:mm:ss");
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MyWidget widget;
    widget.setWindowTitle("QDateTimeEdit Example");
    widget.show();

    return app.exec();
}

#include "main.moc"