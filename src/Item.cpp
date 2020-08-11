#include <Item.h>
#include <iostream>


Item::Item(string x, int y){

 name=x;
 price=y;

}
	
int Item::GetPrice(){
		return price;
		cout<<price;
	}
	
	
string Item::GetName(){
		return name;
	}
