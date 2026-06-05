#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QtUiTools/QUiLoader>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile qss(":/style/stylesheet.qss");    //用资源路径（: 开头）打开打包进 exe 的 qss 文件，不是硬盘路径。
    if(qss.open(QFile::ReadOnly)){
        qDebug() << "qss open success";
        QString style = QLatin1String(qss.readAll());  // 读出全部内容转成字符串
        a.setStyleSheet(style);                          // 应用到整个应用
        qss.close();
    }else {
        qDebug() << "qss open failed";
    }

    MainWindow w;
    w.show();
    return QCoreApplication::exec();
}
