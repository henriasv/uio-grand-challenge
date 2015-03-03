#include <iostream>
#include <string>

void sayHello(std::string name);

using namespace std;

int main()
{
	sayHello("Thomas");

	for (int i = 0; i<10; i++)
	{
		std::cout << i << std::endl;
	}

	int counter = 0;
	while (counter<10)
	{
		std::cout << counter << std::endl;
		counter ++;
	}

}


void sayHello(std::string name)
{
	std::cout << "Hello " << name << std::endl;
}