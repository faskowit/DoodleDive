#ifndef FIREBALL_H
#define FIREBALL_H 

#include <QRect>
#include "doodledude.h"

class Fireball : public QRect {

	public:
		Fireball(DoodleDude* tempDude) : QRect() {
		
			int dudeX, dudeY; 
			
			dudeX = (tempDude->x()) + 15; 
			dudeY = tempDude->y(); 
		
			this->setRect(dudeX, dudeY, 15, 15);
			
			this->health_ = 3; 
		}; 
		void fired_shot() {
		
			int currentY = top(); 
			
			currentY += 5; 
			
			this->moveTo(this->x(), currentY); 
		}; 
	private:
		int bullet_hit() {
		
			health_--; 
			
			return health_; 
		}
		int health_; 
}; 
#endif
