#include "create_named_vertices_markov_chain_graph.h"

#include "create_named_vertices_markov_chain_graph.impl"

#include "create_named_vertices_markov_chain_graph_demo.impl"

#include <cassert>
#include <iostream>
#include "get_n_edges.h"
#include "get_n_vertices.h"
#include "get_edges.h"
#include "get_vertices.h"
#include "get_edge_descriptors.h"
#include "get_vertex_descriptors.h"
#include "get_vertex_names.h"
#include "create_named_vertices_markov_chain_graph.h"

void create_named_vertices_markov_chain_graph_test() noexcept
{
  const auto g = create_named_vertices_markov_chain_graph();
  assert(boost::num_vertices(g) == 2);
  assert(boost::num_edges(g) == 4);
  assert(get_n_vertices(g) == 2);
  assert(get_n_edges(g) == 4);
  const auto vip = get_vertices(g);
  assert(vip.first != vip.second);
  const auto vds = get_vertex_descriptors(g);
  assert(vds.size() == 2);
  const auto eip = get_edges(g);
  assert(eip.first != eip.second);
  const auto eds = get_edge_descriptors(g);
  assert(eds.size() == 4);

  const std::vector<std::string> expected_names{"Sunny", "Rainy"};
  const std::vector<std::string> vertex_names = get_vertex_names(g);
  assert(expected_names == vertex_names);

  create_named_vertices_markov_chain_graph_demo();
  std::cout << __func__ << ": OK" << '\n';
}