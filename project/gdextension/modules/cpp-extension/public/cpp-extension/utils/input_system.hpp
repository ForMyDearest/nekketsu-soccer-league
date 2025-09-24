#pragma once

#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/classes/object.hpp>

using namespace godot;

class InputSystem : public Object {
	GDCLASS(InputSystem, Object)

public:
	enum Action {
		ACTION_LEFT,
		ACTION_RIGHT,
		ACTION_UP,
		ACTION_DOWN,
		ACTION_PASS,
		ACTION_KICK
	};

	enum ControlScheme {
		CONTROL_SCHEME_P1,
		CONTROL_SCHEME_P2,
		CONTROL_SCHEME_CPU
	};

	static InputSystem* singleton;

	InputSystem();
	~InputSystem() override;
	Vector2 get_input_vector(ControlScheme scheme) const;
	bool is_action_just_pressed(ControlScheme scheme, Action action) const;
	bool is_action_just_released(ControlScheme scheme, Action action) const;

protected:
	static void _bind_methods();

private:
	Array actions;
};
