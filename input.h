#ifndef INPUT_H
#define INPUT_H

#include <QObject>
#include <QQmlEngine>
#include <QVector>
#include <QString>
#include <QDebug>

class Input : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
public:

    enum class InputKeys{
        UpKey,
        DownKey,
        RightKey,
        LeftKey,
        IddleUp,
        IddleDown,
        IddleRight,
        IddleLeft
    };

    Q_ENUM(InputKeys)

    explicit Input(QObject *parent = nullptr);
    Q_INVOKABLE void addKey(const InputKeys&);
    Q_INVOKABLE void removeKey(const InputKeys&);
    Q_INVOKABLE InputKeys getDirection() const;
signals:
private:
    QVector<Input::InputKeys> m_inputList{InputKeys::IddleDown};
};

#endif // INPUT_H
