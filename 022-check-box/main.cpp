#include <QApplication>
#include <QWidget>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QDebug>

class MyWidget : public QWidget {
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        QCheckBox *checkBox = new QCheckBox("Enable Option", this);
        connect(checkBox, SIGNAL(stateChanged(int)), this, SLOT(onCheckBoxStateChanged(int)));

        layout->addWidget(checkBox);
        setLayout(layout);
    }

private slots:
    void onCheckBoxStateChanged(int state) {
        if (state == Qt::Checked) {
            qDebug() << "Option Enabled";
        } else {
            qDebug() << "Option Disabled";
        }
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MyWidget widget;
    widget.setWindowTitle("QCheckBox Example");
    widget.show();

    return app.exec();
}

#include "main.moc"
