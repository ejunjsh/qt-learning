#include <QApplication>
#include <QWidget>
#include <QComboBox>
#include <QVBoxLayout>
#include <QDebug>

class MyWidget : public QWidget {
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        QComboBox *comboBox = new QComboBox(this);
        comboBox->addItem("Option 1");
        comboBox->addItem("Option 2");
        comboBox->addItem("Option 3");

        connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxIndexChanged(int)));

        layout->addWidget(comboBox);
        setLayout(layout);
    }

private slots:
    void onComboBoxIndexChanged(int index) {
        qDebug() << "Selected Option:" << index;
    }
};
#include "main.moc"
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MyWidget widget;
    widget.setWindowTitle("QComboBox Example");
    widget.show();

    return app.exec();
}
