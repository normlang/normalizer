#include "NewNormspace.h"
#include "ui/widget/BrowseLayout.h"
#include <QLineEdit>
#include <QComboBox>
#include <QFormLayout>
#include <QMessageBox>
#include <QPushButton>
#include <QDir>

NewNormspace::NewNormspace(const QString& workDir) {
    setWindowTitle(tr("New Normspace"));

    m_nameLineEdit = new QLineEdit;
    connect(m_nameLineEdit, &QLineEdit::textChanged, this, &NewNormspace::setOkButtonState);

    m_capacity = new QComboBox;
    m_capacity->addItem("256", 1);
    m_capacity->addItem("65536", 2);

    m_browseLayout = new BrowseLayout(workDir);
    connect(m_browseLayout->lineEdit(), &QLineEdit::textChanged, this, &NewNormspace::setOkButtonState);

    auto formLayout = new QFormLayout;
    formLayout->addRow(tr("Name:"), m_nameLineEdit);
    formLayout->addRow(tr("Capacity:"), m_capacity);
    formLayout->addRow(tr("Directory:"), m_browseLayout);
    formLayout->itemAt(formLayout->indexOf(m_capacity))->setAlignment(Qt::AlignLeft);

    setContentLayout(formLayout);

    resizeToWidth(500);
    m_nameLineEdit->setFocus();
    setOkButtonState();
}

QString NewNormspace::name() const {
    return m_nameLineEdit->text();
}

quint8 NewNormspace::capacity() const {
    return m_capacity->currentData().toUInt();
}

QString NewNormspace::directory() const {
    return m_browseLayout->lineEdit()->text();
}

void NewNormspace::accept() {
    if (QDir().exists(directory() + "/" + name())) {
        QMessageBox::critical(this, {}, tr("Directory already exists!"));
    } else {
        StandardDialog::accept();
    }
}

void NewNormspace::setOkButtonState() {
    bool isAllFieldsFilled = !(m_nameLineEdit->text().isEmpty() || m_browseLayout->lineEdit()->text().isEmpty());
    buttonBox()->button(QDialogButtonBox::Ok)->setEnabled(isAllFieldsFilled);
}
