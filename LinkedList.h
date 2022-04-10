#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

//LinkedList Node
template<class T>  
class Node{
	public:
		//保存数据的变量
		T data;
		//利用节点结构体;指针要保存下一个节点的地址
		Node *link;

		Node(T element){
		  data = element;
		  link = 0;
		}
	};

//LinkedList Class
template<class T> 
class LinkedList{
	protected:
		//指针要保存第一个节点的地址
		Node<T> *first;
		int current_size;
	public:
		//初始化，创建器
		LinkedList(){
			first = 0;
			current_size = 0;
		};

		//返回节点数量
		int GetSize(){
			return current_size;
		};

		//在最前面插入元素，LinkedList和Stack都是一样的
		void Insert(T element);
		
		//删除最后面的元素, 删除最后加入的元素 - LinkedList
		virtual bool Delete(T &element);

		//输出列表
		void Print();
};


//在最前面粘贴新节点并输入值
template<class T> 
void LinkedList<T>::Insert(T element){
	//节点生成
	Node<T> *newnode = new Node<T>(element);

	//新节点指向第一个节点
	//newnode是一个指针 -> 使用函数, 加载变量和newnode.link含义相同
	newnode -> link = first;
	first = newnode;
	current_size++;
}

//从内存中取消分配，同时返回最后一个节点的值
template<class T> 
bool LinkedList<T>::Delete(T &element){

	if (first == 0)
		return false;
	
	Node<T> *current = first;
	Node<T> *previous = 0;
	
	//查找到最后节点的重复句
	while(1){
		if (current->link == 0){  //查找最后一个节点
			if (previous)
				previous -> link = current -> link;
			else
				first = first -> link;
			break;
		}
		previous = current;
		current = current -> link;
	}
	element = current -> data;
	delete current;
	current_size--;

	return true;
}

//输出列表的Print函数
template<class T> 
void LinkedList<T>::Print(){
	Node<T> *i;
	int index = 1;

	if (current_size != 0){
		for( i = first; i != NULL; i=i->link){
			if (index == current_size){
				cout << "[" << index << "|";
				cout << i -> data <<"]";
			}		
			else {
				cout << "[" << index << "|";
				cout << i -> data << "]->";
				index++;
			}
		}
		cout << endl;
	}

}


#endif
