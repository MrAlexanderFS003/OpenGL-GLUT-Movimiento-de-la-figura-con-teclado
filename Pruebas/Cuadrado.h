class Cuadrado {
	float posX = 0.0f, posY = 0.0f; //Atributos privados
public:
	Cuadrado(){} // Constructor predeterminado
	void Dibuja();
	void Actualiza();

	//Setters y Getters 
	void setPosX(float valor) { posX = valor; }
	void setPosY(float valor) { posY = valor; }

	float getPosY() { return posY; }
	float getPosX() { return posX; }
};
