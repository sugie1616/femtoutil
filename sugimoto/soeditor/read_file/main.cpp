#include "file_read.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	FileRead *sample = new FileRead;

	sample->show();

	return app.exec();
}
