#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <QObject>
#include <QStateMachine>
#include "state.h"

class AppController : public QObject {
    Q_OBJECT

    Q_PROPERTY(QObject *stateMachine READ stateMachine CONSTANT)

    Q_PROPERTY(QObject *firstState READ firstState CONSTANT)
    Q_PROPERTY(QObject *secondState READ secondState CONSTANT)
    Q_PROPERTY(QObject *thirdState READ thirdState CONSTANT)

    Q_PROPERTY(bool pop READ pop WRITE setPop)

public:
    explicit AppController(QObject *parent = 0);

    QStateMachine *stateMachine() const { return m_stateMachine; }

    State *firstState() const { return m_firstState; }
    State *secondState() const { return m_secondState; }
    State *thirdState() const { return m_thirdState; }

    bool pop() const { return m_pop; }
    void setPop(bool pop) {
        if (pop != m_pop) {
            m_pop = pop;
        }
    }

    Q_INVOKABLE void navPrevious();
    Q_INVOKABLE void navNext();

private:
    QStateMachine *m_stateMachine;

    State *m_firstState;
    State *m_secondState;
    State *m_thirdState;

    bool m_pop;

    void initStateMachine();

signals:
    void stateChanged(QString objectName);
    void navigateForward(void);
    void navigateBackward(void);

public slots:

};

#endif // APPCONTROLLER_H
