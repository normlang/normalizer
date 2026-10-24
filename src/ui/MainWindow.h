#pragma once
#include <QMainWindow>

class FileSettings;
class NormProcess;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void openNewNormspaceDialog();
    void openNewProjectDialog();
    void showAbout();

private:
    void readSettings();
    void writeSettings();

    void createActions();

    FileSettings* m_fileSettings = nullptr;
    NormProcess* m_normProcess = nullptr;
};
