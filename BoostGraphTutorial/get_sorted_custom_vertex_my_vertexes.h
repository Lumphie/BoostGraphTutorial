#ifndef GET_SORTED_CUSTOM_VERTEX_MY_VERTEXES_H
#define GET_SORTED_CUSTOM_VERTEX_MY_VERTEXES_H

#include "get_custom_vertex_my_vertexes.h"

#include <vector>
//#include <boost/graph/graph_traits.hpp>
//#include <boost/graph/properties.hpp>
//#include "install_vertex_custom_type.h"
//#include "my_custom_vertex.h"

///Collect all the my_custom_vertex objects from a graph
///stored as a custom property of a vertex and
///sort these before returning
//TODO: generalize to return any type
template <typename graph>
std::vector<my_custom_vertex> get_sorted_custom_vertex_my_vertexes(const graph& g) noexcept
{
  auto v = get_custom_vertex_my_vertexes(g);

  const auto my_custom_vertex_comparer
    = [](const my_custom_vertex& lhs,const my_custom_vertex& rhs)
        {
          if (lhs.get_name() < rhs.get_name()) return true;
          if (lhs.get_name() > rhs.get_name()) return false;
          if (lhs.get_description() < rhs.get_description()) return true;
          if (lhs.get_description() > rhs.get_description()) return false;
          if (lhs.get_x() < rhs.get_x()) return true;
          if (lhs.get_x() > rhs.get_x()) return false;
          return lhs.get_y() < rhs.get_y();
        }
  ;
  std::sort(std::begin(v),std::end(v), my_custom_vertex_comparer);
  return v;
}

#endif // GET_SORTED_CUSTOM_VERTEX_MY_VERTEXES_H
