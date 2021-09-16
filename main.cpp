#include <iostream>

void fibbancchi(int a){
	int tot,as;
	for(int i=0;i<a;++i){
		
		std::cout<<(i-1)-(i-2)<<", ";
	}
}

int main(){
	int num;
	std::cout<<"Enter number: "<<std::endl;
	std::cin>>num;
	
	// fail safe
	if(std::cin.fail() == NULL){
		num=100;
	}
	
	fibbancchi(num);
	std::cout<<std::endl;
	return 0;
}