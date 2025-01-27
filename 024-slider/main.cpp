#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QVBoxLayout>
#include <QDebug>

class MyWidget : public QWidget {
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        QSlider *slider = new QSlider(Qt::Horizontal, this);
        slider->setRange(0, 100); // 设置范围为 0 到 100
        slider->setSingleStep(1); // 步长为 1

        connect(slider, SIGNAL(valueChanged(int)), this, SLOT(onSliderValueChanged(int)));

        layout->addWidget(slider);
        setLayout(layout);
    }

private slots:
    void onSliderValueChanged(int value) {
        qDebug() << "Slider Value:" << value;
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MyWidget widget;
    widget.setWindowTitle("QSlider Example");
    widget.show();

    return app.exec();
}

#include "main.moc"
