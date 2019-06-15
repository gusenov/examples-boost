#ifndef INFO_HPP
#define INFO_HPP

#include <vector>
#include <string>

class Info {
private:
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
