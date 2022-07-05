#include "infect.h"
#include <QtWidgets/QApplication>
#include <QSoundEffect>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSoundEffect effect;
    effect.setSource(QUrl::fromLocalFile(QApplication::applicationDirPath() + "/sound.wav"));
    effect.setLoopCount(QSoundEffect::Infinite);
    effect.setVolume(1.0f);
    effect.play();

    infect w(1,1);
    w.show();
    return a.exec();
}
