#include <QApplication> 
#include <QObject>

int main(int argc, char* argv[]) {

	QApplication app(argc, argv); 
	
	DoodleDiveWindow window; 
	
	window.show(); 
	
	return app.exec(); 
}
