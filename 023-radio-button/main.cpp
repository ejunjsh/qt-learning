#include <QApplication>
#include <QWidget>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QDebug>

class MyWidget : public QWidget {
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        QRadioButton *radioButton1 = new QRadioButton("Option 1", this);
        QRadioButton *radioButton2 = new QRadioButton("Option 2", this);

        connect(radioButton1, SIGNAL(clicked()), this, SLOT(onRadioButtonClicked()));
        connect(radioButton2, SIGNAL(clicked()), this, SLOT(onRadioButtonClicked()));

        layout->addWidget(radioButton1);
        layout->addWidget(radioButton2);
        setLayout(layout);
    }

private slots:
    void onRadioButtonClicked() {
        QRadioButton *radioButton = qobject_cast<QRadioButton*>(sender());
        if (radioButton) {
            qDebug() << "Selected Option:" << radioButton->text();
        }
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MyWidget widget;
    widget.setWindowTitle("QRadioButton Example");
    widget.show();

    return app.exec();
}

#include "main.moc"