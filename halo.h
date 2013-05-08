#ifndef HALO_H
#define HALO_H

class DoodleDiveWindow; 

/** @Halo derrives from platform.  Basically a different sizes plaform that is harder to see,
* it does not stop or slow the player down when moved through.
*/ 
class Halo : public Platform {

	public:
		Halo() : Platform (60,2) {
		}
	private:
	
}; 
#endif
