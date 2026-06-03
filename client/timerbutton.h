#ifndef TIMERBUTTON_H
#define TIMERBUTTON_H
#include <QPushButton>
#include<QTimer>

class TimerButton:public QPushButton
{
    Q_OBJECT
public:
    TimerButton(QWidget *parent=nullptr);
    ~TimerButton();

protected:
    void mouseReleaseEvent(QMouseEvent *e) override;//重写鼠标释放

private:
    QTimer *_timer;
    int _counter;
};

#endif // TIMERBUTTON_H
