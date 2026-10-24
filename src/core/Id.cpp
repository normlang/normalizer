#include "Id.h"

Id::Id(quint64 id) : m_id(id) {

}

quint64 Id::value() const {
    return m_id;
}

QString Id::toString() const {
    return QString::number(m_id);
}

bool Id::isValid() const {
    return m_id > 0;
}
