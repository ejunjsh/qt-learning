#include <QApplication>
#include <QWidget>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QTimer>

class MyWidget : public QWidget {
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        QProgressBar *progressBar = new QProgressBar(this);
        progressBar->setRange(0, 100); // 设置范围为 0 到 100
        progressBar->setValue(0); // 初始值为 0

        layout->addWidget(progressBar);
        setLayout(layout);

        // 模拟任务进度的更新
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(updateProgress()));
        timer->start(1000); // 每秒更新一次进度
    }

private slots:
    void updateProgress() {
        QProgressBar *progressBar = findChild<QProgressBar*>();
        if (progressBar) {
            int currentValue = progressBar->value();
            if (currentValue < 100) {
                progressBar->setValue(currentValue + 10); // 每次增加 10
            }
        }
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MyWidget widget;
    widget.setWindowTitle("QProgressBar Example");
    widget.show();

    return app.exec();
}
#include "main.moc"


