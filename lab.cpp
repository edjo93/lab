#include<iostream> 
using std::cout;
using std::endl;
using std::cin;

#include<string>
using std::string;

#include<sstream>
using std::stringstream;

#include<vector>
using std::vector;

void imprimir_array(int*,int );
bool es_primo(int);//prototipo de funcion
void generar_primos(int*,int);
int* get_array(int );
void free_array(int*);
string calculadoraPrimos(int*,int);
int main(){
        int size=25;
        int*array=NULL;
        
        
        
	// menu repetitivo
	char opcion;
        do{
                cout<<"\ningrese una opcion\n1.op1\n2.teorema fund. aritmetica\n3.op3\n4.salir\n\n?:";cin>>opcion;
                //la opcion es procesada en una estructura de casos
                switch(opcion){
                        case '1':
                                break;
                        case '2':
				
				//numero ingresado
				int num;
				cout<<"ingrese numero: ";
				cin>>num;

				//validar numero si es necesario
				
				
				array=get_array(size);//el array contendra los 25 primeros numeros primos
				
				generar_primos(array,size);

				//imprimir_array(array,size);

				//el array de primos contiene informacion necesaria para construir los datos solicitados
                                
                                cout<<calculadoraPrimos(array,num);
        

				//no olvidemos liberar memoria con delete
                                free_array(array);
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
bool es_primo(int num){
  	 
       	int counter=0;
  
	//un numero es primo cuando solo se se puede dividir entre 1 y el mismo
	 		 	 		 
    	for(int i=1;i<=num;i++){//prueba exhaustiva de numeros entre [1 y num] 
		if(num%i==0){
			counter++;
		}
	}
    	
	return counter==2;//si el counter es 2 significa que el numero es divisible solamente entre 1 y el mismo

}

int* get_array(int size){
	//devuelve un apuntador a un array
	int* array=NULL;
	array=new int[size];
	
	return array;

}



//funcion para llenar el arreglo con los primeros numeros primos
void generar_primos(int*array,int size){
	int add=0;//controla el ingreso de datos al arreglo
	for(int i=1;i<=100;i++){//los primeros 25 numeros primos estan entre 1 y 100
		if(es_primo(i)){//si el numero a probar es primo se agrega al arreglo
			array[add++]=i;
		}
	}
}

void imprimir_array(int*array,int size){
	for(int i=0;i<size;i++){
		cout<<"["<<array[i]<<"]";
	}
	
}

void free_array(int*array){
        //libera memoria reservada a un array con una condicion
        if(array!=NULL){
                delete[] array;
                array=NULL;//buena practica asignar null al apuntador del arreglo ya liberado
        }   
	
}
string calculadoraPrimos(int*array,int num){
        bool comprobacion=false;
        stringstream stream;
        string resultado="";
        vector <int> exponentes;
        vector <int> bases;
        int counter=0;//exponente del numero primo
        int pull=0;//controla la extraccion del datos del arreglo
        int pullArray=0;//controla la extraccion de datos del arreglo
        
        while(!comprobacion){// no se haya comprobado
                if(num%array[pull]==0){
                        num=num/array[pull];//el numero cambia
                        
                        counter++;//aumenta el exponente del numero primo
                        if(num==1){
                                //se suben los datos porque ya no se ingresa al caso else
                                
                                bases.push_back(array[pull]);
                                exponentes.push_back(counter);
                                
                                comprobacion=true;
                        }
                }else{//fallo de la comprobacion
                                pullArray=pull;//elemento temporal
                                pull++;
                                if(counter>0){//se agrega el contador al vector
                                        bases.push_back(array[pullArray]);
                                        exponentes.push_back(counter);      
                                }                                
                                
                                counter=0;
                        
                }
                
        }
        
        //dependemos de uno de los 2 vectores para hacer la salida(size)
        
        for(int i=0;i<bases.size();i++){
                
                //stream.clear();
                stream<<bases.at(i) <<"^"<<exponentes.at(i)<<"*";
                
                resultado=stream.str();
        }
        
        return resultado;
}
