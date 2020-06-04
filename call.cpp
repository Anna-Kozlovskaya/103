#include "call.h"

ostream& operator<< (ostream& os, const call& call) {

    os << call.address << " " << call.time_to << " "
       << call.need_hosp << " " << call.time_back << " " << call.assigned_crew << " " << call.status;
    return os;
}
istream& operator>> (istream& is, call& call) {
    is >> call.address >> call.time_to >> call.need_hosp >>
          call.time_back >> call.assigned_crew >> call.status;
    return is;
}
