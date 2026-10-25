#pragma once
#include "StandardDialog.h"

class BrowseLayout;
class QLineEdit;
class QComboBox;

class NewNormspace : public StandardDialog {
    Q_OBJECT
public:
    NewNormspace(const QString& workDir);

    QString name() const;
    QString directory() const;

public slots:
    void accept() override;

private slots:
    void setOkButtonState();

private:
    QLineEdit* m_nameLineEdit = nullptr;
    BrowseLayout* m_browseLayout = nullptr;
};
