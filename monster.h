#ifndef MONSTER_H
#define MONSTER_H

#include <QRect>
#include "doodledude.h"

/** @Monster this object moves upwards. The player wants to avoid the object because
* in doodledivegameplay if you are in contact with a monster, it will put a lot
* of damage on you. This also has a function (monster attack)to move towards the DoodleDude 
* location if you pass the DoodleDude pointer in. Will revert to old position if not in contact with 
* platform anymore. 
*/ 

class Monster : public Platform {

	public: 
		Monster() : Platform (30,30) {
		
			currentX = this->x();
		};
		void monster_attack(DoodleDude* temp) {
		
			int targetX = temp->x(); 
		
			if ((targetX - currentX) > 5) {
			  
				currentX += 2; 
				moveTo(currentX, this->y()); 
			}
			if ((targetX - currentX) < -5) {
			
				currentX += -2; 
				moveTo(currentX, this->y());
			}
			else {
				moveTo(currentX, this->y()); 
			}
		};
	private:
		int currentX; 
	
}; 

#endif
