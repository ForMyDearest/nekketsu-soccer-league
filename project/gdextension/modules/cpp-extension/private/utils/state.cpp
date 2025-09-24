#include <cpp-extension/utils/state.hpp>

////////////////////////////////////////////////////////////

bool State::check() const {
	if (!GDVIRTUAL_IS_OVERRIDDEN(check)) {
		return true;
	}
	else {
		bool result;
		GDVIRTUAL_CALL(check, result);
		return result;
	}
}

void State::enter() {
	if (GDVIRTUAL_IS_OVERRIDDEN(enter)) {
		GDVIRTUAL_CALL(enter);
	}
}

void State::exit() {
	if (GDVIRTUAL_IS_OVERRIDDEN(exit)) {
		GDVIRTUAL_CALL(exit);
	}
}

void State::update(double delta) {
	if (GDVIRTUAL_IS_OVERRIDDEN(update)) {
		GDVIRTUAL_CALL(update, delta);
	}
}

void State::on_animation_complete() {
	if (GDVIRTUAL_IS_OVERRIDDEN(on_animation_complete)) {
		GDVIRTUAL_CALL(on_animation_complete);
	}
}

////////////////////////////////////////////////////////////

void State::_bind_methods() {
	GDVIRTUAL_BIND(init, "entity")
	GDVIRTUAL_BIND(check)
	GDVIRTUAL_BIND(enter)
	GDVIRTUAL_BIND(exit)
	GDVIRTUAL_BIND(update, "delta")
	GDVIRTUAL_BIND(get_state_code)
	GDVIRTUAL_BIND(on_animation_complete)
}
