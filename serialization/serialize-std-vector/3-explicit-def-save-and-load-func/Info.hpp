#ifndef INFO_HPP
#define INFO_HPP

#include <string>
// #include <vector>
// #include <boost/serialization/access.hpp>
#include <boost/serialization/vector.hpp>
// В https://www.boost.org/doc/libs/1_70_0/boost/serialization/vector.hpp
// подключаются #include <vector> и #include <boost/serialization/access.hpp>.
// #include <boost/serialization/split_member.hpp>

class Info {
private:
    // Разрешить сериализации доступ к непубличным членам данных класса:
    friend class boost::serialization::access;


    // Когда есть асимметрия (например, при версионировании) функции сохранения
    // и загрузки определяются явно. Другими словами один и тот же метод
    // serialize не используется для сохранения и восстановления объектов:

    template<class Archive>
    void save(Archive & ar, const unsigned int version) const {
      ar & filenames;
    }

    template<class Archive>
    void load(Archive & ar, const unsigned int version) { ar & filenames; }

    BOOST_SERIALIZATION_SPLIT_MEMBER()
    // Макрос разбивает метод serialize на два отдельных метода: save и load.


    std::vector<std::string> filenames;

public:
    void AddFilename(const std::string& filename);
    void Print() const;
};

#endif
