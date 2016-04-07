#include "clear_first_vertex_with_name.h"
#include "clear_first_vertex_with_name_demo.impl"

#include <boost/test/unit_test.hpp>

#include "create_named_vertices_k2_graph.h"

BOOST_AUTO_TEST_CASE(clear_first_vertex_with_name_on_named_vertices_k2_graph)
{
  auto g = create_named_vertices_k2_graph();
  BOOST_CHECK(boost::num_edges(g) == 1);
  clear_first_vertex_with_name("My computer",g);
  BOOST_CHECK(boost::num_edges(g) == 0);
}

BOOST_AUTO_TEST_CASE(clear_first_vertex_with_name_with_another_type)
{
  using another_graph = boost::adjacency_list<
    boost::vecS,
    boost::vecS,
    boost::undirectedS,
    boost::property<boost::vertex_name_t,std::string>
  >
  auto g = create_named_vertices_k2_graph();
  BOOST_CHECK(boost::num_edges(g) == 1);
  clear_first_vertex_with_name("My computer",g);
  BOOST_CHECK(boost::num_edges(g) == 0);
}
