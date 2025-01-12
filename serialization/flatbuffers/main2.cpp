#include "schema_generated.h"
#include<iostream>

void CreateMonster() {
	flatbuffers::FlatBufferBuilder builder;

	// Create Vec3 object
	auto vec = MyGame::CreateVec3(builder, 1.0f, 2.0f, 3.0f);

	// Create a Monster object
	auto name = builder.CreateString("Orc");
	auto monster = MyGame::CreateMonster(builder, vec, 150, 100, name);

	builder.Finish(monster);

	// Get the serialized data
	uint8_t* buf = builder.GetBufferPointer();
	int size = builder.GetSize();

	// buf can now be sent over network, written to file, etc.
}

int main()
{
	flatbuffers::FlatBufferBuilder builder;

	// Create Vec3 object
	auto vec = MyGame::CreateVec3(builder, 1.0f, 2.0f, 3.0f);

	// Create a Monster object
	auto name = builder.CreateString("Orc");
	auto monster = MyGame::CreateMonster(builder, vec, 150, 100, name);

	builder.Finish(monster);

	// Get the serialized data
	uint8_t* buf = builder.GetBufferPointer();
	int size = builder.GetSize();

	// buf can now be sent over network, written to file, etc.

	const MyGame::Monster* monster2 = MyGame::GetMonster(buf);

	std::cout << "Name: " << monster2->name()->c_str() << "\n";
	std::cout << "Mana: " << monster2->mana() << "\n";
	std::cout << "HP: " << monster2->hp() << "\n";
}
