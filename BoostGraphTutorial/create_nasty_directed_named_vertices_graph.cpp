#include "create_nasty_directed_named_vertices_graph.h"



#include "add_named_vertex.h"
#include "create_empty_directed_named_vertices_graph.h"
#include "save_named_vertices_graph_to_dot.h"
#include "load_directed_named_vertices_graph_from_dot.h"
#include "get_sorted_named_vertex_my_vertexes.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::property<boost::vertex_name_t,std::string>
>
create_nasty_directed_named_vertices_graph() noexcept
{
  auto g = create_empty_directed_named_vertices_graph();
  for (int i=0; i!=2; ++i) //Duplicate labels
  {
    //Normal
    add_named_vertex("A", g);
    //Spaces
    add_named_vertex("A B", g);
    //Spaces in end and front
    add_named_vertex(" A B", g);
    add_named_vertex("A B ", g);
    //Underscores
    add_named_vertex(" _A_B _ ", g);
    //Backslash
    add_named_vertex(" \\\\A\\B\\ ", g);
    //Quotes
    add_named_vertex(" \"A\"B\"\" ", g);
    //Commas
    add_named_vertex(" A,B,, ", g);
    //Long name
    add_named_vertex(std::string(999,'A') + std::string(999,'B'), g);
    //Escape sequence
    add_named_vertex("A\"];", g);
  }
  return g;
}


