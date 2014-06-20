#include "lights.h"
#include <string>

Lights::Lights(){
	Red = false;
	Yellow = false;
	Green = false;
}

Lights::Lights(const Lights& L){
	this->Red = L.Red;
	this->Yellow = L.Yellow;
	this->Green = L.Green;
}

Lights::~Lights(){}

bool Lights::getRed(){
	return Red;
}
bool Lights::getYellow(){
	return Yellow;
}
bool Lights::getGreen(){
	return Green;
}

void Lights::setRed(bool status){
	Red = status;
}
void Lights::setYellow(bool status){
	Yellow = status;
}
void Lights::setGreen(bool status){
	Green = status;
}

void Lights::SetOn(std::string color) {
    if (color == "Red") {
        Red = true;
        Yellow = false;
        Green = false;
    }
    else if (color == "Yellow") {
        Red = false;
        Yellow = true;
        Green = false;
    }
    else if (color == "Green") {
        Red = false;
        Yellow = false;
        Green = true;
    }
    else {
        Red = false;
        Yellow = false;
        Green = false;
    }
}