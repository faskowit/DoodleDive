#ifndef PLATFORM_H
#define PLATFORM_H

#include <QRect>

class Platform: public QRect { 
	public:
		Platform(int); 
		Platform(int, int); 
		void move_up(int); 
		int get_height() const;  
		virtual void contact_made(); 
	private:
		int xPos_; 
		int length_; 
		bool contact_; 
}; 

#endif
