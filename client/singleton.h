#ifndef SINGLETON_H
#define SINGLETON_H
#include<mutex>
#include<memory>


//单例模板
template<typename T>
class Singleton{
protected:
    Singleton()=default;
    Singleton(const Singleton<T>&)=delete;
    Singleton& operator=(const Singleton<T>&)=delete;

    static std::shared_ptr<T> _instance;    //唯一实例

public:
    static std::shared_ptr<T> Getinstance()
    {
        static std::once_flag s_flag;
        std::call_once(s_flag,[&](){
            _instance=std::shared_ptr<T>(new T);
        });
        return _instance;
    }
    ~Singleton()=default;
};

// 静态成员要在类外定义一次
template<typename T>
std::shared_ptr<T> Singleton<T>::_instance=nullptr;





#endif // SINGLETON_H
