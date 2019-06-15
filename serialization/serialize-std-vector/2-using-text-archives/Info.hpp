#ifndef INFO_HPP
#define INFO_HPP

#include <string>
// #include <vector>
// #include <boost/serialization/access.hpp>
#include <boost/serialization/vector.hpp>
// В https://www.boost.org/doc/libs/1_70_0/boost/serialization/vector.hpp
// подключаются #include <vector> и #include <boost/serialization/access.hpp>.

class Info {
private:
    // Разрешить сериализации доступ к непубличным членам данных класса:
    friend class boost::serialization::access;

    // Сериализовать элемент std::vector данного класса Info:
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version) {
      ar & filenames;
    }

    std::vector<std::string> filenames;

public:
    void AddFilename(const std::string& filename);
    void Print() const;
};

#endif
