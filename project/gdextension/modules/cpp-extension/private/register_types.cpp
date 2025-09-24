#include <cpp-extension/utils/state.hpp>
#include <cpp-extension/utils/state_machine.hpp>
#include <cpp-extension/utils/input_system.hpp>

#include <godot_cpp/classes/engine.hpp>

using namespace godot;

void initialize_gdextension_types(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	GDREGISTER_ABSTRACT_CLASS(State)
	GDREGISTER_RUNTIME_CLASS(StateMachine)
	GDREGISTER_RUNTIME_CLASS(InputSystem)

	Engine::get_singleton()->register_singleton("InputSystem", memnew(InputSystem));
}

void uninitialize_gdextension_types(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	memdelete(InputSystem::singleton);
}

extern "C" GDExtensionBool GDE_EXPORT
cpp_extension_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization* r_initialization) {
	GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);
	init_obj.register_initializer(initialize_gdextension_types);
	init_obj.register_terminator(uninitialize_gdextension_types);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
