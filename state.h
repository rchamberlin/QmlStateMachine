#ifndef STATE_H
#define STATE_H

#include <QState>

class State : public QState {
    Q_OBJECT

public:
    explicit State(QState *parent = 0);

protected:
    void onEntry(QEvent *event);
    void onExit(QEvent *event);

signals:
    void onEnteredWithObjectName(QString objectName);

};

#endif // STATE_H
