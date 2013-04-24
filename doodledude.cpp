#include "doodledude.h"

DoodleDude::DoodleDude() : QRect() {

	setRect(175, 125, 50, 50); 

	rightVelocity_ = 0; 
	leftVelocity_ = 0;  
	inContact_ = false; 

}

void DoodleDude::floatRight(int toTheRight) {
	
	rightVelocity_ +=  5; //(toTheRight - (x() + 25)) * 0.2;   

	if (rightVelocity_ > 0) 
		moveRight(); 
	else 
		rightVelocity_ = 0;
	
}

void DoodleDude::floatLeft(int toTheLeft) {

	leftVelocity_ += ((x() + 25) - toTheLeft) * 0.2;  

	if (leftVelocity_ > 0) 
		moveLeft(); 
	else 
		leftVelocity_ = 0;
	
}
 
void DoodleDude::moveRight() {

	int newPos;

	if (rightVelocity_ < 50)
		newPos = (right()-25) + rightVelocity_;
	else 
		newPos = (right()-25) + 50;
	
	if (leftVelocity_)
		newPos = newPos - (leftVelocity_ * 0.9); 
	
	if (newPos < 400) 
		moveTo(newPos, top());
	else 
		moveTo((newPos - 400), top());
		
	rightVelocity_ -= (rightVelocity_ * 0.11); 
	
	if (rightVelocity_ < 2)
		rightVelocity_ = 0;
}

void DoodleDude::moveLeft() {

	int newPos;

	if (leftVelocity_ < 50)
		newPos = (left()+25) - leftVelocity_;
	else 
		newPos = (left()+25) - 50;
	
	if (rightVelocity_)
		newPos = newPos - (rightVelocity_ * 0.9); 
	
	if (newPos > 0) 
		moveTo(newPos, top());
	else 
		moveTo((newPos + 400), top());
		
	leftVelocity_ -= (leftVelocity_ * 0.11); 
	
	if (leftVelocity_ < 2)
		leftVelocity_ = 0;


}

bool DoodleDude::hasVelocity() {

	if (rightVelocity_ || leftVelocity_)
		return true; 
	else 
		return false; 
		
} 

void DoodleDude::move_without_click() {

	//dummy(10);

	if (rightVelocity_ > leftVelocity_)
		moveRight(); 
	else
		moveLeft(); 
}

void DoodleDude::dummy(int bleh) {

	std::cout << "BLAHHH: " << bleh << std::endl; 
}

















