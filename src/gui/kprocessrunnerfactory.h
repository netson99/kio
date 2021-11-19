#ifndef KPROCESSRUNNERFACTORY_H
#define KPROCESSRUNNERFACTORY_H

#include <QtCore/QObject>

class KProcessRunner;

/**
 * @todo write docs
 */
class KProcessRunnerFactory : public QObject
{
public:
    virtual KProcessRunner *create() = 0;
};

Q_DECLARE_INTERFACE(KProcessRunnerFactory, "KProcessRunnerFactory")

#endif // KPROCESSRUNNERFACTORY_H
