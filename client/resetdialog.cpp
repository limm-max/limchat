#include "resetdialog.h"
#include "ui_resetdialog.h"

ResetDialog::ResetDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ResetDialog)
{
    ui->setupUi(this);
    connect(ui->return_btn,&QPushButton::clicked,this,&ResetDialog::sigSwitchLogin);
}

ResetDialog::~ResetDialog()
{
    delete ui;
}
