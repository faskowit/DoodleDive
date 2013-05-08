#ifndef MONSTER_H
#define MONSTER_H

#include <QRect>

class Monster : public Platform {

	public: 
		Monster() : Platform (30,30) {
		
			monsterImage(); 	
		
		}
	private:
		void monsterImage() {
		
		}
	
}; 

#endif
