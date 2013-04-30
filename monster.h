#ifndef MONSTER_H
#define MONSTER_H

#include <QRect>

class DoodleDiveWindow; 

class Monster : public Platform {

	public: 
		Monster(DoodleDiveWindow* parent) : Platform (30,30, parent) {
		
			monsterImage(); 	
		
		}
	private:
		void monsterImage() {
		
		//set monster image 
		
		}
	
}; 

#endif
