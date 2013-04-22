#include <QApplication> 
#include <QObject>
#include "doodledivewindow.h"

int main(int argc, char* argv[]) {

	QApplication app(argc, argv); 
	
	DoodleDiveWindow window; 
	
	window.show(); 
	
	return app.exec(); 
}
