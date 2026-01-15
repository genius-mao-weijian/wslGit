//#include <iostream>
//#include <string>
//extern int temp;//extern关键字，告诉编译器这个变量在其他文件定义，是一个全局变量
//void Message(std::string& message);//C++在调用某一个函数时，必须要前置声明，告诉编译器，放心编译，这个函数存在
//void static_1() {
//	std::string message;
//	Message(message);//实际上，编译时可以成功的的，但是链接时会报错，因为这个函数在main里被定义为static
//	temp = 10;//事实上，由于main中定义它为static，所以会产生连接错误
//}