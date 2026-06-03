#include "timerbutton.h"
#include <QMouseEvent>

TimerButton::TimerButton(QWidget* parent)
    :QPushButton(parent),_counter(60)
    {
        _timer = new QTimer(this);

        connect(_timer,&QTimer::timeout,this,[this](){
            _counter--;
            if(_counter<=0){
                _timer->stop();
                _counter=10;
                this->setText("获取验证码");
                this->setEnabled(true);
                return;
            }
            this->setText(QString::number(_counter));
        });
    }

TimerButton::~TimerButton()
{
    _timer->stop();
}

//鼠标点击事件重写
void TimerButton::mouseReleaseEvent(QMouseEvent* e)
{
    if(e->button()==Qt::LeftButton){
        this->setEnabled(false);
        this->setText(QString::number(_counter));
        _timer->start(1000);    //单位是毫秒，所以每一秒刷新一次
        emit clicked(); //外部能接收到点击的信号
    }

    QPushButton::mouseReleaseEvent(e);  // 调基类，保证事件链不断
}