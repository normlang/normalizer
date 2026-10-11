#pragma once
#include <QHBoxLayout>

class QLineEdit;

class BrowseLayout : public QHBoxLayout {
public:
    BrowseLayout(const QString& dir = {});
    QLineEdit* lineEdit() const;

private slots:
    void onClicked();

private:
    QLineEdit* m_lineEdit = nullptr;
};
