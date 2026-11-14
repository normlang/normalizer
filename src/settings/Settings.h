#pragma once
#include <QVariant>

class Settings {
public:
    void setMainWindowGeometry(const  QByteArray& geometry);
    QByteArray mainWindowGeometry() const;

protected:
    virtual void setValue(const QString& key, const QVariant& value) = 0;
    virtual QVariant value(const QString& key, const QVariant& defaultValue = {}) const = 0;

    virtual void setList(const QString& key, const QVariantList& list) = 0;
    virtual QVariantList list(const QString& key) const = 0;
};
