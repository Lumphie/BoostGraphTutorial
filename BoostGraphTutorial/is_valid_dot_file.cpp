#include "is_valid_dot_file.h"

#include "create_empty_directed_graph.h"
#include "create_empty_undirected_graph.h"
#include "create_k2_graph.h"
#include "copy_file.h"
#include "save_graph_to_dot.h"
#include "helper.h"
#include "is_regular_file.h"

#include "is_valid_dot_file.impl"

void is_valid_dot_file_test() noexcept
{
  //An empty undirected graph should be convertable to a valid .dot file
  {
    const auto g = create_empty_undirected_graph();
    const std::string filename{
      "is_valid_dot_file_test_create_empty_undirected_graph.dot"
    };
    save_graph_to_dot(g,filename);
    assert(is_valid_dot_file(filename));
  }
  //An empty directed graph should be convertable to a valid .dot file
  {
    const auto g = create_empty_directed_graph();
    const std::string filename{
      "is_valid_dot_file_test_create_empty_directed_graph.dot"
    };
    save_graph_to_dot(g,filename);
    assert(is_valid_dot_file(filename));
  }
  //A K2 graph should be convertable to a valid .dot file
  {
    const auto g = create_k2_graph();
    const std::string filename{
      "is_valid_dot_file_test_create_k2_graph.dot"
    };
    save_graph_to_dot(g,filename);
    assert(is_valid_dot_file(filename));
  }
  std::cout << __func__ << ": OK" << '\n';
}