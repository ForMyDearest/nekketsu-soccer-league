#pragma once

#include "cpp-extension/utils/state.hpp"

#include <godot_cpp/variant/array.hpp>

using namespace godot;

class StateMachine : public Node {
	GDCLASS(StateMachine, Node)

public:
	void init(Object* entity, int64_t states_count);
	bool change_state(int state_code);

	State* current_state;

protected:
	static void _bind_methods();

private:
	void __set_state(State* value);
	State* __get_state() const;

	Array states;
};
