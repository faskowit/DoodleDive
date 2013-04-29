#ifndef BADPLATFORM_H
#define BADPLATFORM_H

#include "platform.h"

class BadPlatform : public Platform {
	public:
		BadPlatform(int length) : Platform (length) {
		
			moveRight_ = true; 
		
			int moveDir = rand() % 1; 
			
			if (moveDir)
				moveRight_ = false; 
		
			//static_cast<QRect*>(this)->image
		}
	private:
		bool moveRight_; 
		void move_horizontal () {
		
			int leftPos = left(); 
		
			if (moveRight_)
				moveTo(leftPos + 52, top()); 	
			else
				moveTo(leftPos - 2, top());
		
		};



}; 
#endif 
