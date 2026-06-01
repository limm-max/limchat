#include "global.h"

//改了控件的动态属性，Qt 不会自动重新套用样式表，必须 unpolish 再 polish 一下强制重刷
std::function<void(QWidget*)> repolish=[](QWidget* w){
    w->style()->unpolish(w);
    w->style()->polish(w);
};

//服务器地址不写四，后续通过config.ini读进来
QString gate_url_prefix = "";