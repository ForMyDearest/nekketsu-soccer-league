#include <cpp-extension/utils/state_machine.hpp>

////////////////////////////////////////////////////////////

void StateMachine::init(Object* entity, int64_t states_count) {
	states.resize(states_count);
	for (auto&& state_variant: get_children()) {
		State* state = cast_to<State>(state_variant);
		state->init(entity);
		states.set(state->get_state_code(), state);
	}
	current_state->enter();
}

bool StateMachine::change_state(int state_code) {
	State* new_state = cast_to<State>(states.get(state_code));
	if (!new_state->check()) return false;
	current_state->exit();
	current_state = new_state;
	current_state->enter();
	return true;
}

////////////////////////////////////////////////////////////

void StateMachine::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_state", "value"), &__set_state);
	ClassDB::bind_method(D_METHOD("get_state"), &__get_state);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "state", PROPERTY_HINT_NODE_TYPE), "set_state", "get_state");

	ClassDB::bind_method(D_METHOD("init", "entity", "states_count"), &init);
	ClassDB::bind_method(D_METHOD("change_state", "state_code"), &change_state);
}

////////////////////////////////////////////////////////////

void StateMachine::__set_state(State* state) {
	current_state = state;
}

State* StateMachine::__get_state() const {
	return current_state;
}
