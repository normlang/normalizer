#include "NewProject.h"
#include "ui/widget/BrowseLayout.h"
#include <QLineEdit>
#include <QIntValidator>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QComboBox>
#include <QMessageBox>
#include <QDir>

NewProject::NewProject(const QString& workDir) {
    setWindowTitle(tr("New Project"));

    m_nameLineEdit = new QLineEdit;
    connect(m_nameLineEdit, &QLineEdit::textChanged, this, &NewProject::setOkButtonState);

    m_targetComboBox = new QComboBox;
    m_targetComboBox->addItem(tr("Application"));
    m_targetComboBox->addItem(tr("Library"));

    m_directoryBrowseLayout = new BrowseLayout(workDir);
    connect(m_directoryBrowseLayout->lineEdit(), &QLineEdit::textChanged, this, &NewProject::setOkButtonState);

    auto formLayout = new QFormLayout;
    formLayout->addRow(tr("Name:"), m_nameLineEdit);
    formLayout->addRow(tr("Target:"), m_targetComboBox);
    formLayout->addRow(tr("Directory:"), m_directoryBrowseLayout);
    formLayout->itemAt(formLayout->indexOf(m_targetComboBox))->setAlignment(Qt::AlignLeft);

    setContentLayout(formLayout);

    resizeToWidth(500);
    m_nameLineEdit->setFocus();
    setOkButtonState();
}

QString NewProject::name() const {
    return m_nameLineEdit->text();
}

Project::Target NewProject::target() const {
    return static_cast<Project::Target>(m_targetComboBox->currentIndex());
}

QString NewProject::directory() const {
    return m_directoryBrowseLayout->lineEdit()->text();
}

void NewProject::accept() {
    if (QDir().exists(directory() + "/" + name() + ".norm")) {
        QMessageBox::critical(this, {}, tr("Project already exists!"));
    } else {
        StandardDialog::accept();
    }
}

void NewProject::setOkButtonState() {
    bool isAllFieldsFilled = !(m_nameLineEdit->text().isEmpty() || m_directoryBrowseLayout->lineEdit()->text().isEmpty());
    buttonBox()->button(QDialogButtonBox::Ok)->setEnabled(isAllFieldsFilled);
}
