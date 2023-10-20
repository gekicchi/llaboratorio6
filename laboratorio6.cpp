#include <iostream>
#include <queue>
using namespace std;

void operaciones_lista(queue<float> nums, float *suma, float *prom, float *prod);
int calculo_factorial(int n);
int calculo_fibonacci(int n);
bool es_palindrome(string p);

int main()
{
	// ejercicio 1
	queue<float> numeros_lista;
	float numero, suma = 0, promedio = 0, producto = 1;
	int tamano;
	
	cout << "Cuantos Numeros Ingresara: ";
	cin >> tamano;
	
	while (tamano > 0)
	{
		cout << "Ingrese Numero: ";
		cin >> numero;
		
		numeros_lista.push(numero);
		tamano--;
	}
	
	operaciones_lista(numeros_lista, &suma, &promedio, &producto);
	
	cout << "Suma Total: " << suma << "\nProducto Total: " << producto << "\nPromedio: " << promedio << endl;
	
	// ejercicio 2
	int factorial;
	
	cout << "Ingrese Numero para Factorial: ";
	cin >> factorial;
	
	cout << calculo_factorial(factorial) << endl;
	
	// ejercicio 3
	int fibonacci;
	
	cout  << "Digito de Fibonacci: ";
	cin >> fibonacci;
	
	cout << calculo_fibonacci(fibonacci);
	
	return 0;
}

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

int calculo_fibonacci(int n)
{
	if (n <= 1)
		return n;
		
	return calculo_fibonacci(n-1) + calculo_fibonacci(n-2);
}

bool es_palindrome(string p)
{
	
	return false;
}



