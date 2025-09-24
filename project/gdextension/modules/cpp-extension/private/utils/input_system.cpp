#include <cpp-extension/utils/input_system.hpp>

#include <godot_cpp/classes/input.hpp>

////////////////////////////////////////////////////////////

VARIANT_ENUM_CAST(InputSystem::Action);

VARIANT_ENUM_CAST(InputSystem::ControlScheme);

InputSystem* InputSystem::singleton = nullptr;

InputSystem::InputSystem() {
	singleton = this;

	actions.resize(CONTROL_SCHEME_CPU);

	actions[CONTROL_SCHEME_P1].set(ACTION_LEFT, "p1_left");
	actions[CONTROL_SCHEME_P1].set(ACTION_RIGHT, "p1_right");
	actions[CONTROL_SCHEME_P1].set(ACTION_UP, "p1_up");
	actions[CONTROL_SCHEME_P1].set(ACTION_DOWN, "p1_down");
	actions[CONTROL_SCHEME_P1].set(ACTION_PASS, "p1_pass");
	actions[CONTROL_SCHEME_P1].set(ACTION_KICK, "p1_kick");

	actions[CONTROL_SCHEME_P2].set(ACTION_LEFT, "p2_left");
	actions[CONTROL_SCHEME_P2].set(ACTION_RIGHT, "p2_right");
	actions[CONTROL_SCHEME_P2].set(ACTION_UP, "p2_up");
	actions[CONTROL_SCHEME_P2].set(ACTION_DOWN, "p2_down");
	actions[CONTROL_SCHEME_P2].set(ACTION_PASS, "p2_pass");
	actions[CONTROL_SCHEME_P2].set(ACTION_KICK, "p2_kick");
}

InputSystem::~InputSystem() {
	singleton = nullptr;
}

Vector2 InputSystem::get_input_vector(ControlScheme scheme) const {
	auto&& mapping = actions[scheme];
	return Input::get_singleton()->get_vector(
		mapping.get(ACTION_LEFT),
		mapping.get(ACTION_RIGHT),
		mapping.get(ACTION_UP),
		mapping.get(ACTION_DOWN)
	);
}

bool InputSystem::is_action_just_pressed(ControlScheme scheme, Action action) const {
	return Input::get_singleton()->is_action_just_pressed(actions[scheme].get(action));
}

bool InputSystem::is_action_just_released(ControlScheme scheme, Action action) const {
	return Input::get_singleton()->is_action_just_released(actions[scheme].get(action));
}

////////////////////////////////////////////////////////////

void InputSystem::_bind_methods() {
	BIND_ENUM_CONSTANT(ACTION_LEFT)
	BIND_ENUM_CONSTANT(ACTION_RIGHT)
	BIND_ENUM_CONSTANT(ACTION_UP)
	BIND_ENUM_CONSTANT(ACTION_DOWN)
	BIND_ENUM_CONSTANT(ACTION_PASS)
	BIND_ENUM_CONSTANT(ACTION_KICK)

	BIND_ENUM_CONSTANT(CONTROL_SCHEME_P1)
	BIND_ENUM_CONSTANT(CONTROL_SCHEME_P2)
	BIND_ENUM_CONSTANT(CONTROL_SCHEME_CPU)

	ClassDB::bind_method(D_METHOD("get_input_vector", "controller"), &get_input_vector);
	ClassDB::bind_method(D_METHOD("is_action_just_pressed", "controller", "action"), &is_action_just_pressed);
	ClassDB::bind_method(D_METHOD("is_action_just_released", "controller", "action"), &is_action_just_released);
}
