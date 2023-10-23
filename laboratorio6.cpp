#include <iostream>
#include <queue>
using namespace std;

void operaciones_lista(queue<float> nums, float *suma, float *prom, float *prod);
int calculo_factorial(int n);
int calculo_fibonacci(int n);
bool es_palindrome(string str);

int main()
{
	int eleccion;
	// ejercicio 1
	queue<float> numeros_lista;
	float numero, suma = 0, promedio = 0, producto = 1;
	int tamano;
	// ejercicio 2
	int factorial;
	// ejercicio 3
	int fibonacci;
	// ejercicio 4
	string palabra;
	
	do{
		cout << "---Re-Cursive---" << endl;
		cout << "[1] Lista de Numeros\n" << "[2] Factorial\n" << "[3] Fibonacci\n" << "[4] Palindrome\n" << "[5] Salir\n";
		do{
			cout << "Eleccion: ";
			cin >> eleccion;
		} while (eleccion < 1 || eleccion > 5);
		cout << endl;
		
		switch (eleccion)
		{
			case 1:	// lista de numeros
				do
				{
					cout << "Cuantos Numeros Ingresara: ";
					cin >> tamano;
					if (tamano < 1)
						cout << "Tamano NO Puede ser Menor a 1\n";
				} while (tamano < 1);
	
				while (numeros_lista.size() < tamano)
				{	
					cout << "Ingrese Numero: ";
					cin >> numero;
		
					numeros_lista.push(numero);
				}
	
				operaciones_lista(numeros_lista, &suma, &promedio, &producto);
	
				cout << "Suma Total: " << suma << "\nProducto Total: " << producto << "\nPromedio: " << promedio << endl;
				break;
				
			case 2: // factorial
				do{
					cout << "Ingrese Numero para Factorial: ";
					cin >> factorial;
					if (factorial)
						cout << "Imposible Calcular Factorial de Numeros Negativos\n";
				} while (factorial < 0);
	
				cout << calculo_factorial(factorial) << endl;
				break;
				
			case 3:	// fibonacci
				do{
					cout  << "Digito de Fibonacci: ";
					cin >> fibonacci;
					if (fibonacci < 1)
						cout << "Debe Ingresar Numeros Naturales\n";
				} while (fibonacci < 1);
	
				cout << "El " << fibonacci << " Digito de la Sucesion de Fibonacci es: " << calculo_fibonacci(fibonacci) << endl;
				break;
				
			case 4: // palindrome
				cout << "Ingrese Palabra: ";
				cin >> palabra;
	
				if (es_palindrome(palabra))
					cout << palabra << " es Palindrome\n";
				else
					cout << palabra << " no es Palindrome\n";
				break;
				
			case 5: // salir
				cout << "BUH-BYE!\n";
				break;
		}
		cout << endl;
	} while (eleccion != 5);
	
	return 0;
}

// entrega la suma, producto y promedio de una lista de numeros
void operaciones_lista(queue<float> nums, float *suma, float *prom, float *prod)
{
	int tamano = nums.size();
	while (!nums.empty())
	{
		float num = nums.front();
		nums.pop();
		
		*suma += num;
		*prod *= num;
	}
	
	*prom = *suma / tamano;
}

// calcula el factorial del numero ingresado
int calculo_factorial(int n)
{
	if (n <= 1)
	{
		cout << n << " = ";
		return 1;
	}
		
	cout << n << " * ";
	return n * calculo_factorial(n-1);
}

// retorna el digito de fibonacci en la posicion ingresada
int calculo_fibonacci(int n)
{
	if (n <= 1)
		return n;
		
	return calculo_fibonacci(n-1) + calculo_fibonacci(n-2);
}

// comprueba si una palabra ingresada es palindrome o no
bool es_palindrome(string str)
{
	if (str.length() <= 1)
		return true;
		
	if (str[0] == str[str.length()-1])
		return es_palindrome(str.substr(1, str.length()-2));
	
	return false;
}



