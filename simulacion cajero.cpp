//Autor Darkarbryan

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

using namespace std;

int beep_tecla(){
	
	Beep(1100,300);
	
return 0;	
}

int beep_erroneo(){ //refinar	
	Beep(1500,100);
	Beep(1500,100);
	Beep(1500,100);
	Beep(1530,900);
	Beep(1500,100);
	Beep(1500,100);
	Beep(1500,100);
	Beep(1530,900);
	
	return 0;
}

int retirar(int ret,int fondos, int lim){	//funcion retirar	

	
	cout<<"\n\t\tFavor digitar el monto a retirar\n";
	cout<<"Se le informa que puede realizar retiros de hasta 600.000\n";
	cin>>ret;
	beep_tecla();
				
		if(ret<fondos){
					
			if(ret<lim){
				
				system("CLS");		
				cout<<"\nSe esta procesando su solicitud...\n";
				cout<<"...\n";
				cout<<"...\n";
				cout<<"Transaccion finalizada, su saldo actual es : "<<(fondos-ret)<<endl;
				cout<<"\nHemos terminado. HASTA PRONTO"<<endl;
						
					}else if(ret>lim){
					
						system("CLS");					
						cout<<"\nSe ha excedido del limite por retiros. \n"<<endl;
						cout<<"Hemos terminado. HASTA PRONTO"<<endl;
						beep_erroneo();

							}else{
						
								cout<<"\nDato ingresado no valido.\n"<<endl;
								cout<<"Hemos terminado. HASTA PRONTO"<<endl;
								beep_erroneo();
							
							}
					
			}else if(ret>fondos){
				
				system("CLS");	
				cout<<"\nQuerido usuario, su saldo es insuficiente.\n"<<endl;
				cout<<"Hemos terminado. HASTA PRONTO"<<endl;
				beep_erroneo();
					
					}else{
						
						cout<<"\nDato ingresado no valido.\n"<<endl;
						cout<<"Hemos terminado. HASTA PRONTO"<<endl;
						beep_erroneo();
						
					}				
	
	return 0;
}

int menu(int res, int ret, int fondos, int lim, int id, string nom, string ape, string erroneo){
	
		cout<<"Bienvenido. A continuacion se mostrara su cajero virtual.\n"<<endl;
	
	cout<<"\t\t\tCajero Virtual\n"<<endl;
	
	cout<<"\t\tSeleccione el tipo de cuenta.\n"<<endl;
	cout<<" \n"<<endl;
	cout<<"1. CUENTA CORRIENTE  	\t2. CUENTA DE AHORROS\n"<<endl;
	cout<<"\t\t\t";cin>>res;
	beep_tecla();
	system("CLS");
	
	switch (res){
		
		case 1:
			
			cout<<"\n\t\t¿Que transaccion desea realizar?\n"<<endl;
			cout<<" \n";
			cout<<"1. RETIRAR EFECTIVO  	\t2. REALIZAR GIRO\n"<<endl;
			cout<<"\n\t\t\t";cin>>res;
			beep_tecla();
			system("CLS");
			if(res==1){
				
				retirar(ret,fondos,lim);
				
			}else if(res==2){
			
				cout<<"\n\t\tFavor digitar el monto para girar\n";
				cout<<"\tSe le informa que puede realizar giros de hasta 600.000\n"<<endl;
				cout<<"\t\t\t\t";cin>>ret;
				beep_tecla();
				system("CLS");
				cout<<"\nFavor de ingresar la identificacion de la persona quien recibira el giro.\n"<<endl;
				cout<<"\t\t\t\t";cin>>id;
				beep_tecla();
				cout<<"\nA continuacion ingrese los datos de la persona destinataria."<<endl;
				cout<<"Ingrese nombre   :	";
				cin>>nom;
				beep_tecla();
				cout<<"Ingrese apellido :	";
				cin>>ape;
				beep_tecla();
				cout<<"\n"<<endl;
				
				if(ret<fondos){
					
					if(ret<lim){
						
						system("CLS");
						cout<<"\nSe esta procesando su solicitud...\n";
						cout<<"...\n";
						cout<<"...\n";
						cout<<"Transaccion finalizada. \n"<<endl;
						cout<<"\nIDENTIFICACION		:\t"<<id;
						cout<<"\nNOMBRE DESTINATARIO   	:\t"<<nom;
						cout<<"\nAPELLIDO DESTINATARIO 	:\t"<<ape;
						cout<<"\nVALOR GIRADO		:\t"<<ret;
						cout<<"\nSU SALDO ACTUAL ES	:\t"<<(fondos-ret)<<endl;
						cout<<"\nHemos terminado. HASTA PRONTO"<<endl;
						
					}else if(ret>lim){
						
							cout<<erroneo;

							}else{
						
								cout<<"\nDato ingresado no valido.\n"<<endl;
								cout<<"Hemos terminado. HASTA PRONTO"<<endl;
								beep_erroneo();
							
							}
					
				}else if(ret>fondos){
					
					cout<<"\nQuerido usuario, su saldo es insuficiente.\n"<<endl;
					cout<<"\nSU SALDO ACTUAL ES	:\t"<<fondos<<endl;
					cout<<"Hemos terminado. HASTA PRONTO"<<endl;					
					
					}else{
						
						cout<<erroneo;
						beep_erroneo();
						
					}
			}else{
				
				cout<<erroneo;
				beep_erroneo();
				
			}
		break;	
		
		case 2:
			
			system("CLS");
			cout<<"\n\t\t¿Que transaccion desea realizar?\n"<<endl;
			cout<<"\n";
			cout<<"1. RETIRAR EFECTIVO  	\t2. CONSULTAR SALDO\n"<<endl;
			cin>>res;
			beep_tecla();
			system("CLS");
			
			if (res==1){
				
				retirar(ret,fondos,lim);
				
			}else if(res==2){
				
				system("CLS");
				cout<<"\nSe esta procesando su solicitud...\n";
				cout<<"...\n";
				cout<<"...\n";
				cout<<"Transaccion finalizada. \n"<<endl;
				cout<<"\nSU SALDO ACTUAL ES		:\t"<<(fondos-ret)<<endl;
				cout<<"\nHemos terminado. HASTA PRONTO"<<endl;
				
			}else{
				
				cout<<erroneo;
				
			}
			
		break;	
		
		default:
			
			cout<<erroneo;
			
		break;	
			
	}
	
}

int main(){
	
	int res, ret, fondos, lim, id, psw=1234, in;
	fondos=1570000;
	lim=600000;
	
	string nom;
	string ape;
	string erroneo="\nDato ingresado no valido.\nHemos terminado. HASTA PRONTO";
	
						//VALIDACION DE USUARIO EN LA SUCURSAL ELECTRONICA//
	
	cout<<"\t\tLe damos la bienvenida a la sucursal electronica. \nPor seguridad se recomienda que no ingrese su clave en presencias de terceros.\n"<<endl;
	
	cout<<"\t\tPara empezar, digite la clave de su cuenta.\n";
	cout<<"\t\t\t*Recuerde que son 4 digitos*\n";
	cout<<"\t\t\t\t      ";cin>>in;	
	cout<<"\n"<<endl;
	
	if(in==psw){
		
		system("CLS");
		menu(res, ret, fondos, lim, id, nom, ape, erroneo);
		
	}else{
		
		cout<<erroneo;
		beep_erroneo();
	}	
		
getch();		
return 0;
	
}


	


