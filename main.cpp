#include <stdio.h>
#include "Stack.h"

void prnMenu(){
	cout<<"*******************************************"<<endl;
	cout<<"* 1. insertion     2. delete    3. Print    4.end  *"<<endl;
	cout<<"*******************************************"<<endl;
	cout<<endl;
	cout<<"Please select your desired menu: ";
}

int main(){
	    int mode, selectNumber, tmpItem;
		LinkedList<int> *p;
		bool flag = false;

		cout<<"data structure selection(1: Stack, Other: Linked List): ";
		cin>>mode;
						    
		if(mode == 1)
			p = new Stack<int>();    // stack of integers
			
		else
			p = new LinkedList<int>();


		do{
			prnMenu();
			cin>>selectNumber;
			
			switch(selectNumber){ 
				case 1:
					cout<<"Please enter your desired value: ";
					cin>>tmpItem;    p->Insert(tmpItem);
					cout<<tmpItem<<"inserted."<<endl;
					break;
					
				case 2:
					if(p->Delete(tmpItem)==true)
						cout<<tmpItem<<"deleted."<<endl;
						
					else cout<<"is empty. failed to delete"<<endl;
					break;
					
				case 3:
					cout<<"size: "<<p->GetSize()<<endl;
					p->Print();
					break;
					
				case 4:
					flag = true;     break;
					
				default:
					cout<<"you made a typo."<<endl;
					break;
			
			}
			
			if(flag) break;
			
		} while(1);
		
		return 0;
}
