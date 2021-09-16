#include <iostream>


void fibbancchi(int a){
	for(int i=0;i<a;++i){
		
		std::cout<<(i-1)+(i-2)<<", ";
	}
}

int main(){
	int num;
	std::cout<<"Enter number: ";
	std::cin>>num;
	
	// fail safe
	if(std::cin.fail()){
		num=100;
	}
	
	fibbancchi(num);
	std::cout<<std::endl;
	return 0;
}