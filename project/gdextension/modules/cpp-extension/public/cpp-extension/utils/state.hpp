#pragma once

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/gdvirtual.gen.inc>

using namespace godot;

class State : public Node {
	GDCLASS(State, Node)

public:
	virtual void init(Object* entity) = 0;
	virtual bool check() const;
	virtual void enter();
	virtual void exit();
	virtual void update(double delta);
	virtual int get_state_code() const = 0;
	virtual void on_animation_complete();

	GDVIRTUAL1_REQUIRED(init, Object*)
	GDVIRTUAL0RC(bool, check)
	GDVIRTUAL0(enter)
	GDVIRTUAL0(exit)
	GDVIRTUAL1(update, double)
	GDVIRTUAL0RC_REQUIRED(int, get_state_code)
	GDVIRTUAL0(on_animation_complete)

protected:
	static void _bind_methods();
};
