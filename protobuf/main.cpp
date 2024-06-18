
#include <iostream>
#include <fstream>
#include "person.pb.h"

int main () {
    Serialize::Address addr;
    addr.set_building(15);
    addr.set_street("Lva ");
    *addr.mutable_street() += "Tolstogo";
    std::cout << addr.street() << " " << addr.building() << std::endl;

    Serialize::Person p;
    p.add_phone_number("1234");
    p.add_phone_number("4321");

    for (const std::string& phone : p.phone_number()) {
        std::cout << phone << std::endl;
    }
    *p.mutable_address() = addr;

    std::ofstream out("person.bin", std::ios_base::binary);
    p.SerializePartialToOstream(&out);
    out.close();

    std::ifstream in("person.bin", std::ios_base::binary);
    Serialize::Person new_person;

    if (new_person.ParseFromIstream(&in)) {
        std::cout << new_person.name() << " "
                  << new_person.phone_number_size() << std::endl;
        if (new_person.has_address()) {
            std::cout << new_person.address().street() << std::endl;
        } else {
            std::cout << "No address" << std::endl;
        }
    } else {
        std::cout << "Faild to parse message" << std::endl;
    }

    return 0;
}
