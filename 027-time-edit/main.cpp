#include <QApplication>
#include <QWidget>
#include <QTimeEdit>
#include <QVBoxLayout>
#include <QDebug>

class MyWidget : public QWidget {
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        QTimeEdit *timeEdit = new QTimeEdit(this);
        timeEdit->setTimeRange(QTime(0, 0, 0), QTime(23, 59, 59)); // 设置时间范围
        timeEdit->setTime(QTime::currentTime()); // 设置默认时间为当前时间

        connect(timeEdit, SIGNAL(timeChanged(const QTime&)), this, SLOT(onTimeChanged(const QTime&)));

        layout->addWidget(timeEdit);
        setLayout(layout);
    }

private slots:
    void onTimeChanged(const QTime &time) {
        qDebug() << "Selected Time:" << time.toString("hh:mm:ss");
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MyWidget widget;
    widget.setWindowTitle("QTimeEdit Example");
    widget.show();

    return app.exec();
}
#include "main.moc"