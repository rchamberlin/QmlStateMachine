#include "state.h"

State::State(QState *parent) : QState(parent) {
}

void State::onEntry(QEvent *event) {
    Q_UNUSED(event);

    emit onEnteredWithObjectName(this->objectName());
}

void State::onExit(QEvent *event) {
    Q_UNUSED(event);
}
