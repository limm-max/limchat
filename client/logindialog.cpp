#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->pass_visible->setCursor(Qt::PointingHandCursor);
    ui->pass_visible->SetState("unvisible", "unvisible_hover", "",
                               "visible", "visible_hover", "");
    connect(ui->pass_visible, &ClickedLabel::clicked, this, [this]() {
        auto state = ui->pass_visible->GetCurState();
        if (state == ClickLbState::Normal) {
            ui->pass_edit->setEchoMode(QLineEdit::Password);  // 隐藏
        } else {
            ui->pass_edit->setEchoMode(QLineEdit::Normal);    // 显示明文
        }
    });

    connect(ui->reg_btn,&QPushButton::clicked,this,&LoginDialog::switchRegister);
    connect(ui->forget_label,&ClickedLabel::clicked,this,&LoginDialog::switchReset);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}
