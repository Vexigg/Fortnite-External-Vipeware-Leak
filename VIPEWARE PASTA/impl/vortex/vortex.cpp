#ifndef VORTEX_CPP
#define VORTEX_CPP

#include "../include.hpp"

auto vortex::communicate_t::send_cmd(
	void* data,
	requests code ) -> bool
{
	if ( !data || !code )
		return false;

	IO_STATUS_BLOCK block;
	invoke_data request { 0 };

	request.unique = requests::invoke_unique;
	request.data = data;
	request.code = code;

	auto result =
		direct_device_control(
		this->m_handle, 
		nullptr, 
		nullptr,
		nullptr, 
		&block, 
		0,
		&request,
		sizeof( request ), 
		&request, 
		sizeof( request ) );

	return result;
}

auto vortex::communicate_t::initialize_handle( ) -> bool
{
	this->m_handle = CreateFileA( DEVICE, GENERIC_READ, 0, 0, 3, 0x00000080, 0 );
	if ( this->m_handle != INVALID_HANDLE_VALUE )
	{
		this->m_pid = GetCurrentProcessId( );
		return true;
	}

	return false;
}

auto vortex::communicate_t::attach(
	int a_pid ) -> bool
{
	if ( !a_pid )
		return false;

	this->m_pid = a_pid;

	return true;
}

auto vortex::communicate_t::get_image_base(
	const char* module_name ) -> const std::uintptr_t
{
	base_invoke data { 0 };
	
	data.pid = this->m_pid;
	data.handle = 0;
	data.name = module_name;

	this->send_cmd(
		&data,
		invoke_base );

	this->image_base = 
		data.handle;
	
	return data.handle;
}

auto vortex::communicate_t::get_guarded_pool( 
	) -> std::uintptr_t
{
	region_invoke data { 0 };

	data.address = 0;
	
	this->send_cmd(
			&data,
			invoke_region );

	return data.address;
}

auto vortex::communicate_t::is_guarded( 
	std::uintptr_t Address ) -> bool
{
	static uintptr_t filter = 0xFFFFFFFF00000000;
	uintptr_t result = Address & filter;

	return bool( result == 0x8000000000 || result == 0x10000000000 );
}

auto vortex::communicate_t::fix_address( 
	std::uintptr_t Address ) -> std::uintptr_t
{
	if ( this->is_guarded( uintptr_t( Address ) ) )
	{
		return Address & 0xFFFFFF;
	}

	return Address;
}

auto vortex::communicate_t::write_physical(
	const std::uintptr_t address, 
	void* buffer,
	const std::size_t size ) -> bool
{
	write_invoke data { 0 };

	data.pid = this->m_pid;
	data.address = address;
	data.buffer = buffer;
	data.size = size;

	auto result = 
		this->send_cmd( 
			&data, 
			invoke_write );

	return result;
}

auto vortex::communicate_t::read_physical(
	const std::uintptr_t address, 
	void* buffer,
	const std::size_t size ) -> bool
{
	read_invoke data { 0 };

	data.pid = this->m_pid;
	data.address = address;
	data.buffer = buffer;
	data.size = size;

	auto result = 
		this->send_cmd( 
			&data, 
			invoke_read );
	
	return result;
}

#endif // ! VORTEX_CPP
