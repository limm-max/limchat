#ifndef GLOBAL_H
#define GLOBAL_H

#include<QWidget>
#include<QStyle>
#include<QString>
#include<functional>

//刷新控件样式
extern std::function<void(QWidget*)>   repolish;


//GateServer 的 url 前缀（如 http://localhost:8080），由 main 读 config.ini 填入
extern QString gate_url_prefix;

//网络http请求ID，标识"这是哪种请求"
enum ReqId{
    ID_GET_VARIFY_CODE=1001,
    ID_REG_USER       =1002,
};

// 错误码：和后端约定一致
enum ErrorCodes {
    SUCCESS     = 0,
    ERR_JSON    = 1,   // JSON 解析失败
    ERR_NETWORK = 2,   // 网络错误
};



// 模块：标识"这个回包该交给哪个界面"
enum Modules {
    REGISTERMOD = 0,
};



#endif // GLOBAL_H
