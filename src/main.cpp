#include <iostream>
#include <string>
#include <vector>
//链接器把所有的文件链接到一起
//如果这个时候，有一个函数或者变量同时被两个文件定义，就会产生链接错误，它没办法确定你用的是哪个函数
class Static {
public:
	//Static():
		//a(1){}//这时会报错，因为我声明的这个静态变量，它属于整个类
	//不属于某一个类对象，所以它无法用某一个类对象的构造函数对它初始化
	//这样就可以防止这个属于全部类对象被某个类对象初始化造成不必要的麻烦
	static void SetX();
private:
	static int a;
};

int Static::a = 0;//要在类外进行初始化
void Static::SetX() {
	a++;
	std::cout << a << std::endl;
}//通过成员函数来改变a的值

static void Message(std::string& message) {
	//定义为static，这个函数就成为了这个文件私有的函数，其他文件无法访问
	std::cout << message << std::endl;
}
static int temp = 10;
const int count() {
	static int i = 0;
	i++;
	temp++;
	return i;
}
int main() {
	std::string message;
	Message(message);
	std::cout << count() << std::endl;
	std::cout << count() << std::endl;
	std::cout << count() << std::endl;
	std::cout << count() << std::endl;
	std::cout << count() << std::endl;//会出现1 2 3 4 5，这是因为这个i变量被声明为静态变量，作用域是函数内部，但生命周期是程序运行周期
	Static* mao = new Static[5];
	for (int i = 0; i < 5; i++) {
		mao[i].SetX();
	}
	delete[] mao;
}