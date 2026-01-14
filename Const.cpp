#include <iostream>
#include <string>
class Const {
private:
	mutable int m_x;//将它声明为mutable,这时就可以在GetX函数中修改m_x的值
	int m_y = 10;
	const int m_z;//const int m_z = 1;C++中不允许这样初始化一个const变量

public:
	Const():
		m_z(1){ }
	//Const() {
	//	m_z = 1;//同样，也不能这样对const成员变量进行赋值
	//}
	int GetX() const {//这意味着我承诺不会修改类对象的变量
		m_x = 10;
		return m_x;//可以修改，由此，可以根据这个特性，来把x当作一个统计我这个函数被调用了多少次的变量
		//m_y = 5;//这是不允许的，因为你已经承诺不会修改这个类对象的变量（const）
	}
	const int GetY(){//这意味着函数的返回值是不能被修改的
		return m_y;
	}
	int GetZ() {
	}
};
int main() {
	
	const int a = 0;
	int b = 10;

	const int* p = &a;//可以通过const int* p来访问a的值，但是不能通过p来改变a的值，但可以改变p的指向
	int* q = const_cast<int*>(p);//类型强制转换

	*q = 20;//这个时候是可以改变它的值的，但程序输出仍然是0，因为编译器已经做了优化，默认a的值是0
	std::cout << a << std::endl;

	int* const ptr = &b;//指针ptr被固定，只能指向b，但可以改变ptr说指向的内容的值
	*ptr = 20;

	std::cout << b << std::endl;
	int x = 0;

	Const mao;//如果我没有给我的const成员进行列表初始化，会说默认构造函数被删除
	//原因就是C++中，不允许在除了列表初始化这种方式外对const成员进行初始化，也就是说，系认默认的构造函数，是没有办法对m_z进行赋值的
	// 所以编译器会报错
	//mao.GetY() = 0;//这个时候就不能修改SetX的返回值
	mao.GetX();
	return 0;
}
