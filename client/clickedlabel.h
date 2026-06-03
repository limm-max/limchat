#ifndef CLICKEDLABEL_H
#define CLICKEDLABEL_H
#include<QLabel>

//普通 / 选中（用于密码可见切换这种 toggle 场景）
enum ClickLbState{
    Normal=0,
    Selected=1
};

class ClickedLabel:public QLabel
{
    Q_OBJECT
public:
    ClickedLabel(QWidget* parent=nullptr);
    void SetState(QString normal, QString hover, QString press,
                  QString select, QString select_hover, QString select_press);
    ClickLbState GetCurState();

protected:
    void mousePressEvent(QMouseEvent *event) override;  //鼠标点击
    void mouseReleaseEvent(QMouseEvent *event) override;    //鼠标释放
    void enterEvent(QEnterEvent *event) override;   //鼠标悬停
    void leaveEvent(QEvent *event) override;    //鼠标离开

signals:
    void clicked();   // QLabel 没有这个信号

private:
    ClickLbState _curstate = ClickLbState::Normal;

    // 六种状态对应的 qss property 值,不同状态下展示不同的字和颜色
    QString _normal;
    QString _normal_hover;
    QString _normal_press;
    QString _selected;
    QString _selected_hover;
    QString _selected_press;
};

#endif // CLICKEDLABEL_H
