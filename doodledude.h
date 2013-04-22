#ifndef DOODLE_DUDE_H
#define DOODLE_DUDE_H

#include <QRect>

class DoodleDude : public QRect 
{
	public:
		DoodleDude(); 
		floatRight(); 
		floatLeft(); 

	private:
		QImage image;
		int rightMomentum; 
		int leftMomentum; 
		//int upMomentum; 
		bool inContact; 

};

#endif
