#include<iostream> 
using std::cout;
using std::endl;
using std::cin;

bool es primo(int);//prototipo de funcion

int main(){
	//    
    
    
}

//definicion de funcion

//la funcion es primo devuelve verdadero cuando valida un numero primo
bool es primo(int num){
  	 
       	int counter=0;
  
	//un numero es primo cuando solo se se puede dividir entre 1 y el mismo
	 		 	 		 
    	for(int i=1;i<=num;i++){//prueba exhaustiva de numeros entre [1 y num] 
		if(num%i==0){
			counter++;
		}
	}
    	
	return counter==2;//si el counter es 2 significa que el numero es divisible solamente entre 1 y el mismo
}
