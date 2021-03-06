#ifndef DELTACOLORING_WRITE_GRAPH_TO_DOT
#define DELTACOLORING_WRITE_GRAPH_TO_DOT

#include "color_writer.hpp"
#include "component_writer.hpp"
#include "graphinfo_writer.hpp"

#include <iostream>
#include <boost/graph/graphviz.hpp>

using std::ostream;

namespace dColoring {
	template<class Graph, class ColorMap, class ComponentMap>
	void write_graph_to_dot(
		const Graph& graph, const ColorMap& color, const ComponentMap& component, 
		ostream& out, const int num_col, const int num_comp, const int delta_g) {
		LOG1("new color_writer");
		color_writer<ColorMap> col_w(color, COLOR_WITH_COLORS);
		LOG1("new component_writer");
		component_writer<ComponentMap> comp_w(component);
		LOG1("new graphinfo_writer");
		graphinfo_writer ginfo_w(num_col, num_comp, delta_g);

		LOG1("calling write_graphviz");
		write_graphviz(out, graph, col_w, comp_w, ginfo_w);
	}
}

#endif //DELTACOLORING_WRITE_GRAPH_TO_DOT