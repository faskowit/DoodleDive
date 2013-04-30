#include "platform.h"

Platform::Platform(int length, DoodleDiveWindow* parent) : QRect()  {

	this->length_ = length; 
	
	int x = (rand() % 300) + 25;
	
	this->xPos_ = x;  
	
	this->setRect(this->xPos_, 600, length, 10); 
	
	this->contact_ = false; 

}

Platform::Platform(int length, int height, DoodleDiveWindow* parent) : QRect()  {

	this->length_ = length; 
	
	int x = (rand() % 350) + 25;
	
	this->xPos_ = x;  
	
	this->setRect(this->xPos_, 600, length, height); 
	
	this->contact_ = false;  

}

int Platform::get_height() const {

	return this->y(); 

}

void Platform::move_up(int jump_up) {

	int currentY = get_height();  

	int newY = (currentY - jump_up) ;

	this->moveTo(this->xPos_,newY);
	
}

void Platform::contact_made() {

	this->contact_ = true; 
	
	//new rect???
}
	
	









