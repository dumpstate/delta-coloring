#ifndef DELTACOLORING_DELTA_G
#define DELTACOLORING_DELTA_G

#include <boost/foreach.hpp>
#include <boost/graph/graph_traits.hpp>

namespace dColoring {
	template<typename VertexListGraph>
	int delta_g(const VertexListGraph& graph) {
		typedef graph_traits<VertexListGraph> Graph;
		typedef typename Graph::vertex_descriptor	Vertex;

		int max_degree = 0;
		BOOST_FOREACH(Vertex v, vertices(graph)) {
			int degr = degree(v, graph);
			LOG4("vertex v =", v, " degree =", degr);
			if(degr > max_degree)
				max_degree = degr;
		}
		LOG2("max degree: ", max_degree);
		return max_degree;
	}
}

#endif //DELTACOLORING_DELTA_G