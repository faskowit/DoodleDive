#ifndef PLATFORM_H
#define PLATFORM_H

#include <iostream>
#include <QRect>

/** @Platfrom Baseplatform that others will derrive from. Two different constructors that will make 
* platforms of different sizes. It also hase a general move_up function to move all the platform
* objects up in the frame.
*/
class Platform: public QRect { 
	public:
		Platform(int); 
		Platform(int, int); 
		void move_up(int); 
		int get_height() const;   
	private:
		int xPos_; 
		int length_;  
}; 

#endif
