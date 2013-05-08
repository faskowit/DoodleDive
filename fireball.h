#ifndef FIREBALL_H
#define FIREBALL_H 

#include <QRect>
#include "doodledude.h"
#include "monster.h"

/** @Fireball projectile from the DoodleDude's location. Travels down the screen. Has the ability 
* to track the monster in its vicinity to hit it. 
*/

class Fireball : public QRect {

	public:
		Fireball(DoodleDude* tempDude) : QRect() {
		
			int dudeX, dudeY; 
			
			dudeX = (tempDude->x()) + 15; 
			dudeY = tempDude->y(); 
		
			this->setRect(dudeX, (dudeY + 35), 15, 15); 
		}; 
		void fired_shot() {
		
			int currentY = top(); 
			currentY += 5; 
			this->moveTo(this->x(), currentY); 
		}; 
		void set_tracking_loc(Monster* temp) {
		
			this->trackingX_ = temp->x(); 
		};
		void tracking() {
		
			int currentX = this->x(); 
		
			if (trackingX_ - currentX > 5) {
				currentX += 3; 
				this->moveTo(currentX, this->y()); 
			}
			else if (trackingX_ - currentX < -5) {
				currentX += -3; 
				this->moveTo(currentX, this->y());
			}
			else {
				int currentY = top();
				currentY += 5; 
				this->moveTo(this->x(), currentY);
			}
		};
	private:
		int trackingX_; 
}; 
#endif
