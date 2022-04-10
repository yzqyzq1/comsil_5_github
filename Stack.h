#include "LinkedList.h"


//1. 必须扩展到模板类
//2. 必须以Stack格式重新定义Delete函数
//注意:first, current_size必须使用this指针获取，因为它是class的成员变量

//继承LinkedList类
template<class T>
class Stack : public LinkedList<T> {
	public:
		bool Delete (T &element) {
			//如果first为0，则返回false
			if (this->first == NULL)
				return false;
			Node<T>* t = this->first->link;
			element = this->first->data;
			delete this->first;
			this->first = t;
			this->current_size=this->current_size-1;
			return true;
		}
};
