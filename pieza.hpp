#ifndef __HPP__PIEZA__
#define __HPP__PIEZA__
#include <iostream>
#include <string>


using namespace std;
namespace juego{
class Pieza{
public:
	Pieza();
	Pieza(const Pieza &p);
	Pieza(const &double n1, const &double n2);
	~Pieza();
	void mostrar() const;
	void rotar();
	void enfrentarIzq (const Pieza &p);
	void enfrentarDer(const Pieza &p);
	int valorIzq();
	int valorDer();

private:
	int num1, num2;

};
}
#endif