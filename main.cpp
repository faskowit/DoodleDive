#include <QApplication> 




int main(int argc, char* argv[]) {

	QApplication app(argc, argv); 
	
	DoodleDive window; 
	
	window.show(); 
	
	return app.exec(); 
}
