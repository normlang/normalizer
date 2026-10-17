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
    quint8 capacity() const;
    QString directory() const;

public slots:
    void accept() override;

private slots:
    void setOkButtonState();

private:
    QLineEdit* m_nameLineEdit = nullptr;
    QComboBox* m_capacity = nullptr;
    BrowseLayout* m_browseLayout = nullptr;
};
