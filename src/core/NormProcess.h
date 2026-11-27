#pragma once
#include <QObject>

namespace QtTaskTree {
    class QTaskTree;
}

class NormProcess : public QObject {
public:
    NormProcess(QObject* parent);

    void addNormspace(const QString& name, const QString& directory);
    void addWorkspace(const QString& name);

private:
    QtTaskTree::QTaskTree* m_taskTree = nullptr;
};
