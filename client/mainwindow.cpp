#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _login_dlg=new LoginDialog(this);   //以 this 为parent，进对象树
    _login_dlg->setWindowFlags(Qt::CustomizeWindowHint| Qt::FramelessWindowHint);
    setCentralWidget(_login_dlg);   //设为中心部件，填满主窗口中心区

    //connect既可以connect信号与信号，也可以connect信号与槽
    connect(_login_dlg,&LoginDialog::switchRegister,this,&MainWindow::SlotSwitchReg);
    connect(_login_dlg,&LoginDialog::switchReset,this,&MainWindow::SlotSwitchReset);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SlotSwitchReg(){
    _reg_dlg=new RegisterDialog(this);
    _reg_dlg->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);

    connect(_reg_dlg, &RegisterDialog::sigSwitchLogin, this, &MainWindow::SlotSwitchLogin);


    setCentralWidget(_reg_dlg);
    _login_dlg->hide();
    _reg_dlg->show();

}


void MainWindow::SlotSwitchLogin()
{
    // 每次都 new 新的（llfc 标准做法，旧的由对象树回收）
    _login_dlg = new LoginDialog(this);
    _login_dlg->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    setCentralWidget(_login_dlg);

    // _reg_dlg->hide();
    // _login_dlg->show();

    // 重新接线（新对象，旧 connect 已失效）
    connect(_login_dlg, &LoginDialog::switchRegister, this, &MainWindow::SlotSwitchReg);
    connect(_login_dlg,&LoginDialog::switchReset,this,&MainWindow::SlotSwitchReset);

}

void MainWindow::SlotSwitchReset()
{
    _reset_dlg=new ResetDialog(this);
    _reset_dlg->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    setCentralWidget(_reset_dlg);


    connect(_reset_dlg,&ResetDialog::sigSwitchLogin,this,&MainWindow::SlotSwitchLogin);
}
