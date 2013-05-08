#ifndef DOODLE_DUDE_H
#define DOODLE_DUDE_H

#include <iostream>
#include <QRect>
#include <QPainter>

/** @DoodleDude this is the player of the game. It moves left and right. In gameplay, if not stopped by
* any other objects, it will begin to move downwards arithmetically faster. 
*/

class DoodleDude : public QRect 
{
	public: 
		DoodleDude();
		void dummy(int bleh = 0);  
		void floatRight(); 
		void floatLeft();  
		//void move_without_click(); 

	private:
		QImage image_;
		int rightVelocity_; 
		int leftVelocity_;  
		bool inContact_; 

};

#endif
