#pragma once
#include <QString>

template <typename T>
class Id {
public:
    Id(T id = 0) : m_id(id) {}

    T value() const { return m_id; }
    QString toString() const { return QString::number(m_id); }

    bool isValid() const { return m_id > 0; }

    bool operator==(const Id& other) const {
        return m_id == other.m_id;
    }

    bool operator!=(const Id& other) const {
        return !(*this == other);
    }

private:
    T m_id = 0;
};

using Id8 = Id<quint8>;
using Id16 = Id<quint16>;
using Id32 = Id<quint32>;
using Id64 = Id<quint64>;

template <typename T>
using Ids = QVector<T>;

using Ids8 = Ids<quint8>;
using Ids16 = Ids<quint16>;
using Ids32 = Ids<quint32>;
using Ids64 = Ids<quint64>;
