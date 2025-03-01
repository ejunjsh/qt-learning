#include <QApplication>
#include <QtQuickWidgets/QQuickWidget>
#include <QQuickView>
#include <QHBoxLayout>
#include <QLabel>

int main(int argc, char *argv[])
{
    // QApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    
    QApplication app(argc, argv);
    
    QWidget * widget = new QWidget;
    widget->setWindowTitle("widget 主窗口");
    widget->resize(800, 400);
    
    // 设置布局
    QHBoxLayout * layout = new QHBoxLayout;
    layout->setContentsMargins(0, 0, 0 ,0);
    widget->setLayout(layout);
    
    // qml 界面 嵌入到 widget
    QQuickWidget qmlWidget(QUrl("qrc:/main.qml"));
    qmlWidget.setResizeMode(QQuickWidget::SizeRootObjectToView );
    // 设置这个之后 anchor不用设置，root节点大小会根据 QQuickWidget大小改变
    // 在qml里 通过 parent 获取不到 widget 窗口 !!!   
    layout->addWidget(&qmlWidget);
    
    // widget 界面 嵌入到 qmlWidget里
    QLabel label("QLabel", &qmlWidget);
    label.move(100, 100);
    
    // widget 界面 嵌入到 widget
    QLabel nativeWidget;
    nativeWidget.setText("Widget");
    nativeWidget.setAlignment(Qt::AlignCenter);
    layout->addWidget(&nativeWidget);
    
    widget->show();
    
    return app.exec();
}