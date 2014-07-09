#include "appcontroller.h"

AppController::AppController(QObject *parent) : QObject(parent) {

    setPop(false);
    this->initStateMachine();

}

void AppController::initStateMachine() {

    m_stateMachine    = new QStateMachine(this);
    m_firstState      = new State(m_stateMachine);
    m_secondState     = new State(m_stateMachine);
    m_thirdState      = new State(m_stateMachine);

    // SET STATE OBJECT NAMES TO BE USED BY QML
    m_firstState->setObjectName("firstState");
    m_secondState->setObjectName("secondState");
    m_thirdState->setObjectName("thirdState");

    // EMIT stateChanged WHEN ENTERING STATE
    QObject::connect(m_firstState, SIGNAL(onEnteredWithObjectName(QString)), this, SIGNAL(stateChanged(QString)));
    QObject::connect(m_secondState, SIGNAL(onEnteredWithObjectName(QString)), this, SIGNAL(stateChanged(QString)));
    QObject::connect(m_thirdState, SIGNAL(onEnteredWithObjectName(QString)), this, SIGNAL(stateChanged(QString)));

    m_firstState->addTransition(this, SIGNAL(navigateForward()), m_secondState);
    m_secondState->addTransition(this, SIGNAL(navigateForward()), m_thirdState);

    m_thirdState->addTransition(this, SIGNAL(navigateBackward()), m_secondState);
    m_secondState->addTransition(this, SIGNAL(navigateBackward()), m_firstState);

    m_stateMachine->setInitialState(m_firstState);

    m_stateMachine->start();

}

void AppController::navPrevious() {
    setPop(true);
    emit navigateBackward();
    setPop(false);
}

void AppController::navNext() {
    emit navigateForward();
}
