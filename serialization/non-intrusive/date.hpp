#ifndef DATE_HPP
#define DATE_HPP

typedef struct date {
  unsigned int m_day;
  unsigned int m_month;
  unsigned int m_year;

  date( int d,  int m,  int y) : m_day(d), m_month(m), m_year(y) {}
  date() : m_day(1), m_month(1), m_year(2000) {}

  friend std::ostream& operator << (std::ostream& out, date& d) {
    out << "day: "    << d.m_day
        << " month: " << d.m_month
        << " year: "  << d.m_year;
    return out;
  }

  /*
  // ПРОБЛЕМА!
  // Не всегда есть возможность модифицировать декларации классов.
  // Особенно, если это третьесторонние типы.

  template<class Archive>
  void serialize(Archive& archive, const unsigned int version) {
    archive & BOOST_SERIALIZATION_NVP(m_day);
    archive & BOOST_SERIALIZATION_NVP(m_month);
    archive & BOOST_SERIALIZATION_NVP(m_year);
  }
  */
} date;

#endif
