#### 虚函数与多态



#### 虚析构函数

为什么要有虚析构函数?

如果一个类不作为基类, 那么它不需要有虚析构函数. 

但是如果一个类会作为基类且没有定义虚析构函数, 定义了一个基类指针, 指向子类, 那么在delete这个指针的时候, 将不会执行子类的析构函数(都会执行父类的析构函数). 当然, 如果该指针是子类指针, 那么会执行子类的析构函数. 

而子类的析构函数会用来做一些指针的清理工作, 因此会造成内存泄漏.

例如下面的代码

```cc
#include <iostream>
using namespace std;

class Base {
    public:
    Base() {};
    // virtual ~Base() {
    ~Base() {
        cout << "~ of 1" << endl;
    };

    virtual void DoSomething() {
        cout << "something ... 1" << endl;
    }
};

class NewClass: public Base {
    public:
    NewClass() {};
    ~NewClass() {
        cout << "~ of 2" << endl;
    }
    void DoSomething() {
        cout << "something ... 2\n";
    }
};

int main() {
    Base *p1 = new NewClass();
    p1->DoSomething();
    delete p1;

    NewClass *p2 = new NewClass();
    p2->DoSomething();
    delete p2;
}
```

执行的结果是

```bash
something ... 2
~ of 1
something ... 2
~ of 2
~ of 1
```

[参考资料](https://blog.csdn.net/starlee/article/details/619827)

