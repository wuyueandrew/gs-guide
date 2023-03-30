#include <iostream>

#include "grape/serialization/in_archive.h"
#include "grape/serialization/out_archive.h"


namespace gs {

template <typename VID_T>
struct OneidMsg {
  using vid_t = VID_T;

  int type_val;
  int priority;
  std::vector<vid_t> connect_vertices;
  std::vector<double> connect_vertices_confi;

  OneidMsg() : type_val(-1), priority(-1) {}

  ~OneidMsg() = default;

  // for message manager to serialize and diserialize
  friend grape::InArchive& operator<<(grape::InArchive& in_archive,
                                      const OneidMsg& u) {
    in_archive << u.type_val;
    in_archive << u.priority;
    in_archive << u.connect_vertices;
    in_archive << u.connect_vertices_confi;
    return in_archive;
  }

  friend grape::OutArchive& operator>>(grape::OutArchive& out_archive,
                                       OneidMsg& val) {
    out_archive >> val.type_val;
    out_archive >> val.priority;
    out_archive >> val.connect_vertices;
    out_archive >> val.connect_vertices_confi;
    return out_archive;
  }
};


}// namespace gs

int main() {
  grape::InArchive in;

  // init size
  std::cout<< "size: " << in.GetSize() << std::endl;

  // str msg
  std::string str_msg = "2|1|1|100000000:100000001:100000002:100000003:100000004|1.0000:1.0000:1.0000:1.0000:1.0000";
  std::cout<< "size: " << in.GetSize() << std::endl;

  // clear
  in.Clear();

  // struct msg
  gs::OneidMsg<int64_t> msg;
  msg.type_val = 1;
  msg.priority = 2;
  std::vector<int64_t> connect_vertices{1,2,3,4,5};
  std::vector<double> connect_vertices_confi{1.0,1.0,1.0,1.0,1.0};
  msg.connect_vertices = connect_vertices;
  msg.connect_vertices_confi = connect_vertices_confi;
  in << msg;
  std::cout<< "size: " << in.GetSize() << std::endl;
  std::cout<< "=====" << std::endl;
}
