#include "doodledude.h"

DoodleDude::DoodleDude() : QRect() {

	setRect(175, 125, 50, 50); 

	rightVelocity_ = 0; 
	leftVelocity_ = 0;  
	inContact_ = false; 

}

void DoodleDude::floatRight () {

	int rightPoint = ((left())); 

	if ((rightPoint + 65)  < 400)
		this->moveTo((rightPoint + 4), top());	

}

void DoodleDude::floatLeft () {

	int leftPoint = left(); 
	
	if (leftPoint - 15 > 0)
		this->moveTo((leftPoint - 4), top()); 
		
}

/*void DoodleDude::floatRight(int toTheRight) {

	rightVelocity_ += rightVelocity_ + 5; 
	
	moveRight(); 
} */

/*void DoodleDude::moveRight() {

	int newPos, center;
	
	center = (left()) + 25;  
	
	newPos = (center + 3);
	
	if (newPos < 400) 
		moveTo(newPos, top());
	else 
		moveTo((newPos - 400), top());
		
	rightVelocity_ -= 1;
	
} */

/*void DoodleDude::floatRight(int toTheRight) {

	int leftPoint = left(); 

	rightVelocity_ += ((toTheRight - (leftPoint)) + 25) * 0.1 ;    

	if (rightVelocity_ > 0) 
		moveRight(); 
	else 
		rightVelocity_ = 0;  
	
}*/

/*void DoodleDude::floatLeft(int toTheLeft) {

	leftVelocity_ += (((left()) - toTheLeft) + 25) * 0.1 ; 

	
	
} */
 
/*void DoodleDude::moveRight() {

	int newPos; 
	
	if (rightVelocity_ < 50)
		newPos = ((left()) + rightVelocity_);
	else 
		newPos = (left()) + 50;
	
	if (newPos < 400) 
		moveTo(newPos, top());
	else 
		moveTo((newPos - 400), top());
		
	rightVelocity_ -= (rightVelocity_ * 0.3); 
	
	if (rightVelocity_ < 2)
		rightVelocity_ = 0;  
	
} */

/*void DoodleDude::moveLeft() {

	int newPos;

	if (leftVelocity_ < 50)
		newPos = ((left()) - leftVelocity_);
	else 
		newPos = (left()) - 50;
	
	if (newPos > 0) 
		moveTo(newPos, top());
	else 
		moveTo((newPos + 400), top());
		
	leftVelocity_ -= (leftVelocity_ * 0.11); 
	
	if (leftVelocity_ < 2)
		leftVelocity_ = 0;
	

} */

/*bool DoodleDude::hasVelocity() {

	if (leftVelocity_)
		return true; 
	else 
		return false; 
		
} */

/*void DoodleDude::move_without_click() {

}
*/

void DoodleDude::dummy(int bleh) {

	std::cout << "BLAHHH: " << bleh << std::endl; 
}

















