#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 诊断：列出资源区 :/ 下到底有什么
    qDebug() << "==== 资源区根目录内容 ====";
    QDir root(":/");
    for (const QString &entry : root.entryList()) {
        qDebug() << "  " << entry;
    }
    qDebug() << "==== :/style 下内容 ====";
    QDir styleDir(":/style");
    qDebug() << "  exists:" << styleDir.exists();
    for (const QString &entry : styleDir.entryList()) {
        qDebug() << "  " << entry;
    }

    QFile qss(":/style/stylesheet.qss");
    qDebug() << "qss exists:" << qss.exists();   // 关键：文件在不在资源区

    //QFile qss(":/style/stylesheet.qss");    //用资源路径（: 开头）打开打包进 exe 的 qss 文件，不是硬盘路径。
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
