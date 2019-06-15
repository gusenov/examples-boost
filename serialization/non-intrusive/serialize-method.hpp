// non-intrusive версия serialize дефинированная вне скопа класса.
// Можно дефинировать serialize и в глобальном скопе; однако хорошей практикой
// считается дефинировать метод в релевантном пространстве имён:

namespace boost {
  namespace serialization {
    template<class Archive>
    void serialize(Archive& archive, date& d, const unsigned int version) {
        archive & BOOST_SERIALIZATION_NVP(d.m_day);
        archive & BOOST_SERIALIZATION_NVP(d.m_month);
        archive & BOOST_SERIALIZATION_NVP(d.m_year);
    }
  }  // namespace serialization
}  // namespace boost
