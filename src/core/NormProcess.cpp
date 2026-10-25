#include "NormProcess.h"
#include <QtTaskTree/QtTaskTree>
#include <QDebug>

constexpr auto Norm = "norm";

using namespace QtTaskTree;

NormProcess::NormProcess(QObject* parent) : QObject(parent) {
    m_taskTree = new QTaskTree(this);
}

void NormProcess::createNormspace(const QString& name, const QString& directory) {
    const auto onSetup = [&] (QProcess& process) {
        process.setProgram(Norm);
        process.setWorkingDirectory(directory);
        process.setArguments({ "normspace", "add", name });
    };

    const Group recipe {
        QProcessTask(onSetup)
    };

    m_taskTree->setRecipe(recipe);
    m_taskTree->start();
}
