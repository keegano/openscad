#ifndef IMPORTNODE_H_
#define IMPORTNODE_H_

#include "node.h"
#include "visitor.h"
#include "value.h"

enum import_type_e {
	TYPE_UNKNOWN,
	TYPE_STL,
	TYPE_OFF,
	TYPE_DXF
};

class ImportNode : public LeafNode
{
public:
	ImportNode(const ModuleInstantiation *mi, import_type_e type) : LeafNode(mi), type(type) { }
  virtual Response accept(class State &state, Visitor &visitor) const {
		return visitor.visit(state, *this);
	}
	virtual std::string toString() const;
	virtual std::string name() const;

	import_type_e type;
	Filename filename;
	std::string layername;
	int convexity;
	double fn, fs, fa;
	double origin_x, origin_y, scale;
	virtual Geometry *evaluate_geometry(class PolySetEvaluator *) const { return createGeometry(); }
	virtual Geometry *createGeometry() const;
};

#endif
