#include<iostream> 
using std::cout;
using std::endl;
using std::cin;

bool es primo(int);//prototipo de funcion

int main(){
	// menu repetitivo
	char opcion;
        do{
                cout<<"\ningrese una opcion\n1.op1\n2.op2\n3.op3\n4.salir\n\n?:";cin>>opcion;
                //la opcion es procesada en una estructura de casos
                switch(opcion){
                        case '1':
                                break;
                        case '2':
                                break;

                        case '3': 
                                break;
                        case '4':
                                cout<<"\nhasta luego"<<endl;
                                break;

                        default:cout<<"\nno ingreso una opcion correcta/intente de nuevo"<<endl;
                }
        }while(opcion!='4');   
    
    
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

