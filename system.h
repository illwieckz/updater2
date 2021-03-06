#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <string>

#include <QSettings>
#include <QString>

namespace Sys {
QString archiveName();
QString defaultInstallPath();
bool validateInstallPath(const QString& installPath); // Checks installing as root in homepath on Linux
bool install();
bool installUpdater(const QString& installPath); // Copies current application to <install path>/updater[.exe|.app]
bool updateUpdater(const QString& updaterArchive);
QString updaterArchiveName();
std::string getCertStore();
QSettings* makePersistentSettings(QObject* parent);
QString getGameCommand(const QString& installPath); // Substitution for %command%
bool startGame(const QString& commandLine);

inline QString QuoteQProcessCommandArgument(QString arg)
{
    arg.replace('"', "\"\"\"");
    return '"' + arg + '"';
}

}

#endif // SYSTEM_H_
