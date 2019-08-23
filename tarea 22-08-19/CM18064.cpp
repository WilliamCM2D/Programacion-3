//William Alexander Chavez Marquez 
//CM18064

#include <iostream>

using namespace std;

typedef class ArBB *ABB;

//clase arbb contiene todo el arbol binario 
class ArBB{
	private:
		int nro;
		class ArBB *izq, *der;
	public:

//crea los nodos que seran ocupados 		
ABB crearNodo(int x){
	ABB nuevoNodo = new (class ArBB);
	nuevoNodo->nro=x;
	nuevoNodo->izq=NULL;
	nuevoNodo->der=NULL;
	
	return nuevoNodo;
}

//va insertando los nodos 
void insertar(ABB &arbol, int x){
	if(arbol==NULL){
		arbol=crearNodo(x);
	}
	else if(x<arbol->nro){
		insertar(arbol->izq,x);
	}
	else if(x>arbol->nro){
		insertar(arbol->der,x);
	}
}

//va poniendo los nodos a los lados 
int lado(ABB arbol, int &add){
	if(arbol!=NULL){
		lado(arbol->izq,add);
		add = add + arbol->nro;
		lado(arbol->der,add);	
	}
	return add;
}

//muestra la forma del arbol binario
void verArbol(ABB arbol, int n){
	if(arbol==NULL){
		return;
	}
	
	verArbol(arbol->der,n+1);
	for(int i=0; i<n; i++){
		cout<<" ";
	}
	
	cout<<arbol->nro<<endl;
	verArbol(arbol->izq,n+1);
}

//muesra el preorden del arbol
void preOrden(ABB arbol){
	if(arbol!=NULL){
		cout<<arbol->nro<<", ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

//muestra el inorden del arbol
void inOrden(ABB arbol){
	if(arbol != NULL){        
		inOrden(arbol->izq);
		cout << arbol->nro << ", ";
		inOrden(arbol->der);
	}
}

//muetra el postorden del arbol 
void postOrden(ABB arbol){
	if(arbol != NULL){
		cout << arbol->nro << ", ";
		postOrden(arbol->izq);
		postOrden(arbol->der);
	}
}
};

//orden que tendra el menu principal
void Menu(){
    cout<<"MENU"<<endl;
    cout<<"1- Insertar Nuevos nodos"<<endl;
    cout<<"2- Mostrar arbol binario"<<endl;
    cout<<"3- Mostrar Recorridos"<<endl;
    cout<<"4- Salir"<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"Que opcion desea: ";
}

//orden que tendra el submenu 
void SubMenu(){
	cout<<"SUBMENU"<<endl;
    cout<<"1- PreOrden"<<endl;
    cout<<"2- InOrden"<<endl;
    cout<<"3- PostOrden"<<endl;
    cout<<"4- Menu principal"<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"Que opcion desea: ";
}


//cuerpo del programa 
int main(){
	ArBB *arbol = new ArBB();
	int n=0;
	int x=0;
	int opc, opc2;
	int sc;
	
	do{
		cout<<"# Nodos atuales: "<<n<<endl;
		cout<<endl;
		Menu();
		cin>>opc;
		system("cls");
		switch(opc){
			case 1:
				cout<<"Ingrese el numero de Nodos que desea añiadir"<<"        "<<"Nodos actuales son: "<< n <<endl;
				cin>>n;
				
				for(int i=0; i<n; i++){
					cout<<"Ingrese valor del nodo actual"<<endl;
					cin>>x;
					arbol->insertar(arbol,x);
				}
				system("pause");
				break;
			case 2:
				cout<<"Mostrando Arbol: "<< "         " <<"Cantidad actual de nodos:  "<< n <<endl;
				arbol->verArbol(arbol,0);
				cout<<endl;
				system("pause");
				break;
			case 3:
				do{
					cout<<"Cantidad actual de nodos: "<< n <<endl;
					cout<<endl;
					SubMenu();
					cin>>opc2;
					switch(opc2){
						case 1:
							cout<<"Mostrando el arbol en PreOrden: "<<endl;
							arbol->preOrden(arbol);
							system("pause");
										
							cout<<"La suma de todas las claves es: "<<arbol->addin(arbol,sc)<<endl;
							cout<<endl;
				
							cout<<"La altura actual del arbol es: "<<n<<endl;
							cout<<endl;
							break;
						case 2:
							cout<<"Mostrando el arbol en PostOrden: "<<endl;
							arbol->postOrden(arbol);
							
										
							cout<<"La suma de todas las claves es: "<<arbol->addin(arbol,sc)<<endl;
							cout<<endl;
				
							cout<<"La altura actual del arbol es: "<<n<<endl;
							cout<<endl;
							system("pause");
							break;
						case 3:
							cout<<"Mostrando el arbol en InOrden: " <<endl;
							arbol->inOrden(arbol);
										
							cout<<"La suma de todas las claves es: "<<arbol->addin(arbol,sc)<<endl;
							cout<<endl;
				
							cout<<"La altura actual del arbol es: "<<n<<endl;
							cout<<endl;
							system("pause");
							break;
						case 4:
							break;
					}
					system("cls");
				}while(opc2!=4);
				break;
			case 4:
				cout<<"Cerrando..........."<<endl;
				cout<<endl;
				system("pause");
				break;
		}
		system("cls");
	}while(opc!=4);
	
	return 0;
}
