#ifndef BADPLATFORM_H
#define BADPLATFORM_H

#include "platform.h"
#include <QPoint> 

/** @BadPlatform a platform that expands to the right. It inflicts damage when in contact with theDude
* In gameplay, it expands even when theDude is resting on a platform
*/
class BadPlatform : public Platform {
	public:
		BadPlatform(int length) : Platform (length) {
		 
			moveRight_ = true; 
		
			int moveDir = rand() % 1; 
			
			if (moveDir)
				moveRight_ = false; 
		
			//static_cast<QRect*>(this)->image
		};
	void move_horizontal () {
			
			int tempwidth = width() ; 
			
			tempwidth++; 
		
			if (moveRight_) {
				this->setWidth(tempwidth); 
			}	
	};
	private:
		bool moveRight_; 
		



}; 
#endif 
