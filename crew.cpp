#include "crew.h"

ostream& operator<< (ostream& os, const crew& crew) {
    os << crew.doctor << " " << crew.paramedic << " " <<
          crew.driver << " " << crew.duty_status << " " << crew.call_status << " " << crew.duty_bool << endl;
    return os;
}

istream& operator>> (istream& is, crew& crew) {
    is >> crew.doctor >> crew.paramedic >> crew.driver >> crew.duty_status >> crew.call_status >> crew.duty_bool;
    return is;
}
