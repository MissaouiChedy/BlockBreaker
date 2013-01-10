#include <QApplication>
#include <QWidget>
#include <QIcon>
//#include <SFML/Audio.hpp>
#include "mainWindow.h"

int main(int argc, char *argv[]){
    
	QApplication app(argc, argv);
    	MainWindow *window = new MainWindow();
 // Load a sound buffer from a wav file
  //  sf::SoundBuffer Buffer;
    //if (!Buffer.LoadFromFile("/home/chaasof/laboratoireDev/labEsprit/Gp3A16/src/Acrostics.wav"));
      //  return EXIT_FAILURE;
    // Create a sound instance and play it
   // sf::Sound Sound(Buffer);
   // Sound.Play();

//	QSound::play("/home/chaasof/laboratoireDev/labEsprit/Gp3A16/src/Acrostics.wav");
	//acrostics.play();
    	window->show();

    	return app.exec();
}
