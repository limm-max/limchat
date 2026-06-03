#include "registerdialog.h"

#include "ui_registerdialog.h"

RegisterDialog::RegisterDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->page);

    ui->pass_visible->setCursor(Qt::PointingHandCursor);
    ui->pass_visible->SetState("unvisible", "unvisible_hover", "",
                               "visible", "visible_hover", "");
    ui->confirm_visible->setCursor(Qt::PointingHandCursor);
    ui->confirm_visible->SetState("unvisible", "unvisible_hover", "",
                               "visible", "visible_hover", "");

    connect(ui->pass_visible, &ClickedLabel::clicked, this, [this]() {
        auto state = ui->pass_visible->GetCurState();
        if (state == ClickLbState::Normal) {
            ui->pass_edit->setEchoMode(QLineEdit::Password);  // 隐藏
        } else {
            ui->pass_edit->setEchoMode(QLineEdit::Normal);    // 显示明文
        }
    });

    connect(ui->confirm_visible, &ClickedLabel::clicked, this, [this]() {
        auto state = ui->confirm_visible->GetCurState();
        if (state == ClickLbState::Normal) {
            ui->confirm_edit->setEchoMode(QLineEdit::Password);  // 隐藏
        } else {
            ui->confirm_edit->setEchoMode(QLineEdit::Normal);    // 显示明文
        }
    });

    connect(ui->return_btn,&QPushButton::clicked,this,&RegisterDialog::sigSwitchLogin);
    connect(ui->cancel_btn,&QPushButton::clicked,this,&RegisterDialog::sigSwitchLogin);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}
