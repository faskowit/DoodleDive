#ifndef DOODLE_DUDE_H
#define DOODLE_DUDE_H

#include <iostream>
#include <QRect>
#include <QPainter>

class DoodleDude : public QRect 
{
	public:
		DoodleDude();
		void dummy(int bleh = 0);  
		void floatRight(int); 
		void floatLeft(int); 
		void moveRight(); 
		void moveLeft(); 
		bool hasVelocity(); 
		void move_without_click();  

		//get_Image(); 

	private:
		QImage image_;
		int rightVelocity_; 
		int leftVelocity_;  
		bool inContact_; 

};

#endif
