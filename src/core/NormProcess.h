#pragma once
#include <QObject>

namespace QtTaskTree {
    class QTaskTree;
}

class NormProcess : public QObject {
public:
    NormProcess(QObject* parent);

    void addNormspace(const QString& name, const QString& directory);

private:
    QtTaskTree::QTaskTree* m_taskTree = nullptr;
};
