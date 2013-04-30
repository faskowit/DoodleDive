#ifndef PLATFORM_H
#define PLATFORM_H

#include <iostream>
#include <QRect>
//#include "doodledivewindow.h"

class DoodleDiveWindow; 

class Platform: public QRect { 
	public:
		Platform(int, DoodleDiveWindow*); 
		Platform(int, int, DoodleDiveWindow*); 
		void move_up(int); 
		int get_height() const;  
		virtual void contact_made(); 
	private:
		int xPos_; 
		int length_; 
		bool contact_; 
}; 

#endif
