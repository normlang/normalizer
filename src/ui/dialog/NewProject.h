#pragma once
#include "StandardDialog.h"
#include "project/Project.h"
#include <QComboBox>

class BrowseLayout;
class QLineEdit;

class NewProject : public StandardDialog {
    Q_OBJECT
public:
    NewProject(const QString& workDir);

    QString name() const;
    Project::Target target() const;
    QString workspace() const;

public slots:
    void accept() override;

private slots:
    void setOkButtonState();

private:
    QLineEdit* m_nameLineEdit = nullptr;
    QComboBox* m_targetComboBox = nullptr;
    BrowseLayout* m_workspaceBrowseLayout = nullptr;
};
