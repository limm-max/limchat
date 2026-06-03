#include "clickedlabel.h"
#include "global.h"      // repolish
#include <QMouseEvent>

ClickedLabel::ClickedLabel(QWidget* parent)
    :QLabel(parent)
{
    setCursor(Qt::PointingHandCursor);  // 鼠标移上去变小手
}

ClickLbState ClickedLabel::GetCurState()
{
    return _curstate;
}

//六种样式.
//例如密码可见不可见：normal不可见，
void ClickedLabel::SetState(QString normal, QString hover, QString press,
                            QString select, QString select_hover, QString select_press)
{
    _normal = normal;
    _normal_hover = hover;
    _normal_press = press;
    _selected = select;
    _selected_hover = select_hover;
    _selected_press = select_press;

    setProperty("state", normal);
    repolish(this);
}

//鼠标按下不作特殊处理，只有释放的时候才做处理。但是在视觉上呈现效果
void ClickedLabel::mousePressEvent(QMouseEvent* event)
{
    if(event->button()==Qt::LeftButton)
    {
        if(_curstate==ClickLbState::Normal)
        {
            _curstate=ClickLbState::Selected;
            setProperty("state",_selected_press);
        }else{
            _curstate=ClickLbState::Normal;
            setProperty("state",_normal_press);
        }
        repolish(this);
        update();
    }
    QLabel::mousePressEvent(event);

}

void ClickedLabel::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button()==Qt::LeftButton)
    {
        //按下的时候大状态就变了，释放之后，就变成了对应大状态的悬停，因为鼠标还没移走
        if (_curstate == ClickLbState::Normal) {
            setProperty("state", _normal_hover);
        } else {
            setProperty("state", _selected_hover);
        }
        repolish(this);
        update();
        emit clicked();   // 释放时才发 clicked，和 QPushButton 行为一致
    }
    QLabel::mouseReleaseEvent(event);
}

void ClickedLabel::enterEvent(QEnterEvent *event)
{
    if(_curstate==ClickLbState::Normal){
        setProperty("state",_normal_hover);
    }else
    {
        setProperty("state",_selected_hover);
    }
    repolish(this);
    update();
    QLabel::enterEvent(event);
}

void ClickedLabel::leaveEvent(QEvent *event)
{
    if (_curstate == ClickLbState::Normal) {
        setProperty("state", _normal);
    } else {
        setProperty("state", _selected);
    }
    repolish(this);
    update();
    QLabel::leaveEvent(event);
}