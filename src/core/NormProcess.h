#pragma once
#include <QObject>

namespace QtTaskTree {
    class QTaskTree;
}

class NormProcess : public QObject {
public:
    NormProcess(QObject* parent);

    void createNormspace(const QString& name, const QString& directory, quint8 capacity);

private:
    QtTaskTree::QTaskTree* taskTree = nullptr;
};
